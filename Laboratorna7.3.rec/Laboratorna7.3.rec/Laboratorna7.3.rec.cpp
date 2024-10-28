#include <iostream>
#include <iomanip>
#include <ctime>
#include <Windows.h>

using namespace std;

void Create(int** a, const int rowCount, const int colCount, const int Low, const int High) {
    for (int i = 0; i < rowCount; i++)
        for (int j = 0; j < colCount; j++)
            a[i][j] = Low + rand() % (High - Low + 1);
}

void Print(int** a, const int rowCount, const int colCount) {
    cout << endl;
    for (int i = 0; i < rowCount; i++) {
        for (int j = 0; j < colCount; j++)
            cout << setw(4) << a[i][j];
        cout << endl;
    }
    cout << endl;
}

int CountColumnsWithoutZeros(int** a, const int rowCount, const int colCount, int col = 0) {
    if (col == colCount) return 0;

    bool hasZero = false;
    for (int i = 0; i < rowCount; i++) {
        if (a[i][col] == 0) {
            hasZero = true;
            break;
        }
    }

    if (hasZero) {
        return CountColumnsWithoutZeros(a, rowCount, colCount, col + 1);
    }
    else {
        return 1 + CountColumnsWithoutZeros(a, rowCount, colCount, col + 1);
    }
}

int RowCharacteristic(int* row, const int colCount, int col = 0) {
    if (col == colCount) return 0;
    int add = 0;
    if (row[col] > 0 && row[col] % 2 == 0) {
        add = row[col];
    }
    return add + RowCharacteristic(row, colCount, col + 1);
}

void SortRows(int** a, const int rowCount, const int colCount, int i = 0) {
    if (i >= rowCount - 1)
        return;

    for (int j = 0; j < rowCount - 1 - i; j++) {
        if (RowCharacteristic(a[j], colCount) > RowCharacteristic(a[j + 1], colCount)) {
            int* temp = a[j];
            a[j] = a[j + 1];
            a[j + 1] = temp;
        }
    }

    SortRows(a, rowCount, colCount, i + 1);
}

int main() {
    srand((unsigned)time(NULL));
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int Low = -41;
    int High = 23;
    int rowCount, colCount;

    cout << "k = ";
    cin >> rowCount;
    cout << "n = ";
    cin >> colCount;

    int** a = new int* [rowCount];
    for (int i = 0; i < rowCount; i++)
        a[i] = new int[colCount];

    Create(a, rowCount, colCount, Low, High);
    Print(a, rowCount, colCount);

    int zeroColumns = CountColumnsWithoutZeros(a, rowCount, colCount);
    cout << "Стовпці які не містять нулів: " << zeroColumns << endl;

    SortRows(a, rowCount, colCount);
    cout << "Відсортована матриця:" << endl;
    Print(a, rowCount, colCount);

    for (int i = 0; i < rowCount; i++)
        delete[] a[i];
    delete[] a;

    return 0;
}
