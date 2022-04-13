#pragma once

#include<string>
#include<iostream>
#include<vector>
#include <stdexcept>
using namespace std;

namespace zich
{
    class Matrix
    { 
    public:
        int row;
        int col;
        vector<double> data;
         Matrix(const vector<double> &data, const int row, const int col);
        //compare function
        //bool operator==(Matrix &mat);
        bool operator!=(Matrix &mat) const;
        bool operator<=(Matrix &mat);
        bool operator<(Matrix &mat);
        bool operator>(Matrix &mat);
        bool operator>=(Matrix &mat);
        friend bool operator==(Matrix const &mat1,Matrix const &mat2);

        //plus, minus function
        Matrix& operator+=(const Matrix &mat);
        Matrix &operator-=(const Matrix &mat);

        Matrix &operator++();         // prefix  - ++a
        Matrix operator++(int); // postfix - a++

        Matrix &operator--();         // prefix  - --a
        Matrix operator--(int); // postfix - a--

            //plus, minus function
        Matrix operator+(Matrix &mat);
        Matrix operator-(Matrix &mat);
            //unary function
        friend Matrix operator+(Matrix &mat);
        friend Matrix operator-(Matrix &mat);

            //mul with double num function
        Matrix operator*(const Matrix &mat);
        Matrix& operator*=(const Matrix &mat);
        friend Matrix operator*(const double a, Matrix &mat);

        Matrix operator*(const double a);
        Matrix& operator*=(const double a);
        double multiplication(const Matrix &mat, const int tempRow, const int tempCol);
        double mat_sum();
            //input, output
        friend std::ostream &operator<<(std::ostream &out, const Matrix &mat);
        friend std::istream& operator>>(std::istream &input, Matrix &mat);
    };
    
}