////метод цепочек
//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#include <corecrt_malloc.h>
//
//#define TABLE_SIZE 10
//
//// Узел списка (цепочка)
//typedef struct Node {
//    char* key;
//    int value;
//    struct Node* next;
//} Node;
//
//// Хэш-таблица
//typedef struct HashTable {
//    Node** buckets;
//} HashTable;
//
//// Хэш-функция (простой пример)
//unsigned int hash(const char* key) {
//    unsigned long int value = 0;
//    while (*key)
//        value += *key++;
//    return value % TABLE_SIZE;
//}
//
//// Создание узла
//Node* create_node(const char* key, int value) {
//    Node* node = (Node*)malloc(sizeof(Node));
//    node->key = _strdup(key);
//    node->value = value;
//    node->next = NULL;
//    return node;
//}
//
//// Инициализация хэш-таблицы
//HashTable* create_hash_table() {
//    HashTable* table = (HashTable*)malloc(sizeof(HashTable));
//    table->buckets = (Node**)calloc(TABLE_SIZE, sizeof(Node*));
//    return table;
//}
//
//// Вставка в таблицу
//void insert(HashTable* table, const char* key, int value) {
//    unsigned int index = hash(key);
//    Node* current = table->buckets[index];
//
//    // Если ключ уже существует — обновляем значение
//    while (current != NULL) {
//        if (strcmp(current->key, key) == 0) {
//            current->value = value;
//            return;
//        }
//        current = current->next;
//    }
//
//    // Добавляем новую запись в начало списка
//    Node* new_node = create_node(key, value);
//    new_node->next = table->buckets[index];
//    table->buckets[index] = new_node;
//}
//
//// Поиск значения по ключу
//int search(HashTable* table, const char* key) {
//    unsigned int index = hash(key);
//    Node* current = table->buckets[index];
//
//    while (current != NULL) {
//        if (strcmp(current->key, key) == 0)
//            return current->value;
//        current = current->next;
//    }
//
//    return -1; // Ключ не найден
//}
//
//// Удаление элемента по ключу
//int remove_key(HashTable* table, const char* key) {
//    unsigned int index = hash(key);
//    Node* current = table->buckets[index];
//    Node* previous = NULL;
//
//    while (current != NULL) {
//        if (strcmp(current->key, key) == 0) {
//            // Удаляем текущий узел
//            if (previous == NULL) {
//                // Удаляем первый элемент списка
//                table->buckets[index] = current->next;
//            }
//            else {
//                // Удаляем не первый элемент
//                previous->next = current->next;
//            }
//
//            // Освобождаем память
//            free(current->key);
//            free(current);
//
//            return 1; // Успех
//        }
//
//        previous = current;
//        current = current->next;
//    }
//
//    return 0; // Ключ не найден
//}
//
//// Освобождение памяти
//void free_hash_table(HashTable* table) {
//    for (int i = 0; i < TABLE_SIZE; i++) {
//        Node* current = table->buckets[i];
//        while (current != NULL) {
//            Node* temp = current;
//            current = current->next;
//            free(temp->key);
//            free(temp);
//        }
//    }
//    free(table->buckets);
//    free(table);
//}
//
//// Пример использования
//int main() {
//    HashTable* table = create_hash_table();
//    insert(table, "one", 1);
//    insert(table, "two", 2);
//    insert(table, "three", 3);
//
//    printf("Before removal:\n");
//    printf("Search 'two': %d\n", search(table, "two"));     // Output: 2
//    printf("Search 'three': %d\n", search(table, "three")); // Output: 3
//
//    // Удаляем элемент
//    remove_key(table, "two");
//
//    printf("\nAfter removal:\n");
//    printf("Search 'two': %d\n", search(table, "two"));     // Output: -1
//    printf("Search 'three': %d\n", search(table, "three")); // Output: 3
//
//    free_hash_table(table);
//    return 0;
//}
//
////Метод двойного хэширования
//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#include <conio.h>
//#include <locale.h>
//
//#define TABLE_SIZE 10
//
//typedef struct {
//    char* key;
//    int value;
//} Entry;
//
//typedef struct {
//    Entry* entries;
//    int count;
//} HashTable;
//
//unsigned int hash1(const char* key) {
//    unsigned long val = 0;
//    while (*key)
//        val += *key++;
//    return val % TABLE_SIZE;
//}
//
//unsigned int hash2(const char* key) {
//    unsigned long val = 0;
//    while (*key)
//        val += *key++;
//    return 1 + (val % (TABLE_SIZE - 1)); // Всегда > 0
//}
//
//void init_table(HashTable* table) {
//    table->entries = (Entry*)calloc(TABLE_SIZE, sizeof(Entry));
//    table->count = 0;
//}
//
//int find_index(HashTable* table, const char* key) {
//    unsigned int index = hash1(key);
//    unsigned int step = hash2(key);
//
//    for (int i = 0; i < TABLE_SIZE; i++) {
//        Entry entry = table->entries[index];
//        if (entry.key == NULL)
//            return -1 - index; // Свободная позиция или пусто
//        if (strcmp(entry.key, key) == 0)
//            return index; // Найден ключ
//        index = (index + step) % TABLE_SIZE;
//    }
//    return -1; // Не найдено
//}
//
//void insert(HashTable* table, const char* key, int value) {
//    int index = find_index(table, key);
//    if (index >= 0) {
//        table->entries[index].value = value; // Обновляем
//        return;
//    }
//
//    index = -index - 1;
//    table->entries[index].key = _strdup(key);
//    table->entries[index].value = value;
//    table->count++;
//}
//
//int search(HashTable* table, const char* key) {
//    int index = find_index(table, key);
//    return (index >= 0) ? table->entries[index].value : -1;
//}
//
//void remove_key(HashTable* table, const char* key) {
//    int index = find_index(table, key);
//    if (index >= 0) {
//        free(table->entries[index].key);
//        table->entries[index].key = NULL;
//        table->count--;
//    }
//}
//
//void free_table(HashTable* table) {
//    for (int i = 0; i < TABLE_SIZE; i++) {
//        if (table->entries[i].key)
//            free(table->entries[i].key);
//    }
//    free(table->entries);
//}
//
//// Пример использования
//int main() {
//    HashTable table;
//    init_table(&table);
//
//    insert(&table, "one", 1);
//    insert(&table, "two", 2);
//    insert(&table, "three", 3);
//
//    printf("Search 'two': %d\n", search(&table, "two"));   // Output: 2
//    printf("Search 'four': %d\n", search(&table, "four")); // Output: -1
//
//    remove_key(&table, "two");
//
//    printf("After removal:\n");
//    printf("Search 'two': %d\n", search(&table, "two"));   // Output: -1
//
//    insert(&table, "two", 2);
//    printf("Search 'two': %d\n", search(&table, "two"));   // Output: 2
//
//    free_table(&table);
//    return 0;
//}
//
//
//
//
//
//
//
//
//
////C#
////Метод цепочек
//
//using System;
//using System.Collections.Generic;
//
//public struct Entry<TKey, TValue>
//{
//	public TKey Key;
//	public TValue Value;
//
//	public Entry(TKey key, TValue value)
//	{
//		Key = key;
//		Value = value;
//	}
//}
//
//public struct HashTable<TKey, TValue> where TKey : class
//{
//	private const int DefaultSize = 10;
//	private List<Entry<TKey, TValue>>[] _buckets = new List<Entry<TKey, TValue>>[DefaultSize];
//
//	public HashTable()
//	{
//		if (DefaultSize <= 0)
//			throw new ArgumentOutOfRangeException(nameof(DefaultSize));
//
//		_buckets = new List<Entry<TKey, TValue>>[DefaultSize];
//		for (int i = 0; i < _buckets.Length; i++)
//		{
//			_buckets[i] = new List<Entry<TKey, TValue>>();
//		}
//	}
//
//	private int GetBucketIndex(TKey key)
//	{
//		if (key == null)
//			return 0;
//
//		unchecked
//		{
//			int hash = key.GetHashCode();
//			return Math.Abs(hash) % _buckets.Length;
//		}
//	}
//
//	public void Insert(TKey key, TValue value)
//	{
//		if (key == null) throw new ArgumentNullException(nameof(key));
//
//		int index = GetBucketIndex(key);
//		var bucket = _buckets[index];
//
//		// Обновление значения, если ключ существует
//		foreach(var entry in bucket)
//		{
//			if (Equals(entry.Key, key))
//			{
//				RemoveFromList(bucket, key);
//				break;
//			}
//		}
//
//		bucket.Add(new Entry<TKey, TValue>(key, value));
//	}
//
//	public bool TryGetValue(TKey key, out TValue value)
//	{
//		if (key == null)
//		{
//			value = default;
//			return false;
//		}
//
//		int index = GetBucketIndex(key);
//		var bucket = _buckets[index];
//
//		foreach(var entry in bucket)
//		{
//			if (Equals(entry.Key, key))
//			{
//				value = entry.Value;
//				return true;
//			}
//		}
//
//		value = default;
//		return false;
//	}
//
//	public bool Remove(TKey key)
//	{
//		if (key == null) return false;
//
//		int index = GetBucketIndex(key);
//		var bucket = _buckets[index];
//
//		foreach(var entry in bucket)
//		{
//			if (Equals(entry.Key, key))
//			{
//				return RemoveFromList(bucket, key);
//			}
//		}
//
//		return false;
//	}
//
//	private bool RemoveFromList(List<Entry<TKey, TValue>> list, TKey key)
//	{
//		for (int i = 0; i < list.Count; i++)
//		{
//			if (Equals(list[i].Key, key))
//			{
//				list.RemoveAt(i);
//				return true;
//			}
//		}
//		return false;
//	}
//
//	public void PrintAll()
//	{
//		for (int i = 0; i < _buckets.Length; i++)
//		{
//			Console.Write($"Bucket {i}: ");
//			foreach(var entry in _buckets[i])
//			{
//				Console.Write($"[{entry.Key}:{entry.Value}] ");
//			}
//			Console.WriteLine();
//		}
//	}
//}
//
//class Program
//{
//	static void Main()
//	{
//		HashTable<string, int> table = new HashTable<string, int>();
//
//		table.Insert("one", 1);
//		table.Insert("two", 2);
//		table.Insert("three", 3);
//
//		Console.WriteLine("Search 'two': " + (table.TryGetValue("two", out int val) ? val.ToString() : "not found"));
//
//		table.Remove("two");
//
//		Console.WriteLine("After removal:");
//		Console.WriteLine("Search 'two': " + (table.TryGetValue("two", out val) ? val.ToString() : "not found"));
//	}
//}

////Метод двойного хэширования
//using System;
//
//public struct Entry<TKey, TValue> where TKey : class
//{
//	public TKey Key;
//	public TValue Value;
//
//	public Entry(TKey key, TValue value)
//	{
//		Key = key;
//		Value = value;
//	}
//}
//
//public struct HashTable<TKey, TValue> where TKey : class
//{
//	private const int DefaultSize = 10;
//	private readonly int _size;
//	private Entry<TKey, TValue>[] _entries;
//	private bool[] _occupied;
//	private bool[] _deleted;
//
//	public HashTable()
//	{
//		_size = DefaultSize;
//		_entries = new Entry<TKey, TValue>[DefaultSize];
//		_occupied = new bool[DefaultSize];
//		_deleted = new bool[DefaultSize];
//	}
//
//	private int Hash1(TKey key)
//	{
//		unchecked
//		{
//			int hash = key ? .GetHashCode() ? ? 0;
//			return Math.Abs(hash) % _size;
//		}
//	}
//
//	private int Hash2(TKey key)
//	{
//		unchecked
//		{
//			int hash = key ? .GetHashCode() ? ? 0;
//			return 1 + Math.Abs(hash) % (_size - 1); // Всегда > 0
//		}
//	}
//
//	public void Insert(TKey key, TValue value)
//	{
//		int index = FindIndex(key);
//		if (index >= 0)
//		{
//			_entries[index].Value = value;
//			return;
//		}
//
//		index = -index - 1;
//		_entries[index] = new Entry<TKey, TValue>(key, value);
//		_occupied[index] = true;
//		_deleted[index] = false;
//	}
//
//	public bool TryGetValue(TKey key, out TValue value)
//	{
//		int index = FindIndex(key);
//		if (index >= 0)
//		{
//			value = _entries[index].Value;
//			return true;
//		}
//
//		value = default;
//		return false;
//	}
//
//	private int FindIndex(TKey key)
//	{
//		int index = Hash1(key);
//		int step = Hash2(key);
//
//		for (int i = 0; i < _size; i++)
//		{
//			if (!_occupied[index])
//				return -1 - index;
//
//			if (!_deleted[index] && Equals(_entries[index].Key, key))
//				return index;
//
//			index = (index + step) % _size;
//		}
//
//		return -1;
//	}
//
//	public bool Remove(TKey key)
//	{
//		int index = FindIndex(key);
//		if (index >= 0)
//		{
//			_deleted[index] = true;
//			return true;
//		}
//		return false;
//	}
//
//	public void PrintAll()
//	{
//		for (int i = 0; i < _size; i++)
//		{
//			if (_occupied[i] && !_deleted[i])
//			{
//				Console.WriteLine($"Bucket {i}: [{_entries[i].Key}:{_entries[i].Value}]");
//			}
//		}
//	}
//}
//
//class Program
//{
//	static void Main()
//	{
//		HashTable<string, int> table = new HashTable<string, int>();
//
//		table.Insert("one", 1);
//		table.Insert("two", 2);
//		table.Insert("three", 3);
//
//		Console.WriteLine("Before removal:");
//		table.PrintAll();
//
//		Console.WriteLine("\nRemoving 'two'...");
//		table.Remove("two");
//
//		Console.WriteLine("\nAfter removal:");
//		table.PrintAll();
//
//		if (table.TryGetValue("two", out int val))
//			Console.WriteLine("Found 'two': " + val);
//		else
//			Console.WriteLine("Not found 'two'");
//
//		if (table.TryGetValue("one", out int res))
//		{
//			Console.WriteLine("\nValue for 'one': " + res);
//		}
//		else
//		{
//			Console.WriteLine("\n'one' not found.");
//		}
//	}
//}