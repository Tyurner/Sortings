////Двусвязный список C
//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#include <cstddef>
//
//// Структура "Тур"
//typedef struct {
//    int id;
//    char name[100];
//    char country[100];
//    int placesCount;
//    char fio[100];
//} Tour;
//
//// Узел двусвязного списка
//typedef struct Node {
//    Tour data;
//    struct Node* next;
//    struct Node* prev;
//} Node;
//
//// Двусвязный список
//typedef struct {
//    Node* head;
//    Node* tail;
//} LinkedList;
//
//// Инициализация списка
//void initList(LinkedList* list) {
//    list->head = NULL;
//    list->tail = NULL;
//}
//
//// Очистка буфера ввода
//void clearInputBuffer() {
//    int c;
//    while ((c = getchar()) != '\n' && c != EOF);
//}
//
//// Ввод целого числа с защитой от ошибок
//int getIntInput(const char* prompt) {
//    int value;
//    char line[256];
//
//    while (1) {
//        printf("%s", prompt);
//        if (fgets(line, sizeof(line), stdin)) {
//            if (sscanf_s(line, "%d", &value) == 1) {
//                return value;
//            }
//            else {
//                printf("Invalid input. Please enter a number.\n");
//            }
//        }
//    }
//}
//
//// Ввод строки с защитой от пустого ввода
//void getStringInput(const char* prompt, char* buffer, size_t bufferSize) {
//    while (1) {
//        printf("%s", prompt);
//        if (fgets(buffer, bufferSize, stdin)) {
//            size_t len = strlen(buffer);
//            if (len > 0 && buffer[len - 1] == '\n') {
//                buffer[len - 1] = '\0'; // Убираем '\n'
//            }
//            if (strlen(buffer) > 0) {
//                break;
//            }
//            else {
//                printf("Input cannot be empty. Try again.\n");
//            }
//        }
//    }
//}
//
//// Добавление элемента по ID (сохраняя порядок)
//void insertSorted(LinkedList* list, Tour newTour) {
//    Node* newNode = (Node*)malloc(sizeof(Node));
//    if (!newNode) {
//        printf("Memory allocation error\n");
//        return;
//    }
//
//    newNode->data = newTour;
//    newNode->next = NULL;
//    newNode->prev = NULL;
//
//    if (list->head == NULL) {
//        list->head = list->tail = newNode;
//        return;
//    }
//
//    // Вставка в начало
//    if (newTour.id < list->head->data.id) {
//        newNode->next = list->head;
//        list->head->prev = newNode;
//        list->head = newNode;
//        return;
//    }
//
//    // Вставка в конец
//    if (newTour.id > list->tail->data.id) {
//        newNode->prev = list->tail;
//        list->tail->next = newNode;
//        list->tail = newNode;
//        return;
//    }
//
//    // Вставка в середину
//    Node* current = list->head;
//    while (current && current->data.id < newTour.id) {
//        current = current->next;
//    }
//
//    if (current && current->data.id == newTour.id) {
//        printf("Tour with this ID already exists. Skipping...\n");
//        free(newNode);
//        return;
//    }
//
//    newNode->next = current;
//    newNode->prev = current->prev;
//
//    if (current->prev) {
//        current->prev->next = newNode;
//    }
//    else {
//        list->head = newNode;
//    }
//
//    current->prev = newNode;
//}
//
//// Удаление элемента по ID
//void deleteById(LinkedList* list, int id) {
//    Node* current = list->head;
//
//    while (current != NULL) {
//        if (current->data.id == id) {
//            // Обновляем указатели соседей
//            if (current->prev) {
//                current->prev->next = current->next;
//            }
//            else {
//                list->head = current->next; // текущий был первым
//            }
//
//            if (current->next) {
//                current->next->prev = current->prev;
//            }
//            else {
//                list->tail = current->prev; // текущий был последним
//            }
//
//            // Удаляем узел
//            free(current);
//            printf("Tour with ID %d successfully deleted.\n", id);
//            return;
//        }
//        current = current->next;
//    }
//
//    printf("Tour with ID %d not found.\n", id);
//}
//
//// Вывод всех элементов
//void printList(const LinkedList* list) {
//    if (list->head == NULL) {
//        printf("\nList is empty.\n");
//        return;
//    }
//
//    Node* current = list->head;
//    printf("\nTour List:\n");
//    while (current != NULL) {
//        printf("ID: %d\n", current->data.id);
//        printf("Name: %s\n", current->data.name);
//        printf("Country: %s\n", current->data.country);
//        printf("Places Count: %d\n", current->data.placesCount);
//        printf("FIO: %s\n", current->data.fio);
//        printf("------------------------\n");
//
//        current = current->next;
//    }
//}
//
//// Очистка списка
//void freeList(LinkedList* list) {
//    Node* current = list->head;
//    while (current != NULL) {
//        Node* next = current->next;
//        free(current);
//        current = next;
//    }
//    list->head = list->tail = NULL;
//}
//
//// --- Главная функция ---
//int main() {
//    LinkedList tourList;
//    initList(&tourList);
//
//    int choice;
//
//    do {
//        printf("\nMenu:\n");
//        printf("1. Add tour\n");
//        printf("2. Show all tours\n");
//        printf("3. Delete tour by ID\n");
//        printf("0. Exit\n");
//        choice = getIntInput("Enter your choice: ");
//
//        switch (choice) {
//        case 1: {
//            Tour newTour;
//
//            newTour.id = getIntInput("Tour ID: ");
//            getStringInput("Tour Name: ", newTour.name, sizeof(newTour.name));
//            getStringInput("Tour Country: ", newTour.country, sizeof(newTour.country));
//            newTour.placesCount = getIntInput("Places Count: ");
//            getStringInput("FIO of responsible person: ", newTour.fio, sizeof(newTour.fio));
//
//            insertSorted(&tourList, newTour);
//            break;
//        }
//        case 2:
//            printList(&tourList);
//            break;
//        case 3: {
//            int idToDelete = getIntInput("Enter Tour ID to delete: ");
//            deleteById(&tourList, idToDelete);
//            break;
//        }
//        case 0:
//            printf("Exiting...\n");
//            break;
//        default:
//            printf("Invalid command. Please try again.\n");
//        }
//    } while (choice != 0);
//
//    freeList(&tourList);
//    return 0;
//}



////C++
//#include <string>
//#include <iostream>
//using namespace std;
//
//struct Tour {
//    int Id;
//    string Name;
//    string Country;
//    int PlacesCount;
//    string Fio;
//};
//
//struct Node {
//    Tour Value;
//    Node* nextNode;
//    Node* previousNode;
//
//    Node(Tour val) : Value(val), nextNode(nullptr), previousNode(nullptr) {}
//};
//
//struct LinkedList {
//    Node* first;
//    Node* last;
//
//    LinkedList() : first(nullptr), last(nullptr) {}
//
//    bool isEmpty() {
//        return first == nullptr;
//    }
//
//    void print() {
//        if (isEmpty()) {
//            return;
//        }
//
//        Node* current = first;
//        while (current) {
//            cout << "ID: " << current->Value.Id << "\n";
//            cout << "Name: " << current->Value.Name << "\n";
//            cout << "Country: " << current->Value.Country << "\n";
//            cout << "PlacesCount: " << current->Value.PlacesCount << "\n";
//            cout << "FIO: " << current->Value.Fio << "\n\n";
//            current = current->nextNode;
//        }
//    }
//
//    void insertSorted(Tour value) {
//        Node* newNode = new Node(value);
//
//        if (isEmpty()) {
//            first = last = newNode;
//            return;
//        }
//
//        if (value.Id < first->Value.Id) {
//            newNode->nextNode = first;
//            first->previousNode = newNode;
//            first = newNode;
//            return;
//        }
//
//        if (value.Id > last->Value.Id) {
//            last->nextNode = newNode;
//            newNode->previousNode = last;
//            last = newNode;
//            return;
//        }
//
//        Node* current = first;
//        while (current && current->Value.Id < value.Id) {
//            current = current->nextNode;
//        }
//
//        if (current && current->Value.Id == value.Id) {
//            delete newNode;
//            return;
//        }
//
//        newNode->nextNode = current;
//        newNode->previousNode = current->previousNode;
//        current->previousNode->nextNode = newNode;
//        current->previousNode = newNode;
//    }
//};
//
//int main() {
//    LinkedList tourList;
//    Tour newTour;
//    int choice;
//
//    do {
//        cout << "\nMenu:\n";
//        cout << "1. Add tour\n";
//        cout << "2. Show all\n";
//        cout << "0. Exit\n";
//        cin >> choice;
//
//        switch (choice) {
//        case 1: {
//            cout << "Tour Id: ";
//            cin >> newTour.Id;
//            cin.ignore();
//
//            cout << "Tour name: ";
//            getline(cin, newTour.Name);
//
//            cout << "Tour Country: ";
//            getline(cin, newTour.Country);
//
//            cout << "Places count: ";
//            cin >> newTour.PlacesCount;
//            cin.ignore();
//
//            cout << "FIO: ";
//            getline(cin, newTour.Fio);
//
//            tourList.insertSorted(newTour);
//            break;
//        }
//        case 2:
//            tourList.print();
//            break;
//        case 0:
//            break;
//        default:
//            cout << "Wrong command!\n";
//        }
//    } while (choice != 0);
//
//    return 0;
//}


////Классический List
//#include <iostream>
//#include <list>
//#include <string>
//
//// Структура "Самолёт"
//struct Airplane {
//    std::string model;
//    int year;
//    int tailNumber; // Бортовой номер
//};
//
//// Функция для вывода информации о самолёте
//void printAirplane(const Airplane& a) {
//    std::cout << "Модель: " << a.model
//        << ", Год: " << a.year
//        << ", Бортномер: " << a.tailNumber
//        << std::endl;
//}
//
//// Функция для добавления самолёта в список
//void addAirplaneToList(std::list<Airplane>& airplanes, const Airplane& plane) {
//    airplanes.push_back(plane); // Добавляем самолёт в список
//
//    // Сортируем по бортовому номеру после каждого добавления
//    airplanes.sort([](const Airplane& a, const Airplane& b) {
//        return a.tailNumber < b.tailNumber;
//        });
//}
//
//// Функция для вывода всех самолётов
//void printAllAirplanes(const std::list<Airplane>& airplanes) {
//    for (const auto& plane : airplanes) {
//        printAirplane(plane);
//    }
//}
//
//int main() {
//    std::list<Airplane> airplanes;
//
//    // Создаем структуры в main и передаём в функцию
//    Airplane a1 = { "Boeing 737", 2015, 12345 };
//    Airplane a2 = { "Airbus A320", 2018, 12344 };
//    Airplane a3 = { "Antonov An-2", 1960, 12346 };
//
//    // Добавляем через функцию
//    addAirplaneToList(airplanes, a1);
//    addAirplaneToList(airplanes, a2);
//    addAirplaneToList(airplanes, a3);
//
//    // Выводим отсортированный список
//    printAllAirplanes(airplanes);
//
//    return 0;
//}