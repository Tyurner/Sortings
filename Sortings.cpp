#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <locale.h>

// Функция пузырьковой сортировки O(n^2)
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

//Функция шейкерной сортировки O(n^2), в лучшем случае O(n)
void cocktailSort(int arr[], int n) {
    int left = 0;
    int right = n - 1;
    int i, swapped;

    do {
        swapped = 0;

        // Проход слева направо: как в пузырьковой сортировке
        for (i = left; i < right; ++i) {
            if (arr[i] > arr[i + 1]) {
                int temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;
                swapped = 1;
            }
        }

        if (!swapped)
            break;

        swapped = 0;
        --right;

        // Проход справа налево
        for (i = right; i > left; --i) {
            if (arr[i - 1] > arr[i]) {
                int temp = arr[i];
                arr[i] = arr[i - 1];
                arr[i - 1] = temp;
                swapped = 1;
            }
        }

        ++left;

    } while (swapped);
}

// Вспомогательная функция для разделения массива
int partition(int arr[], int low, int high) {
    int pivot = arr[high];  // Опорный элемент — последний элемент
    int i = low - 1;        // Индекс меньшего элемента

    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            // Меняем местами arr[i] и arr[j]
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    // Ставим опорный элемент на своё место
    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;

    return i + 1; // Возвращаем позицию опорного элемента
}

// Функция быстрой сортировки худш - O(n^2), среднее - O(nlogn)
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        // Разделяем массив и получаем позицию опорного элемента
        int pi = partition(arr, low, high);

        // Рекурсивно сортируем левую часть
        quickSort(arr, low, pi - 1);

        // Рекурсивно сортируем правую часть
        quickSort(arr, pi + 1, high);
    }
}

// Функция слияния двух подмассивов arr[l..m] и arr[m+1..r]
void merge(int arr[], int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    // Создаем временные массивы
    int* L = (int*)malloc(n1 * sizeof(int));
    int* R = (int*)malloc(n2 * sizeof(int));

    // Копируем данные во временные массивы L[] и R[]
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    // Сливаем временные массивы обратно в arr[l..r]

    i = 0; // Начальный индекс первого подмассива
    j = 0; // Начальный индекс второго подмассива
    k = l; // Начальный индекс объединённого подмассива

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Копируем оставшиеся элементы из L[], если они есть
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Копируем оставшиеся элементы из R[], если они есть
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }

    // Освобождаем память
    free(L);
    free(R);
}

// Функция сортировки слиянием всегда O(nlogn)
void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2; // То же, что (l + r)/2, но без переполнения

        // Сортируем левую и правую части
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        // Сливаем отсортированные части
        merge(arr, l, m, r);
    }
}

void heapify(int arr[], int n, int i) {
    int largest = i;         // Инициализируем наибольший элемент как корень
    int left = 2 * i + 1;    // Левый дочерний элемент
    int right = 2 * i + 2;   // Правый дочерний элемент

    // Если левый дочерний больше корня
    if (left < n && arr[left] > arr[largest])
        largest = left;

    // Если правый дочерний больше самого большого на данный момент
    if (right < n && arr[right] > arr[largest])
        largest = right;

    // Если самый большой элемент не является корнем
    if (largest != i) {
        // Меняем местами
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;

        // Рекурсивно просеиваем вниз затронутую подкучу
        heapify(arr, n, largest);
    }
}

// Функция сортировки кучей всегда O(nlogn)
void heapSort(int arr[], int n) {
    // Построение max-heap (перестраиваем массив)
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // Один за другим извлекаем элементы из кучи
    for (int i = n - 1; i > 0; i--) {
        // Перемещаем текущий корень в конец
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;

        // Вызываем heapify на уменьшенной куче
        heapify(arr, i, 0);
    }
}

// Структура узла бинарного дерева
typedef struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

// Функция для создания нового узла
TreeNode* createNode(int value) {
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
    if (!newNode) {
        printf("Ошибка выделения памяти!\n");
        exit(1);
    }
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Вставка элемента в дерево
TreeNode* insertNode(TreeNode* root, int value) {
    if (root == NULL)
        return createNode(value);

    if (value < root->data)
        root->left = insertNode(root->left, value);
    else
        root->right = insertNode(root->right, value);

    return root;
}

// In-order обход дерева (вывод в отсортированном порядке)
void inOrderTraversal(TreeNode* root, int* arr, int* index) {
    if (root != NULL) {
        inOrderTraversal(root->left, arr, index);
        arr[*index] = root->data;
        (*index)++;
        inOrderTraversal(root->right, arr, index);
    }
}

// Освобождение памяти, занятой деревом
void freeTree(TreeNode* root) {
    if (root != NULL) {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}

// Функция сортировки деревом O(nlogn), однако в разбалансированном дереве может достигать O(n^2)
void treeSort(int arr[], int n) {
    TreeNode* root = NULL;

    // Построение дерева
    for (int i = 0; i < n; i++) {
        root = insertNode(root, arr[i]);
    }

    // Обратный обход и запись в массив
    int index = 0;
    inOrderTraversal(root, arr, &index);

    // Очистка памяти
    freeTree(root);
}

// Функция сортировки вставками O(n^2)
void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];       // Текущий элемент для вставки
        int j = i - 1;

        // Перемещаем элементы arr[0..i-1], которые больше key,
        // на одну позицию вперёд
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }

        arr[j + 1] = key; // Вставляем текущий элемент на нужное место
    }
}

// Функция сортировки выбором всегда O(n^2)
void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        // Предполагаем, что минимальный элемент — на позиции i
        int minIndex = i;

        // Ищем минимальный элемент в оставшейся части массива
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;  // Обновляем индекс минимального элемента
            }
        }

        // Меняем местами минимальный элемент и первый элемент неотсортированной части
        if (minIndex != i) {
            int temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
        }
    }
}

// Функция сортировки Шелла в реднем O(nLog^2n) худшая O(n^2)
void shellSort(int arr[], int n) {
    // Начинаем с большого шага, делим его пополам на каждом шаге
    for (int gap = n / 2; gap > 0; gap /= 2) {
        // Проходим по элементам, начиная с gap
        for (int i = gap; i < n; i++) {
            int temp = arr[i];
            int j;

            // Перемещаем элементы arr[j], которые больше temp,
            // на gap позиций назад
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                arr[j] = arr[j - gap];
            }

            // Вставляем arr[i] на нужное место
            arr[j] = temp;
        }
    }
}

// Возвращает максимальный элемент массива
int getMax(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > max)
            max = arr[i];
    return max;
}

// Сортировка подсчётом по разряду (exp)
void countingSortForRadix(int arr[], int n, int exp) {
    int* output = (int*)malloc(n * sizeof(int));
    int count[10] = { 0 };

    // Подсчёт количества
    for (int i = 0; i < n; i++)
        count[(arr[i] / exp) % 10]++;

    // Изменяем count[i], чтобы он содержал позиции в output
    for (int i = 1; i < 10; i++)
        count[i] += count[i - 1];

    // Строим output массив справа налево (устойчивость!)
    for (int i = n - 1; i >= 0; i--) {
        int digit = (arr[i] / exp) % 10;
        output[count[digit] - 1] = arr[i];
        count[digit]--;
    }

    // Копируем назад
    for (int i = 0; i < n; i++)
        arr[i] = output[i];

    free(output);
}

// Функция поразрядной сортировки (на полож) O(k*n), где k - кол-во разрядов
void radixSort(int arr[], int n) {
    if (n <= 0) return;

    int max = getMax(arr, n);

    // Сортируем по каждому разряду
    for (int exp = 1; max / exp > 0; exp *= 10)
        countingSortForRadix(arr, n, exp);
}

//Функция сортировки подсчетом O(n+m) m - кол-во возможных значений элементов
void countingSort(int arr[], int n, int maxVal) {
    // Массив для подсчёта частоты значений
    int* count = (int*)calloc(maxVal + 1, sizeof(int));
    if (!count) {
        printf("Ошибка выделения памяти!\n");
        return;
    }

    // Массив для результата
    int* output = (int*)malloc(n * sizeof(int));
    if (!output) {
        printf("Ошибка выделения памяти!\n");
        free(count);
        return;
    }

    // Подсчёт количества элементов
    for (int i = 0; i < n; i++)
        count[arr[i]]++;

    // Обновляем count[i] так, чтобы он содержал позиции в выходном массиве
    for (int i = 1; i <= maxVal; i++)
        count[i] += count[i - 1];

    // Строим выходной массив (справа налево для устойчивости)
    for (int i = n - 1; i >= 0; i--) {
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }

    // Копируем отсортированный массив обратно в исходный
    for (int i = 0; i < n; i++)
        arr[i] = output[i];

    // Освобождаем память
    free(count);
    free(output);
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

    /* для жесткой задачи int arr[] = {5, 6, -9, 0};
    int n = sizeof(arr) / sizeof(arr[0]);*/

    printf("Исходный массив:\n");
    printArray(arr, n);

    //bubbleSort(arr, n);
    //cocktailSort(arr, n);
    //quickSort(arr, 0, n - 1);
    //mergeSort(arr, 0, n - 1);
    //heapSort(arr, n);
    //treeSort(arr, n);
    //insertionSort(arr, n);
    //selectionSort(arr, n);
    //shellSort(arr, n);
    //radixSort(arr, n);      
    //int maxVal = arr[0];// Находим максимальное значение
    //for (int i = 1; i < n; i++)
        //if (arr[i] > maxVal)
            //maxVal = arr[i];
    //countingSort(arr, n, maxVal);

    printf("Отсортированный массив:\n");
    printArray(arr, n);

    free(arr);

    printf("Нажмите любую клавишу для выхода");
    _getch();

    return 0;
}