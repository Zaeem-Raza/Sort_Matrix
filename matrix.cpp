#include "matrix.h"
D2_Array ::D2_Array()
{
    rows = 0;
    columns = 0;
    mat = nullptr;
}

D2_Array ::D2_Array(int rows, int columns)
{
    this->rows = rows;
    this->columns = columns;
    mat = new int *[rows];
    for (int i = 0; i < rows; i++)
    {
        mat[i] = new int[columns];
    }
}
void D2_Array ::printArray()
{
    cout << "The matrix is :- " << endl;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            cout << setw(6) << mat[i][j];
        }
        cout << endl;
    }
}
void D2_Array ::setArray()
{
    cout << "Enter the elements of matrix :- " << endl;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            cout << "M[" << i + 1 << "][" << j + 1 << "] = ";
            cin >> mat[i][j];
        }
    }
}
int D2_Array::minimum()
{

    //* this function finds the minimum number in the matrix

    int min = mat[0][0];
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            if (mat[i][j] < min)
            {
                min = mat[i][j];
            }
        }
    }
    return min;
}
int D2_Array::max()
{

    //* this function finds the maximum number in the matrix
    int max = mat[0][0];
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            if (mat[i][j] > max)
            {
                max = mat[i][j];
            }
        }
    }
    return max;
}

/// @brief this function prints the triplet form of the matrix
/// @param none
/// @return none

void D2_Array::Triple()
{
    int min = minimum();
    int highest = max();
    int *pt = new int[rows * columns];    // temporary array to store the elements of the matrix
    int k = 0;                           // counter for the temporary array
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            pt[k] = mat[i][j];           
            k++;
        }
    }
    int *c = new int[rows * columns]; // array to store the sequence of numbers
    for (int i = 0; i < rows * columns; i++)
    {
        c[i] = 1;
    }
    k = 0;
    while (k < rows * columns)
    {
        int temp = pt[k];
        if (c[k] < 0)
        {
            k++;
            continue;
        }
        int x = k + 1;
        int flag = 0;
        while (x < rows * columns)
        {
            if (pt[x] > temp)
            {
                for (int i = 0; i < rows * columns; i++)
                {
                    flag = 1;
                    if (pt[i] > temp && pt[i] < pt[x]) // it will check if there is any number between the numbers in the sequence
                    {
                        flag = 1; // flag will remain change if no number is found
                        break;
                    }
                    else
                    {
                        flag = 0;
                    }
                }
                if (flag == 0)
                {
                    c[k] = c[k] + 1; // the count of numbers in the sequence will be incremented
                    c[x] = -1;       // the number will be flagged as -1 so that it should not be picked while being printed
                }
                else
                {
                    break;
                }
            }
            else
            {
                break;
            }
            temp = pt[x];
            x++;
        }

        k++; // the index will be incremented to check for the next number in the array
    }
    // to convert the array to matrix
    int **d = new int *[rows];
    for (int i = 0; i < rows; i++)
    {
        d[i] = new int[columns];
    }
    k = 0;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            d[i][j] = c[k];
            k++;
            // cout<<c[k];
        }
    }
    // to print the triplets from lowest number to highest number
    int p = 0;
    while (p < rows * columns)
    {
        int prev = min;
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < columns; j++)
            {
                if (mat[i][j] == min && d[i][j] > 0)
                {
                    cout << i + 1 << " " << j + 1 << " " << d[i][j] << endl; // printing the triplet in the format of row,column,sequence of numbers
                    d[i][j] = -1;
                    min = highest; // setting the highest number as the minimum number to drill down to the lowest number
                    for (int i = 0; i < rows; i++)
                    {
                        for (int j = 0; j < columns; j++)
                        {
                            if (mat[i][j] > prev && mat[i][j] < min && d[i][j] != -1) // minimum cannot be the number flagged as -1
                            {
                                min = mat[i][j];
                            }
                        }
                    }
                }
            }
        }
        p++;
    }

    //! deallocate the memory
    //* delete pt
    if (pt != nullptr)
        delete[] pt;

    //* delete c
    if (c != nullptr)
        delete[] c;

    //* delete d
    for (int i = 0; i < rows; i++)
    {
        if (d[i] != nullptr)
            delete[] d[i];
    }
    if (d != nullptr)
        delete[] d;
}
D2_Array ::~D2_Array()
{
    //* delete mat
    for (int i = 0; i < rows; i++)
    {
        if (mat[i] != nullptr)
            delete[] mat[i];
    }
    if (mat != nullptr)
        delete[] mat;
}