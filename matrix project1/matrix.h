//
//  matrix.h
//  matrix
//  @author Justin Kord
//  Student number 0360764
//  Created by Justin on 2018-09-28.
//  Copyright © 2018 Justin. All rights reserved.
//

#ifndef matrix_h
#define matrix_h

#include <iostream>
#include <vector>
#include <iostream>

using namespace std;

class Matrix {
    
private:
    // save data row
    unsigned int row;
    // save data col
    unsigned int col;
    // utility function, Set row and col value
    void setUp(int, int);
    
public:
    // A two-dimensional double matrix
    double ** data;
    
    //overloaded index which gives access to a row
    void operator [] (int index) {
        for(int i =0; i<row; i++){
            cout << data[index][i];
        }
    }
    //const of overloaded index which gives access to a row
    const double* operator [] (int index) const {
        return data[index];
    }
    // default constructor, No argument passed, set it to 2*2 double data matrix with all values been 0
    Matrix();
    
    // constructor, set matrix size
    Matrix(int, int);
    
    // copy constructor
    Matrix(const Matrix &);
    
    // destructor, clean up data
    ~Matrix();
    
    //assignment operator
    Matrix operator = (const Matrix &m);
    
    //set each position (r,c)its with a data value
    void setData(int, int, double);
    
    //setRow and setCol which sets the contents of the row/column respectively
    void setRow(vector<double> v, int r);
    void setCol(vector<double> v, int c);
    
    //get the number of rows and columns respectively
    int getNumRows() const;
    int getNumColumns() const;
    
    // Get value inserted in position (r,c) of matrix
    double getData(int, int) const;
    
    void input();
    
    //getRow and getColumn which take in an index and return the specified row/column
    vector<double> getrow(Matrix x, int row);
    vector<double> getCol(int col,Matrix x);
    
    
    void print(vector<double> v);
    
    //Overlaoded operators for multiplication, division, addition, and subtraction of matrices
    // and for a matrix and scalar
    Matrix& operator+=(const Matrix&);
    Matrix& operator-=(const Matrix&);
    Matrix& operator*=(const Matrix&);
    Matrix operator*(const Matrix& B);
    Matrix operator / (const Matrix &m) const;
    Matrix& operator*=(double);
    Matrix& operator/=(double);
    Matrix& operator+=(const double num);
    Matrix& operator-=(const double num);
    operator double();
    void operator = (Matrix &a);
    
    int index(int length, int width)const;
    
    // Overloaded ostream operator, which prints out the matrix in a row-wise manner.
    friend std::ostream& operator<<(std::ostream&, const Matrix&);
    // Overloaded istream operator, which reads the matrix
    friend std::istream& operator>>(std::istream&, Matrix&);
    
    // Print matrix data for testing
    void displayData() {
        
        for (int i = 0;i<row; i++) {
            
            for (int j = 0;j<col; j++) {
                
                cout<<data[i][j]<<"\t";
                
            }
            
            cout<<""<<endl;
            
        }
        
    }
    
};

//Overlaoded operators for multiplication, division, addition, and subtraction of matrices
// and for a matrix and scalar
Matrix operator+(const Matrix&, const Matrix&);
Matrix operator-(const Matrix&, const Matrix&);
Matrix operator*(const Matrix&, const Matrix&);
Matrix operator*(const Matrix&, double);
Matrix operator*(double, const Matrix&);
Matrix operator/(const Matrix&, double);

#endif /* matrix_h */
