using System;
using System.Collections.Generic;

namespace lab_five
{
    internal class Program
    {
        public static int[] hash { get; set; }

            public static void AddValue(int value)
            {
                var k = GetHash(value);
                if (hash[k].Equals(0))
                {
                    hash[k] = value;
                }
                else
                {
                    for (int i = 0; i < hash.Length; i++)
                    {
                        if (i == k) continue;
                        if (hash[i].Equals(0))
                        {
                            hash[i] = value;
                            break;
                        }
                    }
                }
            }

            public static string Search(int value)
            {
                var k = GetHash(value);
                if (hash[k] != 0)
                {
                    for (int i = 0; i < hash.Length; i++)
                    {
                        if (value.Equals(hash[i]))
                        {
                            k = i;
                        }
                    }

                    return $"Hash: {k}; ";
                }
                else
                {
                    return "Not found";
                }
            }

            private static int GetHash(int value)
            {
                int result = 0;
                if (Type.GetTypeCode(value.GetType()) == TypeCode.Int32)
                {
                    int temp = Convert.ToInt32(value);

                    while (temp != 0)
                    {
                        result += (temp % 10);
                        temp /= 10;
                    }
                }
                return result % hash.Length;
            }

            private static void Main(string[] args)
            {
                int arrayLength = 11;
                int hashLength = 15;
                int start = 44000;
                int end = 73000;

                Console.WriteLine($"\nRange: {start} - {end}");

                Console.Write($"n: {arrayLength}");
                Console.WriteLine($"\nM: {hashLength}");

                int[] array = new int[arrayLength];

                hash = new int[hashLength];

                Console.WriteLine();
                for (int i = 0; i < arrayLength; i++)
                {
                    Console.Write($"{i + 1}: ");
                    int value = -1;
                    while (value < start || value > end)
                    {
                        value = Convert.ToInt32(Console.ReadLine());
                    }

                    array[i] = value;
                    AddValue(value);
                }

                Console.WriteLine("\nArray");
                for (int i = 0; i < arrayLength; i++)
                {
                    Console.Write($"{array[i]}, ");
                }

                Console.WriteLine("\n\nhash");
                for (int i = 0; i < hash.Length; i++)
                {
                    if (hash[i] == 0)
                    {
                        Console.WriteLine($"{i}: ");
                    }
                    else
                    {
                        Console.WriteLine($"{i}: {hash[i]} ");
                    }
                }

                Console.WriteLine("\nSearch:");
                int search = Convert.ToInt32(Console.ReadLine());
                Console.WriteLine($"{Search(search)}");

                Console.ReadKey();
            }
        }
    }

