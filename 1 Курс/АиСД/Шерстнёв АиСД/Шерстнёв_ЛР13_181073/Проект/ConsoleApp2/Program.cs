using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp2
{
    internal class Program
    {
        static void Main(string[] args)
        {
            const string infinity = "INF";
            const int infInt = int.MaxValue;

            Console.Write("Введите количество узлов графа: ");
            var matrixSize = int.Parse(Console.ReadLine());

            var matrix = new int[matrixSize, matrixSize];
            for (var i = 0; i < matrixSize; i++)
            {
                for (var j = 0; j < matrixSize; j++)
                {
                    Console.Write($"Введите значение дуги {i} - {j} (0 - нет такой дуги, INF - бесконечность): ");
                    var input = Console.ReadLine();
                    if (input == infinity)
                    {
                        matrix[i, j] = infInt;
                    }
                    else
                    {
                        matrix[i, j] = int.Parse(input);
                    }
                }
            }

            matrix = RunFloydAlgorithm(matrix, matrixSize);
            Console.WriteLine("Итоговая матрица:");
            for (var columnIndex = 0; columnIndex < matrixSize; columnIndex++)
            {
                for (var rowIndex = 0; rowIndex < matrixSize; rowIndex++)
                {
                    var value = matrix[columnIndex, rowIndex] == infInt
                        ? infinity
                        : matrix[columnIndex, rowIndex].ToString();
                    Console.Write($"{value}\t");
                }

                Console.WriteLine();
            }
            Console.ReadKey();


            int[,] RunFloydAlgorithm(int[,] matrix1, int matrixSize1)
            {
                for (var k = 0; k < matrixSize1; ++k)
                {
                    for (var i = 0; i < matrixSize1; ++i)
                    {
                        for (var j = 0; j < matrixSize1; ++j)
                        {
                            var value = matrix1[i, k] + matrix1[k, j];
                            if (value >= 0 && value < matrix1[i, j])
                            {
                                matrix1[i, j] = value;
                            }
                        }
                    }
                }

                return matrix;
            }

        }
    }
}
