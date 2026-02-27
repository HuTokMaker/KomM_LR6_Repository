using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace KomM_LR6
{
    internal class Program
    {
        static void Main(string[] args)
        {
            while (true)
            {
                Console.WriteLine("\nГлавное меню");
                Console.WriteLine("1 - Задача 1: Переселение в Лайнландии");
                Console.WriteLine("0 - Выход из программы");
                Console.Write("Выберите задачу: ");

                string choice = Console.ReadLine();

                Console.Clear();

                switch (choice)
                {
                    case "1":
                        Task1();
                        break;
                    case "0":
                        Console.WriteLine("Программа завершена.");
                        return;
                    default:
                        Console.WriteLine("Неверный ввод. Пожалуйста, выберите 1, 2 или 0.");
                        break;
                }

                Console.WriteLine("\nНажмите любую клавишу для возврата в меню...");
                Console.ReadKey();
                Console.Clear();
            }

        }

        static void Task1()
        {
            Console.WriteLine("=== Задача 1: Переселение в Лайнландии ===\n");

            try
            {
                Console.Write("Введите количество городов N (от 2 до 100): ");
                int n = int.Parse(Console.ReadLine());

                if (n < 2 || n > 100)
                {
                    Console.WriteLine("Ошибка: N должно быть от 2 до 100");
                    return;
                }

                Console.WriteLine($"Введите {n} чисел (цены проживания в городах от 0 до {n - 1}):");
                string[] input = Console.ReadLine().Split(' ');

                if (input.Length < n)
                {
                    Console.WriteLine($"Ошибка: нужно ввести ровно {n} чисел");
                    return;
                }

                int[] prices = new int[n];

                for (int i = 0; i < n; i++)
                {
                    prices[i] = int.Parse(input[i]);

                    if (prices[i] < 0 || prices[i] > 1000000000)
                    {
                        Console.WriteLine("Ошибка: цена должна быть от 0 до 10^9");
                        return;
                    }
                }

                int[] result = new int[n];

                for (int i = 0; i < n; i++)
                {
                    result[i] = -1; 

                    for (int j = i + 1; j < n; j++)
                    {
                        if (prices[j] < prices[i])
                        {
                            result[i] = j;
                            break;
                        }
                    }
                }

                Console.WriteLine("\nРезультаты переселения:");
                Console.WriteLine("Город | Цена | Переселяется в город");
                Console.WriteLine("------|------|---------------------");

                for (int i = 0; i < n; i++)
                {
                    if (result[i] == -1)
                        Console.WriteLine($"  {i,-3} | {prices[i],-4} | -1 (нет подходящего города)");
                    else
                        Console.WriteLine($"  {i,-3} | {prices[i],-4} | {result[i]} (цена {prices[result[i]]} меньше)");
                }

                Console.Write("\nОтвет в одну строку: ");
                for (int i = 0; i < n; i++)
                {
                    Console.Write(result[i] + " ");
                }
                Console.WriteLine();
            }
            catch (FormatException)
            {
                Console.WriteLine("Ошибка: введите целые числа");
            }
            catch (Exception ex)
            {
                Console.WriteLine($"Произошла ошибка: {ex.Message}");
            }
        }
    }
}