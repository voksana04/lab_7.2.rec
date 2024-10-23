#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;

void CreateRows(int** a, const int n, const int Low, const int High, int row = 0);
void CreateRow(int** a, const int n, const int Low, const int High, int row, int col);
void PrintRows(int** a, const int n, int row = 0);
void PrintRow(int** a, const int n, int row, int col);
void Transpose(int** a, const int n, int i = 0, int j = 0);

int main()
{
    srand((unsigned)time(NULL));

    int n;
    cout << " n = ";
    cin >> n;

    int Low = 1;   
    int High = 9;   

    int** a = new int* [n];
    for (int i = 0; i < n; i++)
        a[i] = new int[n];

    CreateRows(a, n, Low, High);
    cout << "\nOriginal matrix:\n";
    PrintRows(a, n);

    Transpose(a, n);
    cout << "\nTranspose matrix:\n";
    PrintRows(a, n);

    for (int i = 0; i < n; i++)
        delete[] a[i];
    delete[] a;

    return 0;
}

void CreateRows(int** a, const int n, const int Low, const int High, int row)
{
    if (row < n)
    {
        CreateRow(a, n, Low, High, row, 0);
        CreateRows(a, n, Low, High, row + 1);
    }
}

void CreateRow(int** a, const int n, const int Low, const int High, int row, int col)
{
    if (col < n)
    {
        a[row][col] = Low + rand() % (High - Low + 1);
        CreateRow(a, n, Low, High, row, col + 1);
    }
}

void PrintRows(int** a, const int n, int row)
{
    if (row < n)
    {
        PrintRow(a, n, row, 0);
        cout << endl;
        PrintRows(a, n, row + 1);
    }
}

void PrintRow(int** a, const int n, int row, int col)
{
    if (col < n)
    {
        cout << setw(4) << a[row][col];
        PrintRow(a, n, row, col + 1);
    }
}

void Transpose(int** a, const int n, int i, int j)
{
    if (i < n)
    {
        if (j < n)
        {
            if (i < j)
            {
                int temp = a[i][j];
                a[i][j] = a[j][i];
                a[j][i] = temp;
            }
            Transpose(a, n, i, j + 1);
        }
        else
        {
            Transpose(a, n, i + 1, i + 1);
        }
    }
}