//
//  tester.cpp
//  matrix
//  @author Justin Kord
//  Student number 0360764
//  Created by Justin on 2018-09-28.
//  Copyright © 2018 Justin. All rights reserved.
//

#include <stdio.h>
#include "matrix.h"
#include <iostream>
using namespace std;
typedef std::vector<int> Row;
typedef std::vector<Row> Mat;

int main()
{
    //Testing contructor to show all values set to 0
    cout << "Constructor created m1 with" << endl;
    Matrix m1(2,2);
    m1.displayData();
    //Now setting all val to 12 to test other functions
    m1.setData(0, 0, 12);
    m1.setData(0, 1, 12);
    m1.setData(1, 0, 12);
    m1.setData(1, 1, 12);
    
    cout << "Matrix m1 has" << endl;
    //Testing getNumRows and getNumColumns methods
    cout << "Num rows: " << m1.getNumRows() << " Num cols: " << m1.getNumColumns() <<endl;
    
    //Setting all values of m2 to 6
    Matrix m2(2, 2);
    m2.setData(0, 0, 6);
    m2.setData(0, 1, 6);
    m2.setData(1, 0, 6);
    m2.setData(1, 1, 6);
    
    cout << "Matrix m1" << endl;
    m1.displayData();
    
    cout << "Matrix m2" << endl;
    m2.displayData();
    
    cout << "Testing overloaded Assignment operator to deep copy m2" << endl;
    Matrix m3 = m2;
    m3.displayData();
    
    //Testing the overloaded + for matrices
    Matrix s = m1 + m2;
    cout << "Matrix sum of m1 and m2 " << endl;
    s.displayData();
    
    //Testing operators for addition and subtraction by scalar
    Matrix w = s += 10;
    cout << "Matrix + scalar 10" << endl;
    cout << w;
    w -= 15;
    cout << "Matrix - scalar 15" << endl;
    cout << w;
    
    //Testing operator for subtracting matrices
    cout << "Subtracting Matrix m2 from the current matrix" << endl;
    Matrix n = w - m2;
    cout << n;
    
    //Testing overloaded / by scalar
    m1 /= 2;
    Matrix c = m1;
    cout << "Matrix m1 / scalar 2" << endl;
    c.displayData();
    m1.setData(0, 0, 12);
    m1.setData(0, 1, 12);
    m1.setData(1, 0, 12);
    m1.setData(1, 1, 12);
    
    //Testing the overloaded / for matrices
    cout << "Matrix m1 / Matrix m2" << endl;
    Matrix m = m1 / m2;
    m.displayData();
    Matrix d = m1 *= 2;
    cout << "Testing m1 * scalar 2" << endl;
    cout << d;
    
    cout << "Testing m1 * m2" << endl;
    Matrix e = m1 * m2;
    cout << e;
    
    //Testing overloaded ostream which prints the rows
    cout << "Matrix printed with ostream operator" << endl;
    cout << m;
    cout << "So total would be 8 with 4 elements" << endl;
    
    //Testing the Automatic type conversion from Matrix to doublw which give the average
    double t;
    cout << "Therefore the avg is" << endl;
    t = m;
    cout << endl;
    cout << "Testing the istream operator, enter values for matrix" << endl;
    cin >> m1;
    cout << "The matrix created is" << endl;
    cout << m1 << endl;
    cout << "Setting first row to 0s" << endl;
    vector<double> v(2);
    m1.setRow(v, 0);
    cout << m1;
    cout << "Getting second row" << endl;
    vector<double> vec(2);
    vec = m1.getrow(m1, 1);
    m1.print(vec);
    cout << endl;
    cout << "Setting first col to 1s" << endl;
    vector<double> v2(2);
    v2[0] = 1; v2[1] = 1;
    m1.setCol(v2, 0);
    cout << m1;
    cout << "Getting second col" << endl;
    vector<double> vec2(2);
    vec2 = m1.getCol(1, m1);
    m1.print(vec2);
    cout << endl;
    cout << "Testing [] operator to get first row" << endl;
    m1[0];
    
}
