#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

class MyMatrix {
private:
    int r, c;
    vector<vector<double>> values;

public:
    // Создание пустой матрицы нужного размера
    MyMatrix(int rows, int cols) {
        r = rows;
        c = cols;
        values.assign(r, vector<double>(c, 0.0));
    }

    // Заполнение
    void fillFromConsole() {
        cout << "Введите числа для таблицы " << r << "x" << c << ":" << endl;
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                cout << "Элемент [" << i << "][" << j << "]: ";
                cin >> values[i][j];
            }
        }
    }

    // Вывод на экран
    void show() {
        cout << "--- Текущая матрица ---" << endl;
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                cout << setw(8) << values[i][j] << " ";
            }
            cout << endl;
        }
    }
    // Сложение матриц
    MyMatrix operator+(const MyMatrix& other) {
        if (r != other.r || c != other.c) {
            throw invalid_argument("Размеры матриц не совпадают, сложение невозможно!");
        }

        MyMatrix result(r, c);
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                result.values[i][j] = this->values[i][j] + other.values[i][j];
            }
        }
        return result;
    }
};

int main() {
    setlocale(LC_ALL, "Russian");

    try {
        int rows, cols;
        cout << "Введите размер матриц: ";
        cin >> rows >> cols;

        cout << "\n--- Заполнение первой матрицы ---" << endl;
        MyMatrix m1(rows, cols);
        m1.fillFromConsole();

        cout << "\n--- Заполнение второй матрицы ---" << endl;
        MyMatrix m2(rows, cols);
        m2.fillFromConsole();

        cout << "\nСкладываем матрицы..." << endl;
        MyMatrix sum = m1 + m2;
        sum.show();
    }
    catch (const exception& e) {
        cout << "Ошибка: " << e.what() << endl;
    }

    return 0;
}