#include <iostream>
#include <fstream>
#include <filesystem>

using namespace std;

int main() {
    // Количество записей в файле
    const int count = 2;

    // Размер массива для хранения строк
    const int strSize = 20;

    // Имя файла
   string nameFile = "data/costume.txt";

    // Структура для хранения данных о костюме
    struct costume {
        char firm[strSize];
        int size;
        int price;
    };

    // Переменные для хранения данных о костюме
    char firm[strSize];
    int size;
    int price;

    // Массив структур для хранения данных о костюме
    costume mas[count];

    // Установка русской локали
    setlocale(LC_ALL, "Russian");

    // Вывод сообщения на экран
    cout << "* Hello, World! Привет, мир!" << endl;

    // Открытие файла для записи
    ofstream f_out(nameFile);

    // Запись данных, вводимых с клавиатуры, в файл
    for (int i = 0; i < count; i++) {
        cout << i + 1 << " Фирма:";
        cin >> firm;
        f_out << firm << endl;
        cout << "Размер:";
        cin >> size;
        f_out << size << endl;
        cout << "Цена:";
        cin >> price;
        f_out << price << endl;
        cout << "\n";
    }

    // Закрытие файла
    f_out.close();

    // Чтение данных из файла
    ifstream f_in(nameFile);
    for (int i = 0; i < count; i++) {
        f_in >> mas[i].firm;
        f_in >> mas[i].size;
        f_in >> mas[i].price;
    }
    // Закрытие файла
    f_in.close();

    // Вывод данных на экран
    for (int i = 0; i < count; i++) {
        cout << "Фирма: " << mas[i].firm << " Размер:"
             << mas[i].size << " Цена: " << mas[i].price << endl;
    }
}

