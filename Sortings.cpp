#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <locale.h>

// Функция пузырьковой сортировки
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Функция вывода массива
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Функция для подсчёта количества чисел в строке
int countNumbers(char* str) {
    int count = 0;
    char* token;
    char* context = NULL;

    char* copy = _strdup(str);
    if (!copy) return 0;

    token = strtok_s(copy, " ", &context);
    while (token != NULL) {
        count++;
        token = strtok_s(NULL, " ", &context);
    }

    free(copy);
    return count;
}

// Функция для парсинга строки в массив чисел
int parseInput(char* input, int** output) {
    int size = countNumbers(input);

    *output = (int*)malloc(size * sizeof(int));
    if (*output == NULL) {
        printf("Ошибка выделения памяти.\n");
        return 0;
    }

    char* token;
    char* context = NULL;
    char* copy = _strdup(input);
    if (!copy) {
        free(*output);
        return 0;
    }

    int i = 0;
    token = strtok_s(copy, " ", &context);
    while (token != NULL) {
        (*output)[i++] = atoi(token);
        token = strtok_s(NULL, " ", &context);
    }

    free(copy);
    return size;
}

int main() {
    setlocale(LC_ALL, "");
    system("chcp 65001");
    printf("\n");

    char input[256];

    printf("Введите числа через пробел:\n");
    fgets(input, sizeof(input), stdin);


    input[strcspn(input, "\n")] = '\0';

    int* arr;
    int n = parseInput(input, &arr);

    if (n == 0) {
        printf("Ошибка: не удалось считать числа.\n");
        return 1;
    }

    printf("Исходный массив:\n");
    printArray(arr, n);

    bubbleSort(arr, n);

    printf("Отсортированный массив:\n");
    printArray(arr, n);

    free(arr);

    printf("Нажмите любую клавишу для выхода");
    _getch();

    return 0;
}