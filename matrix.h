#ifndef MATRIX_H_
#define MATRIX_H_
#include <iostream>
#include <iomanip>
using namespace std;
class D2_Array
{
private:
    int rows;
    int columns;
    int **mat;

public:
    D2_Array();
    ~D2_Array();
    D2_Array(int rows, int columns);
    void printArray();
    void setArray();
    void Triple();
    int minimum();
    int max();
};  
#endif