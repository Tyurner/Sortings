////Бинарное дерево поиска
//
//#include <stdio.h>
//#include <stdlib.h>
//
//typedef struct Node {
//    int value;
//    struct Node* left;
//    struct Node* right;
//} Node;
//
//// Создание нового узла
//Node* create_node(int value) {
//    Node* node = (Node*)malloc(sizeof(Node));
//    node->value = value;
//    node->left = NULL;
//    node->right = NULL;
//    return node;
//}
//
//// Вставка элемента
//Node* insert(Node* root, int value) {
//    if (root == NULL)
//        return create_node(value);
//
//    if (value < root->value)
//        root->left = insert(root->left, value);
//    else
//        root->right = insert(root->right, value);
//
//    return root;
//}
//
//// Поиск элемента
//Node* search(Node* root, int value) {
//    if (root == NULL || root->value == value)
//        return root;
//
//    if (value < root->value)
//        return search(root->left, value);
//    else
//        return search(root->right, value);
//}
//
//// Найти минимальный узел (в правом поддереве)
//Node* find_min(Node* node) {
//    while (node && node->left != NULL)
//        node = node->left;
//    return node;
//}
//
//// Удаление узла
//Node* deleteNode(Node* root, int value) {
//    if (root == NULL)
//        return root;
//
//    if (value < root->value)
//        root->left = deleteNode(root->left, value);
//    else if (value > root->value)
//        root->right = deleteNode(root->right, value);
//    else {
//        // Узел с одним или нулём дочерних узлов
//        if (root->left == NULL) {
//            Node* temp = root->right;
//            free(root);
//            return temp;
//        }
//        else if (root->right == NULL) {
//            Node* temp = root->left;
//            free(root);
//            return temp;
//        }
//
//        // Узел с двумя дочерними узлами: заменяем на минимальный из правого поддерева
//        Node* temp = find_min(root->right);
//        root->value = temp->value;
//        root->right = deleteNode(root->right, temp->value);
//    }
//    return root;
//}
//
//// Инфиксный обход (LNR)
//void in_order(Node* root) {
//    if (root != NULL) {
//        in_order(root->left);
//        printf("%d ", root->value);
//        in_order(root->right);
//    }
//}
//
//// Очистка дерева
//void free_tree(Node* root) {
//    if (root != NULL) {
//        free_tree(root->left);
//        free_tree(root->right);
//        free(root);
//    }
//}
//
//// Пример использования
//int main() {
//    Node* root = NULL;
//
//    root = insert(root, 50);
//    root = insert(root, 30);
//    root = insert(root, 20);
//    root = insert(root, 40);
//    root = insert(root, 70);
//    root = insert(root, 60);
//    root = insert(root, 80);
//
//    printf("In-order traversal:\n");
//    in_order(root);
//    printf("\n");
//
//    printf("Delete 20\n");
//    root = deleteNode(root, 20);
//    printf("Delete 30\n");
//    root = deleteNode(root, 30);
//    printf("Delete 50\n");
//    root = deleteNode(root, 50);
//
//    printf("After deletions:\n");
//    in_order(root);
//    printf("\n");
//
//    free_tree(root);
//    return 0;
//}



//// Функция бинарного поиска
//// Возвращает индекс элемента или -1, если не найден
//#include <stdio.h>
//int binarySearch(int arr[], int size, int target) {
//    int left = 0;
//    int right = size - 1;
//
//    while (left <= right) {
//        int mid = left + (right - left) / 2; // избегаем переполнения
//
//        if (arr[mid] == target) {
//            return mid; // Найдено!
//        }
//        else if (arr[mid] < target) {
//            left = mid + 1; // искать в правой половине
//        }
//        else {
//            right = mid - 1; // искать в левой половине
//        }
//    }
//
//    return -1; // Не найдено
//}
//
//int main() {
//    int arr[] = { 2, 5, 7, 9, 12, 16, 19 };
//    int size = sizeof(arr) / sizeof(arr[0]);
//    int target;
//
//    printf("Введите число для поиска: ");
//    scanf_s("%d", &target);
//
//    int index = binarySearch(arr, size, target);
//
//    if (index != -1)
//        printf("Элемент найден на позиции: %d\n", index);
//    else
//        printf("Элемент не найден.\n");
//
//    return 0;
//}





////Реализация на C#
//using System;
//
//public class BinarySearchTree<T> where T : IComparable<T>
//{
//	private class Node
//	{
//		public T Value { get; set; }
//		public Node Left { get; set; }
//		public Node Right { get; set; }
//
//		public Node(T value)
//		{
//			Value = value;
//			Left = null;
//			Right = null;
//		}
//	}
//
//	private Node _root;
//
//	// Вставка элемента
//	public void Insert(T value)
//	{
//		_root = InsertRecursive(_root, value);
//	}
//
//	private Node InsertRecursive(Node node, T value)
//	{
//		if (node == null)
//			return new Node(value);
//
//		if (value.CompareTo(node.Value) < 0)
//			node.Left = InsertRecursive(node.Left, value);
//		else if (value.CompareTo(node.Value) > 0)
//			node.Right = InsertRecursive(node.Right, value);
//
//		return node;
//	}
//
//	// Поиск элемента
//	public bool Search(T value)
//	{
//		return SearchRecursive(_root, value) != null;
//	}
//
//	private Node SearchRecursive(Node node, T value)
//	{
//		if (node == null || value.CompareTo(node.Value) == 0)
//			return node;
//
//		if (value.CompareTo(node.Value) < 0)
//			return SearchRecursive(node.Left, value);
//		else
//			return SearchRecursive(node.Right, value);
//	}
//
//	// Удаление элемента
//	public void Delete(T value)
//	{
//		_root = DeleteRecursive(_root, value);
//	}
//
//	private Node DeleteRecursive(Node node, T value)
//	{
//		if (node == null)
//			return node;
//
//		if (value.CompareTo(node.Value) < 0)
//			node.Left = DeleteRecursive(node.Left, value);
//		else if (value.CompareTo(node.Value) > 0)
//			node.Right = DeleteRecursive(node.Right, value);
//		else
//		{
//			// Узел с одним или нулём дочерних узлов
//			if (node.Left == null)
//				return node.Right;
//			else if (node.Right == null)
//				return node.Left;
//
//			// Узел с двумя дочерними узлами
//			node.Value = FindMin(node.Right).Value;
//			node.Right = DeleteRecursive(node.Right, node.Value);
//		}
//		return node;
//	}
//
//	private Node FindMin(Node node)
//	{
//		while (node.Left != null)
//			node = node.Left;
//		return node;
//	}
//
//	// Обход InOrder (возрастающий порядок)
//	public void InOrder()
//	{
//		InOrderRecursive(_root);
//		Console.WriteLine();
//	}
//
//	private void InOrderRecursive(Node node)
//	{
//		if (node != null)
//		{
//			InOrderRecursive(node.Left);
//			Console.Write($"{node.Value} ");
//			InOrderRecursive(node.Right);
//		}
//	}
//}
//
//// Пример использования
//class Program
//{
//	static void Main()
//	{
//		var tree = new BinarySearchTree<int>();
//
//		tree.Insert(50);
//		tree.Insert(30);
//		tree.Insert(20);
//		tree.Insert(40);
//		tree.Insert(70);
//		tree.Insert(60);
//		tree.Insert(80);
//
//		Console.WriteLine("In-order traversal:");
//		tree.InOrder(); // 20 30 40 50 60 70 80
//
//		Console.WriteLine("Delete 20");
//		tree.Delete(20);
//		Console.WriteLine("Delete 30");
//		tree.Delete(30);
//		Console.WriteLine("Delete 50");
//		tree.Delete(50);
//
//		Console.WriteLine("After deletions:");
//		tree.InOrder(); // 40 60 70 80
//
//		Console.WriteLine("Search 70: " + tree.Search(70)); // True
//		Console.WriteLine("Search 30: " + tree.Search(30)); // False
//	}
//}
// 
// 
////Функция бинарного поиска
//using System;
//
//class Program
//{
//    // Функция бинарного поиска O(nlogn)
//    static int BinarySearch(int[] array, int target)
//    {
//        int left = 0;
//        int right = array.Length - 1;
//
//        while (left <= right)
//        {
//            int mid = left + (right - left) / 2;
//
//            // Проверяем, есть ли цель в середине
//            if (array[mid] == target)
//                return mid;
//
//            // Если цель меньше — ищем в левой половине
//            if (array[mid] > target)
//                right = mid - 1;
//            else
//                // Если цель больше — ищем в правой половине
//                left = mid + 1;
//        }
//
//        // Элемент не найден
//        return -1;
//    }
//
//    static void Main()
//    {
//        int[] numbers = { 2, 5, 7, 9, 12, 16, 19 };
//        int target = 12;
//
//        int result = BinarySearch(numbers, target);
//
//        if (result != -1)
//            Console.WriteLine($"Элемент найден на позиции: {result}");
//        else
//            Console.WriteLine("Элемент не найден.");
//    }
//}