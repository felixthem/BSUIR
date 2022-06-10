Console.WriteLine("Задание 1. Кратчайшие пути от вершины-источника до всех вершин орграфа на основе алгоритма Дейкстры.");

Console.Write("Введите количество узлов графа: ");
var size = int.Parse(Console.ReadLine()!);

var matrix = new int[size, size];
for (var i = 0; i < size; i++)
{
    for (var j = 0; j < size; j++)
    {
        Console.Write($"Введите значение дуги {i}->{j} или 0: ");
        matrix[i, j] = int.Parse(Console.ReadLine()!);
    }
}

Console.Write("Введите вершину-источник: ");
var source = int.Parse(Console.ReadLine()!);
Algorithm(matrix, source, size);

Console.ReadKey();

int MinDistance(IReadOnlyList<int> dist, IReadOnlyList<bool> sptSet)
{
    var maxValue = int.MaxValue;
    var minIndex = -1;
    for (var i = 0; i < dist.Count; i++)
    {
        if (sptSet[i] || dist[i] > maxValue)
            continue;

        maxValue = dist[i];
        minIndex = i;
    }
    return minIndex;
}

void Algorithm(int[,] matrix, int root, int size)
{
    var dist = new int[size];
    var path = new int[size];
    var checkPoint = new bool[size];

    for (var i = 0; i < size; i++)
    {
        dist[i] = int.MaxValue;
        checkPoint[i] = false;
    }

    dist[root] = 0;

    for (var i = 1; i < size; i++)
    {
        var maxValue = int.MaxValue;
        var minDist = -1;
        for (var j = 0; j < dist.Length; j++)
        {
            if (checkPoint[j] || dist[j] > maxValue)
                continue;

            maxValue = dist[j];
            minDist = j;
        }
        checkPoint[minDist] = true;

        for (var j = 0; j < size; j++)
        {
            if (checkPoint[j]
                || matrix[minDist, j] == 0
                || dist[minDist] == int.MaxValue
                || dist[minDist] + matrix[minDist, j] >= dist[j])
                continue;

            dist[j] = dist[minDist] + matrix[minDist, j];
            path[j] = minDist;
        }
        
        if (path[i] == 0)
            Console.WriteLine($"Кратчайший путь: из {root}->{i} | Расстояние: {dist[i]}");
        else
        {
            var stack = new Stack<int>();
            stack.Push(path[i]);
            
            Console.Write($"Кратчайший путь: из {root}->");
            for (var j = path[i]; j != 0; j = path[j])
            {
                if (path[j] == 0)
                    break;

                stack.Push(path[j]);
                j = path[j];
            }
            
            for (var j = 0; j <= stack.Count; j++)
            {
                if (j == stack.Count)
                    Console.Write($"{i} | Расстояние: {dist[i]}");
                else
                {
                    Console.Write(stack.Pop() + " -> ");
                    j = -1;
                }
            }
            Console.WriteLine();
        }
    }
}