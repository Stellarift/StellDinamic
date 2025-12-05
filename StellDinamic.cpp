#include <iostream>
using namespace std;

void task1() {
    int M, N;

    cout << "Задание 1" << endl;
    cout << "Введите размер массива A (M): ";
    cin >> M;
    cout << "Введите размер массива B (N): ";
    cin >> N;

    int* A = new int[M];
    int* B = new int[N];

    cout << "Введите элементы массива A (" << M << " чисел): ";
    for (int i = 0; i < M; i++) {
        cin >> A[i];
    }

    cout << "Введите элементы массива B (" << N << " чисел): ";
    for (int i = 0; i < N; i++) {
        cin >> B[i];
    }

    int* temp = new int[M];
    int resultSize = 0;

    for (int i = 0; i < M; i++) {
        //нет ли элемента уже в temp
        bool alreadyInTemp = false;
        for (int j = 0; j < resultSize; j++) {
            if (temp[j] == A[i]) {
                alreadyInTemp = true;
                break;
            }
        }

        //есть ли элемент в B 
        bool inB = false;
        for (int j = 0; j < N; j++) {
            if (B[j] == A[i]) {
                inB = true;
                break;
            }
        }

        if (!alreadyInTemp && !inB) {
            temp[resultSize] = A[i];
            resultSize++;
        }
    }

    int* C = new int[resultSize];
    for (int i = 0; i < resultSize; i++) {
        C[i] = temp[i];
    }

    cout << "Массив C (элементы A, которых нет в B): ";
    if (resultSize == 0) {
        cout << "пустой";
    }
    else {
        for (int i = 0; i < resultSize; i++) {
            cout << C[i] << " ";
        }
    }
    cout << endl;

    delete[] A;
    delete[] B;
    delete[] temp;
    delete[] C;
}

void task2() {
    int M, N;

    cout << "\nЗадание 2" << endl;
    cout << "Введите размер массива A (M): ";
    cin >> M;
    cout << "Введите размер массива B (N): ";
    cin >> N;

    int* A = new int[M];
    int* B = new int[N];

    cout << "Введите элементы массива A (" << M << " чисел): ";
    for (int i = 0; i < M; i++) {
        cin >> A[i];
    }

    cout << "Введите элементы массива B (" << N << " чисел): ";
    for (int i = 0; i < N; i++) {
        cin >> B[i];
    }

    int* temp = new int[M + N];
    int resultSize = 0;

    //Элементы из A, которых нет в B
    for (int i = 0; i < M; i++) {
        bool alreadyInTemp = false;
        for (int j = 0; j < resultSize; j++) {
            if (temp[j] == A[i]) {
                alreadyInTemp = true;
                break;
            }
        }

        bool inB = false;
        for (int j = 0; j < N; j++) {
            if (B[j] == A[i]) {
                inB = true;
                break;
            }
        }

        if (!alreadyInTemp && !inB) {
            temp[resultSize] = A[i];
            resultSize++;
        }
    }

    //Элементы из B, которых нет в A
    for (int i = 0; i < N; i++) {
        bool alreadyInTemp = false;
        for (int j = 0; j < resultSize; j++) {
            if (temp[j] == B[i]) {
                alreadyInTemp = true;
                break;
            }
        }

        bool inA = false;
        for (int j = 0; j < M; j++) {
            if (A[j] == B[i]) {
                inA = true;
                break;
            }
        }

        if (!alreadyInTemp && !inA) {
            temp[resultSize] = B[i];
            resultSize++;
        }
    }

    int* C = new int[resultSize];
    for (int i = 0; i < resultSize; i++) {
        C[i] = temp[i];
    }

    cout << "Массив C (элементы, не общие для A и B): ";
    if (resultSize == 0) {
        cout << "пустой";
    }
    else {
        for (int i = 0; i < resultSize; i++) {
            cout << C[i] << " ";
        }
    }
    cout << endl;

    delete[] A;
    delete[] B;
    delete[] temp;
    delete[] C;
}

int main() {
    setlocale(LC_ALL, "ru");
    task1();
    task2();
    cout << "\nПрограмма завершена." << endl;
    return 0;
}