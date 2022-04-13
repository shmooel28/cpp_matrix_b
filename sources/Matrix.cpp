#include<string>
#include<iostream>
#include<vector>
#include <stdexcept>
#include"Matrix.hpp"

using namespace std;

namespace zich
{
    Matrix:: Matrix(const vector<double> &data, const int row, const int col)
    {
        if (row < 0 || col < 0)
        {
            throw runtime_error("must be big than zero");
        }
        if(data.size() != row*col )
        {
            throw runtime_error("the vector must be the size of row*col");
        }
        this->data = data;
        this->row = row;
        this->col = col;
    }

    Matrix Matrix::operator+(Matrix &mat)
    {
        if(this->col != mat.col || this->row != mat.row)
        {
            throw runtime_error("must be equal row and col");
        }
        vector<double> temp;
        temp.resize((unsigned int)(row * col));
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                temp[(unsigned int)(i * col + j)] = this->data[(unsigned int)(i * col + j)] + mat.data[(unsigned int)(i * col + j)];
            }
        }
        return Matrix(temp, this->row, mat.col);
    }
    Matrix &Matrix::operator++()
    {
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                this->data[(unsigned int)(i * col + j)] += 1;
            }
        }
        return *this;
    }
    Matrix Matrix::operator++(const int num)
    {
        vector<double> temp(this->data.begin(),this->data.end());
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                this->data[(unsigned int)(i * col + j)] += 1;
            }     
        }
        return Matrix(temp,this->row,this->col);
    }
    Matrix &Matrix::operator+=(const Matrix &mat)
    {
        if(this->col != mat.col || this->row != mat.row)
        {
            throw runtime_error("must be equal size mat");
        }
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                this->data[(unsigned int)(i * col + j)] += mat.data[(unsigned int)(i * col + j)];
            }    
        }
        return *this;
    }
    Matrix operator+(Matrix &mat)
    {
        vector<double> temp;
        temp.resize((unsigned int)(mat.row * mat.col));
        for (int i = 0; i < mat.row; i++)
        {
            for (int j = 0; j < mat.col; j++)
            {
                temp[(unsigned int)(i * mat.col + j)] = mat.data[(unsigned int)(i * mat.col + j)];
            }
        }
        return Matrix(temp, mat.row, mat.col);
    }
    Matrix Matrix::operator-(Matrix &mat)
    {
        if(this->col != mat.col || this->row != mat.row)
        {
            throw runtime_error("must be equal size mat");
        }
        vector<double> temp;
        temp.resize((unsigned int)(row * col));
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                temp[(unsigned int)(i * col + j)] = this->data[(unsigned int)(i * col + j)] - mat.data[(unsigned int)(i * col + j)];
            }
        }
        return Matrix(temp, this->row, mat.col);
    }
    Matrix &Matrix::operator--()
    {
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                this->data[(unsigned int)(i * col + j)] -= 1;
            }
            
        }
        return *this;
    }
    Matrix Matrix::operator--(const int num)
    {
        vector<double> temp(this->data.begin(),this->data.end());
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                this->data[(unsigned int)(i * col + j)] -= 1;
            }     
        }
        return Matrix(temp,this->row,this->col);
    }
    Matrix &Matrix::operator-=(const Matrix &mat)
    {
        if(this->col != mat.col || this->row != mat.row)
        {
            throw runtime_error("must be equal size mat");
        }
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                this->data[(unsigned int)(i * col + j)] -= mat.data[(unsigned int)(i * col + j)];
            }   
        }
        return *this;
    }
    Matrix operator-(Matrix &mat)
    {
        return mat*(-1);
    }
    double Matrix::multiplication(const Matrix &mat, const int tempRow, const int tempCol)
    {
        double sum = 0;
        for (int i = 0; i < this->col; i++)
        {
            sum += this->data[(unsigned int)(this->col * tempRow + i)] * mat.data[(unsigned int)(mat.col * i + tempCol)];
        }
        return sum;
    }
    Matrix Matrix::operator*(const Matrix &mat)
    {
        if (this->col != mat.row)
        {
            throw runtime_error("the col of the first mat and the row of the seconde must be the same");
        }
        vector<double> temp;
        int len = row *mat.col;
        temp.resize((unsigned int)len);
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < mat.col; j++)
            {
                temp[(unsigned int)(i * mat.col + j)] = multiplication(mat, i, j);
            }
        }
        return Matrix(temp, row, mat.col);;
    }
    Matrix &Matrix::operator*=(const Matrix &mat)
    {
        if (this->col != mat.row)
        {
            throw runtime_error("the cols of the first and row of the seconde must be equal");
        }
        vector<double> temp;
        temp.resize((unsigned int)(this->row * mat.col));
        for (int i = 0; i < this->row; i++)
        {
            for (int j = 0; j < mat.col; j++)
            {
                temp[(unsigned int)(i * mat.col + j)] = multiplication(mat, i, j);
            }
        }
        this->col = mat.col;
        this->data = temp;
        return *this;
    }
    Matrix operator*(const double a, Matrix &mat){
        vector<double> temp_data;
        temp_data.resize((unsigned int)(mat.row * mat.col));
        for (int i = 0; i < mat.row; i++)
        {
            for (int j = 0; j < mat.col; j++)
            {
                temp_data[(unsigned int)(i * mat.col + j)] = a * mat.data[(unsigned int)(i * mat.col + j)];
            }
        }
        return Matrix(temp_data, mat.row, mat.col);;
    }
    Matrix Matrix::operator*(const double a)
    {
        vector<double> temp(this->data.begin(),this->data.end());
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                temp[(unsigned int)(i * col + j)] *= a;
            }
            
        }
        return Matrix(temp,this->row,this->col);
    }
    Matrix &Matrix::operator*=(const double a)
    {
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                this->data[(unsigned int)(i * col + j)] *= a;
            }
        }
        return *this;
    }
    double Matrix::mat_sum()
    {
        double count = 0;
        for (int i = 0; i < this->row; i++)
        {
            for (int j = 0; j < this->col; j++)
            {
                count += this->data[(unsigned int)(i * col + j)];
            }
        }
        return count;
    }
    bool Matrix::operator>(Matrix &mat)
    {
        if (this->col != mat.col || this->row != mat.row)
        {
            throw runtime_error("must be sasme size");
        }
        return this->mat_sum() > mat.mat_sum();
    }
    bool Matrix::operator>=(Matrix &mat)
    {
        if (this->col != mat.col || this->row != mat.row)
        {
            throw runtime_error("must be sasme size");
        }
        return this->mat_sum() >= mat.mat_sum();
    }
    bool Matrix::operator<(Matrix &mat)
    {
        if (this->col != mat.col || this->row != mat.row)
        {
            throw runtime_error("must be sasme size");
        }
        return this->mat_sum() < mat.mat_sum();
    }
    bool Matrix::operator<=(Matrix &mat)
    {
        if (this->col != mat.col || this->row != mat.row)
        {
            throw runtime_error("must be sasme size");
        }
        return this->mat_sum() <= mat.mat_sum();
    }
    bool operator ==(Matrix const &mat1,Matrix const &mat2)
    {
        if (mat1.row != mat2.row || mat1.col != mat2.col)
        {
            throw runtime_error("row and cols must be equals");
        }
        for (int i = 0; i < mat1.row; i++)
        {
            for (int j = 0; j < mat1.col; j++)
            {
                if (mat1.data[(unsigned int)(i * mat1.col + j)] != mat2.data[(unsigned int)(i * mat2.col + j)])
                {
                    return false;
                }
            }
        }
        return true;
    }
    bool Matrix::operator!=(Matrix &mat) const
    {
        bool flag = true;
        if (*this == mat)
        {
            flag = false;
        }
        return flag;
    }
    ostream & operator << (ostream &out, const Matrix &mat){
        for (int i = 0; i < mat.row; i++)
        {
            out << '[';
            for (int j = 0; j < mat.col; j++)
            {
                if (j != mat.col - 1)
                {
                    out << mat.data[(unsigned int)(i * mat.col + j)] << ' ';
                }
                else
                {
                    out << mat.data[(unsigned int)(i * mat.col + j)];
                }
            }
            if (i != mat.row - 1)
            {
                out << ']' << '\n';
            }
            else
            {
                out << ']';
            }
        }
        return out;
    }
    istream &operator>>(istream &input, Matrix &mat)
    {
        int row = 0;
        int col = 0;
        int number = 0;
        string value;
        getline(input, value);
        unsigned int len = value.length();
        if (value[0] != '[' || value[len - 1] != ']')
        {
            throw runtime_error("invalid input");
        }
        for (size_t i = 0; i < len; i++)
        {
            if(value[i] > '0' && value[i] < '9')
            {
                number++;
            }
            if( (value[i] < '0' && value[i] > '9') && value[i] != '[' && value[i] != ']' && value[i] != ',' && value[i] != '.')
            {
                throw runtime_error("invalid input");
            }
            if(value[i] == '[' && (value[i] < '0' && value[i] > '9'))
            {
                throw runtime_error("invalid input");
            }
            if (value[i] == '[')            
            {
                row++;
                continue;
            }
            if (value[i] == ']' && (unsigned int)(i) +1 >= len)
            {
                continue;
            }
            if (value[i] == ']' && i+2 < len)
            {
                if(value[i+1] != ',' || value[i+2] != ' ' || value[i+3]!= '[')
                {
                    throw runtime_error("invalid input");
                }
            }
            if(value[i] ==',' && value[i-1]!=']')
            {
                throw runtime_error("invalid input");   
            }
        }
        char s = '9';
        vector<double> data;
        data.resize((unsigned int) number);
        unsigned int count = 0;
        for (size_t i = 0; i < len; i++)
        {
            if(value[i] > '0' && value[i] < '9')
            {
                data[count] = double(value[i]);
                count++;
            }
        }
        for (size_t i = 0; value[i] ==']' ; i++)
        {
            col++;
        }
        mat.data = data;
        mat.row = row;
        mat.col = col;
        return input;
    }
}