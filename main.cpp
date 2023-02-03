#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib>
#include <conio.h>
#include <cmath>
#include <fstream>
using namespace std;
#include "matrix.cpp"
int main()
{
    int rows = 0, columns = 0;
    while (rows <= 0)
    {
        cout << "Enter the number of rows : ";
        cin >> rows;
    }
    while (columns <= 0)
    {
        cout << "Enter the number of columns : ";
        cin >> columns;
    }
    D2_Array A(rows, columns);
    A.setArray();
    A.printArray();
    A.Triple();
    return 0;
}