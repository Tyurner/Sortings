////C#
////Обход в глубину
//using System;

//class Program
//{
//	// Генерация случайного графа
//	static int[,] GenerateGraph(int size)
//	{
//		var rand = new Random();
//		int[,] matrix = new int[size, size];

//		for (int i = 0; i < size; i++)
//		{
//			for (int j = i + 1; j < size; j++)
//			{
//				int edge = rand.Next(2); // 0 или 1 — есть ли ребро
//				matrix[i, j] = edge;
//				matrix[j, i] = edge; // граф неориентированный
//			}
//		}

//		return matrix;
//	}

//	// Вывод матрицы смежности
//	static void PrintGraph(int[,] matrix)
//	{
//		int size = (int)Math.Sqrt(matrix.Length);
//		Console.Write("   ");
//		for (int i = 0; i < size; i++) Console.Write($"{i} ");
//		Console.WriteLine();

//		for (int i = 0; i < size; i++)
//		{
//			Console.Write($"{i}: ");
//			for (int j = 0; j < size; j++)
//			{
//				Console.Write($"{matrix[i, j]} ");
//			}
//			Console.WriteLine();
//		}
//	}

//	// Обход в глубину (Depth-First Search)
//	static void DFS(int node, int[,] graph, bool[] visited)
//	{
//		visited[node] = true;
//		Console.Write(node + " ");

//		int size = visited.Length;
//		for (int i = 0; i < size; i++)
//		{
//			if (graph[node, i] == 1 && !visited[i])
//			{
//				DFS(i, graph, visited);
//			}
//		}
//	}

//	static void Main()
//	{
//		int size = 6; // количество вершин
//		int[,] adjacencyMatrix = GenerateGraph(size);

//		Console.WriteLine("Матрица смежности:");
//		PrintGraph(adjacencyMatrix);

//		bool[] visited = new bool[size];
//		Console.WriteLine("\nОбход в глубину (DFS):");
//		for (int i = 0; i < size; i++)
//		{
//			if (!visited[i])
//				DFS(i, adjacencyMatrix, visited);
//		}

//		Console.ReadKey();
//	}
//}

////обход в ширину
//using System;
//using System.Collections.Generic;

//class Program
//{
//	// Генерация случайного графа
//	static int[,] GenerateGraph(int size)
//	{
//		var rand = new Random();
//		int[,] matrix = new int[size, size];

//		for (int i = 0; i < size; i++)
//		{
//			for (int j = i + 1; j < size; j++)
//			{
//				int edge = rand.Next(2); // 0 или 1 — есть ли ребро
//				matrix[i, j] = edge;
//				matrix[j, i] = edge; // граф неориентированный
//			}
//		}

//		return matrix;
//	}

//	// Вывод матрицы смежности
//	static void PrintGraph(int[,] matrix)
//	{
//		int size = (int)Math.Sqrt(matrix.Length);
//		Console.Write("   ");
//		for (int i = 0; i < size; i++) Console.Write($"{i} ");
//		Console.WriteLine();

//		for (int i = 0; i < size; i++)
//		{
//			Console.Write($"{i}: ");
//			for (int j = 0; j < size; j++)
//			{
//				Console.Write($"{matrix[i, j]} ");
//			}
//			Console.WriteLine();
//		}
//	}

//	// Обход в ширину (Breadth-First Search)
//	static void BFS(int startNode, int[,] graph, bool[] visited)
//	{
//		Queue<int> queue = new Queue<int>();

//		visited[startNode] = true;
//		queue.Enqueue(startNode);

//		while (queue.Count > 0)
//		{
//			int node = queue.Dequeue();
//			Console.Write(node + " ");

//			int size = visited.Length;
//			for (int i = 0; i < size; i++)
//			{
//				if (graph[node, i] == 1 && !visited[i])
//				{
//					visited[i] = true;
//					queue.Enqueue(i);
//				}
//			}
//		}
//	}

//	static void Main()
//	{
//		int size = 6; // количество вершин
//		int[,] adjacencyMatrix = GenerateGraph(size);

//		Console.WriteLine("Матрица смежности:");
//		PrintGraph(adjacencyMatrix);

//		bool[] visited = new bool[size];
//		Console.WriteLine("\nОбход в ширину (BFS):");
//		for (int i = 0; i < size; i++)
//		{
//			if (!visited[i])
//				BFS(i, adjacencyMatrix, visited);
//		}

//		Console.ReadKey();
//	}
//}