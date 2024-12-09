#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <chrono>
#include <cstdlib> // Для rand() и srand()
#include <ctime>   // Для time()
#include "SetArray.h"

using namespace std;

const int universe_size = 26;
int Set::counter = 0;

void generateString(char arr[], int n) {
    int count = 0;
    bool used[16] = { false }; // У нас 16 уникальных символов (0-9 и A-F)
    char symbols[] = "0123456789ABCDEF"; // Массив возможных символов

    while (count < n) {
        int index = rand() % 16; // Генерируем случайный индекс от 0 до 15

        if (!used[index]) {
            arr[count++] = symbols[index]; // Добавляем символ в массив
            used[index] = true; // Помечаем символ как использованный
        }
    }
    arr[count] = '\0'; // Завершаем строку нулевым символом
}

int main() {
    srand(static_cast<unsigned int>(time(0)));

    // Цикл по значениям n от 1 до 5
    for (int n = 5; n <= 10; ++n) {
        cout << "----------------------------------------" << endl;
        cout << "Testing with maximum length of the set: " << n << endl;

        char a[universe_size + 1] = { 0 };
        char b[universe_size + 1] = { 0 };
        char c[universe_size + 1] = { 0 };
        char d[universe_size + 1] = { 0 };

        generateString(a, n);
        generateString(b, n);
        generateString(c, n);
        generateString(d, n);

        Set A(a), B(b), C(c), D(d), E;

        cout << "A: "; A.show();
        cout << "B: "; B.show();
        cout << "C: "; C.show();
        cout << "D: "; D.show();

        // Начинаем отсчет времени
        auto start = chrono::high_resolution_clock::now();

        E = (((A & B) & C) | D);

        // Останавливаем отсчет времени
        auto end = chrono::high_resolution_clock::now();

        // Вычисляем время выполнения
        auto duration = chrono::duration_cast<chrono::nanoseconds>(end - start).count();

        cout << "E: "; E.show();

        // Выводим время выполнения
        cout << "Time taken for operations: " << duration << " nanoseconds" << endl;
         // Разделитель для читаемости
    }

    cin.get();
    return 0;
}