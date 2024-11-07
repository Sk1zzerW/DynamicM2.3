#include <iostream>
using namespace std;

void shiftRows(int** array, int rows, int cols, int shifts, bool direction) {
    shifts %= rows;
    if (shifts == 0) return;

    int** temp = new int* [rows];
    for (int i = 0; i < rows; i++) {
        temp[i] = array[(direction ? i - shifts + rows : i + shifts) % rows];
    }

    for (int i = 0; i < rows; i++) {
        array[i] = temp[i];
    }
    delete[] temp;
}

void shiftColumns(int** array, int rows, int cols, int shifts, bool direction) {
    shifts %= cols;
    if (shifts == 0) return;

    int** temp = new int* [rows];
    for (int i = 0; i < rows; i++) {
        temp[i] = new int[cols];
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            temp[i][j] = array[i][(direction ? j - shifts + cols : j + shifts) % cols];
        }
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            array[i][j] = temp[i][j];
        }
        delete[] temp[i];
    }
    delete[] temp;
}

int main() {
    int rows = 3, cols = 3;
    int** array = new int* [rows];
    for (int i = 0; i < rows; i++) {
        array[i] = new int[cols] {i + 1, i + 2, i + 3};

    int shifts = 1;
    bool direction = true;
    shiftRows(array, rows, cols, shifts, direction);
    cout << "после циклического сдвига строк:\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << array[i][j] << " ";
        }
        cout << endl;
    }

    shiftColumns(array, rows, cols, shifts, direction);
    cout << "после циклического сдвига столбйов:\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << array[i][j] << " ";
        }
        cout << endl;
    }

    for (int i = 0; i < rows; i++) delete[] array[i];
    delete[] array;
    return 0;
}
