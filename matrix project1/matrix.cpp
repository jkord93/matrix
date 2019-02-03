//
//  matrix.cpp
//  matrix
//  @author Justin Kord
//  Student number 0360764
//  Created by Justin on 2018-09-28.
//  Copyright © 2018 Justin. All rights reserved.
//
#include "matrix.h"
#include <iostream>

//using namespace std;

// default constructor, No argument passed, set it to 2*2 double data matrix with all values been 0

Matrix::Matrix()
{
    setUp(2, 2);
}

// constructor, set matrix size

Matrix::Matrix(int r, int c)
{
    setUp(r, c);
}

// copy constructor

Matrix::Matrix(const Matrix &m)
{
    setUp(m.row, m.col);
    for(int i = 0; i < row; i++)
        for(int j = 0; j < col; j++)
            data[i][j] = m.data[i][j];
    
}

// destructor, clean up data

Matrix::~Matrix()
{
    for(int i = 0; i < row; i++)
        delete[] data[i];
    delete[] data;
}

//assignment operator
Matrix Matrix::operator = (const Matrix &m)
{
    if(this != &m) //avoid self assignment
    {
        //deallocate existing memory
        for(int i = 0; i < row; i++)
            delete[] data[i];
        delete[] data;
        //copy the data
        setUp(m.row, m.col);
        for(int i = 0; i < row; i++)
            for(int j = 0; j < col; j++)
                data[i][j] = m.data[i][j];
    }
    return *this;
}

// set each position (r,c)its with a data value
void Matrix::setData(int r , int c, double val)
{
    data[r][c] = val;
}

// return private member: row
int Matrix::getNumRows() const
{
    return row;
}

// return private member: col
int Matrix::getNumColumns() const
{
    return col;
}

// Get value inserted in position (r,c) of matrix
double Matrix::getData(int r , int c) const
{
    return data[r][c];
}

// utility function, Set row and col value
void Matrix::setUp(int r, int c)
{
    row = r;
    col = c;
    data = new double*[row];
    for(int i = 0; i < row; i++)
        data[i] = new double[col];
    
    for(int i = 0; i < row; i++)
        for(int j = 0; j < col; j++)
            data[i][j] = 0;
}

// utility function, Set row and col value
void Matrix::setRow(vector<double> v, int r)
{
    for(int i = 0; i < col; i++)
        data[r][i] = v[i];
}

// utility function, Set row and col value
void Matrix::setCol(vector<double> v, int c)
{
    for(int i = 0; i < col; i++)
        data[i][c] = v[i];
}

void Matrix :: input()
{
    cout<<"Enter matrix elements:\n";
    for(int i = 0; i < row; i++)
    {
        for(int j = 0; j < col; j++)
        {
            cin >> data[i][j];
        }
    }
}

vector<double> Matrix:: getrow(Matrix x, int row){
    // allocate
    std::vector<double> v (x.getNumColumns());
    for (int i = 0; i < x.getNumColumns(); i++) {
        v[i] = x.data[row][i];
    }
    return v;
}

//Get a column as a vector (an expensive operation)
vector<double> Matrix::getCol(int col,Matrix x)
{
    std::vector<double> v (x.getNumRows());
    for (int r=0;r<x.getNumRows();r++){
        v[r]=data[r][col];
        
    }
    return v;
}

void Matrix:: print(vector<double> v){
    for( int i = 0; i < v.size(); i++)
        cout << v[i];
}

//addition of matrices
Matrix& Matrix::operator+=(const Matrix& m)
{
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            data[i][j] += m.data[i][j];
        }
    }
    return *this;
}

//addition of matrix and scalar
Matrix& Matrix::operator+=(const double num)
{
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            data[i][j] += num;
        }
    }
    return *this;
}

//subtraction of matrices
Matrix& Matrix::operator-=(const Matrix& m)
{
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            data[i][j] -= m.data[i][j];
        }
    }
    return *this;
}

//addition of matrix and scalar
Matrix& Matrix::operator-=(const double num)
{
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            data[i][j] -= num;
        }
    }
    return *this;
}

//multiplication of matrices
Matrix& Matrix::operator*=(const Matrix& m)
{
    Matrix temp(row, m.col);
    for (int i = 0; i < temp.row; ++i) {
        for (int j = 0; j < temp.col; ++j) {
            for (int k = 0; k < col; ++k) {
                temp.data[i][j] += (data[i][k] * m.data[k][j]);
            }
        }
    }
    return temp;
}

//multiplication of matrices
Matrix Matrix:: operator*(const Matrix& B) { // Return self * B
    
    Matrix C; C.setUp(B.getNumRows(), B.getNumColumns());
    for(int i=0; i<B.getNumRows(); i++)
        for(int j=0; j<B.getNumColumns(); j++)
            for(int k=0; k<B.getNumColumns(); k++)
                C.data[i][j] += data[i][k] * B.data[k][j];
    return C;
}

//multiplication of matrix and scalar
Matrix& Matrix::operator*=(double num)
{
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            data[i][j] *= num;
        }
    }
    return *this;
}

//division of matrix and scalar
Matrix& Matrix::operator/=(double num)
{
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            data[i][j] /= num;
        }
    }
    return *this;
}

//Automatic type conversion from Matrix to double
Matrix::operator double (){
    double sum = 0; int count=0; int x =0,y=0;
    for (x = 0; x < row -1 ; ++x){
        for (y = 0; y < col -1; ++y)
            count++;
        sum += data[x][y];
    }
    cout << sum/count;
    return 0;
    }
    
    //addition of matrices
    Matrix operator+(const Matrix& m1, const Matrix& m2)
    {
        Matrix temp = m1;
        return (temp += m2);
    }
    
    //subtraction of matrices
    Matrix operator-(const Matrix& m1, const Matrix& m2)
    {
        Matrix temp = m1;
        return (temp -= m2);
    }
    
    //multiplication of matrices
    Matrix operator*(const Matrix& m1, const Matrix& m2)
    {
        Matrix temp = m1;
        return (temp *= m2);
    }
    
    //multiplication of matrix and scalar
    Matrix operator*(const Matrix& m, double num)
    {
        Matrix temp = m;
        return (temp *= num);
    }
    
    //multiplication of matrix and scalar
    Matrix operator*(double num, const Matrix& m)
    {
        return (m * num);
    }
    
    //division of matrix and scalar
    Matrix operator/(const Matrix& m, double num)
    {
        Matrix temp = m;
        return (temp /= num);
    }
    
    //addition of matrix and scalar
    Matrix operator+(const Matrix& m, double num)
    {
        Matrix temp = m;
        return (temp += num);
    }
    
    //subtraction of matrix and scalar
    Matrix operator-(const Matrix& m, double num)
    {
        Matrix temp = m;
        return (temp -= num);
    }
    
    //division of matrices
    Matrix Matrix::operator / (const Matrix &m)const {
        if (col != m.col || row != m.row) {
            // throw exception("length / width mismatch");
        }
        
        Matrix mat(row, col);
        for (int l = 0; l < mat.getNumRows(); ++l) {
            for (int w = 0; w < mat.getNumColumns(); ++w) {
                mat.setData(l, w, getData(l, w) / m.getData(l, w));
            }
        }
        return mat;
    }
    
    int Matrix::index(int length, int width)const
    {
        if (length < 0 || width < 0 || length >= row || width >= col) {
            //throw exception("out of bounds");
        }
        return (length * col + width);
    }
    
    // Overloaded ostream operator, which prints out the matrix in a row-wise manner.
    ostream& operator<<(ostream& os, const Matrix& m)
    {
        for (int i = 0; i < m.row; ++i) {
            os << m.data[i][0];
            for (int j = 1; j < m.col; ++j) {
                os << " " << m.data[i][j];
            }
            os << endl;
        }
        return os;
    }
    // Overloaded istream operator, which reads the matrix
    istream& operator>>(istream& is, Matrix& m)
    {
        for (int i = 0; i < m.row; ++i) {
            for (int j = 0; j < m.col; ++j) {
                is >> m.data[i][j];
            }
        }
        return is;
    }
    
    //Overloaded assignment operator, which does a deep copy of the data
    void Matrix:: operator = (Matrix& m)
    {
        Matrix temp(m);
    }
