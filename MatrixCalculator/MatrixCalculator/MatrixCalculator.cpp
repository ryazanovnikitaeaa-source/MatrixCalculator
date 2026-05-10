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

    // Заполнениез
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
};

int main() {
    setlocale(LC_ALL, "Russian");

    int rows, cols;
    cout << "Введите количество строк: ";
    cin >> rows;
    cout << "Введите количество столбцов: ";
    cin >> cols;

    MyMatrix m(rows, cols);
    m.fillFromConsole();
    m.show();

    return 0;
}