#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;

void Create(int** a, const int rowCount, const int colCount, const int Low, const int High);
void Print(int** a, const int rowCount, const int colCount);
void Sort(int** a, const int rowCount, const int colCount);
void SwapRows(int** a, const int row1, const int row2, const int colCount);
void Calculate(int** a, const int rowCount, const int colCount, int& S, int& k);

int main()
{
    srand((unsigned)time(NULL)); 

    int Low = -31;
    int High = 54;
    int rowCount = 9;
    int colCount = 5;

    
    int** a = new int* [rowCount];
    for (int i = 0; i < rowCount; i++)
        a[i] = new int[colCount];
    Create(a, rowCount, colCount, Low, High);
    Print(a, rowCount, colCount);
    Sort(a, rowCount, colCount);
    Print(a, rowCount, colCount);
    int S = 0;
    int k = 0;
    Calculate(a, rowCount, colCount, S, k);
    cout << "Sum : " << S << endl;
    cout << "Count : " << k << endl;
    Print(a, rowCount, colCount);
    for (int i = 0; i < rowCount; i++)
        delete[] a[i];
    delete[] a;
    return 0;
}

void Create(int** a, const int rowCount, const int colCount, const int Low, const int High)
{
    for (int i = 0; i < rowCount; i++)
        for (int j = 0; j < colCount; j++)
            a[i][j] = Low + rand() % (High - Low + 1);
}

void Print(int** a, const int rowCount, const int colCount)
{
    cout << endl;
    for (int i = 0; i < rowCount; i++)
    {
        for (int j = 0; j < colCount; j++)
            cout << setw(4) << a[i][j];
        cout << endl;
    }
    cout << endl;
}

void Sort(int** a, const int rowCount, const int colCount)
{
    for (int i = 0; i < rowCount - 1; i++) 
    {
        for (int j = 0; j < rowCount - i - 1; j++) 
        {
         
            if (a[j][0] > a[j + 1][0]) 
            {
                SwapRows(a, j, j + 1, colCount);
            }
            else if (a[j][0] == a[j + 1][0] && a[j][1] < a[j + 1][1])
            {
                SwapRows(a, j, j + 1, colCount);
            }
            else if (a[j][0] == a[j + 1][0] && a[j][1] == a[j + 1][1] && a[j][3] > a[j + 1][3])
            {
                SwapRows(a, j, j + 1, colCount);
            }
        }
    }
}


void SwapRows(int** a, const int row1, const int row2, const int colCount) 
{
    for (int j = 0; j < colCount; j++) 
    {
        int temp = a[row1][j];
        a[row1][j] = a[row2][j];
        a[row2][j] = temp;
    }
}

void Calculate(int** a, const int rowCount, const int colCount, int& S, int& k) 
{
    S = 0;
    k = 0;
    for (int i = 0; i < rowCount; i++) 
    {
        for (int j = 0; j < colCount; j++)
        {
            if (a[i][j] > 0 && a[i][j] % 5 != 0)
            {
                S += a[i][j];
                k++;
                a[i][j] = 0; 
            }
        }
    }
}
