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
                Console.WriteLine("2 - Задача 2: Работа с очередью");
                Console.WriteLine("3 - Задача 3: Решение уравнений (линейных и квадратных)");
                Console.WriteLine("4 - Задача 4: Карточная игра");
                Console.WriteLine("5 - Задача 5: Класс Rectangle (прямоугольник)");
                Console.WriteLine("6 - Задача 6: Минимальный путь в таблице");
                Console.WriteLine("7 - Задача 7: Компоненты связности в графе");
                Console.WriteLine("8 - Задача 8: Кафе и купоны");
                Console.WriteLine("0 - Выход из программы");
                Console.Write("Выберите задачу: ");

                string choice = Console.ReadLine();

                Console.Clear();

                switch (choice)
                {
                    case "1":
                        Task1();
                        break;
                    case "2":
                        Task2();
                        break;
                    case "3":
                        Task3();
                        break;
                    case "4":
                        Task4();
                        break;
                    case "5":
                        Task5();
                        break;
                    case "6":
                        Task6();
                        break;
                    case "7":
                        Task7(); // или Task7BFS() для версии с обходом в ширину
                        break;
                    case "8":
                        Task8();
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

        static void Task2()
        {
            Console.WriteLine("=== Задача 2: Работа с очередью ===\n");
            Console.WriteLine("Доступные команды:");
            Console.WriteLine("  push n  - добавить число n в очередь");
            Console.WriteLine("  pop     - удалить первый элемент");
            Console.WriteLine("  front   - показать первый элемент");
            Console.WriteLine("  size    - показать размер очереди");
            Console.WriteLine("  clear   - очистить очередь");
            Console.WriteLine("  exit    - выйти из задачи\n");

            Queue<int> queue = new Queue<int>();

            while (true)
            {
                Console.Write("Введите команду: ");
                string input = Console.ReadLine();

                string[] parts = input.Split(' ');
                string command = parts[0].ToLower();

                switch (command)
                {
                    case "push":
                        if (parts.Length < 2)
                        {
                            Console.WriteLine("Ошибка: укажите число для добавления");
                            break;
                        }

                        try
                        {
                            int number = int.Parse(parts[1]);
                            queue.Enqueue(number);
                            Console.WriteLine("ok");
                        }
                        catch (FormatException)
                        {
                            Console.WriteLine("Ошибка: введите целое число");
                        }
                        break;

                    case "pop":
                        if (queue.Count == 0)
                        {
                            Console.WriteLine("error");
                        }
                        else
                        {
                            int popped = queue.Dequeue();
                            Console.WriteLine(popped);
                        }
                        break;

                    case "front":
                        if (queue.Count == 0)
                        {
                            Console.WriteLine("error");
                        }
                        else
                        {
                            int front = queue.Peek();
                            Console.WriteLine(front);
                        }
                        break;

                    case "size":
                        Console.WriteLine(queue.Count);
                        break;

                    case "clear":
                        queue.Clear();
                        Console.WriteLine("ok");
                        break;

                    case "exit":
                        Console.WriteLine("bye");
                        return;

                    default:
                        Console.WriteLine("Неизвестная команда");
                        break;
                }

                if (command != "exit" && command != "clear")
                {
                    Console.Write("Текущая очередь: ");
                    if (queue.Count == 0)
                    {
                        Console.WriteLine("пуста");
                    }
                    else
                    {
                        foreach (int item in queue)
                        {
                            Console.Write(item + " ");
                        }
                        Console.WriteLine();
                    }
                }
            }
        }




        static void Task3()
        {
            Console.WriteLine("=== Задача 3: Решение уравнений ===\n");
            Console.WriteLine("Введите коэффициенты уравнения (от 1 до 3 чисел через пробел):");
            Console.WriteLine("Примеры:");
            Console.WriteLine("  1 -2 1  -> x^2 - 2x + 1 = 0");
            Console.WriteLine("  2 4      -> 2x + 4 = 0");
            Console.WriteLine("  5        -> 5 = 0\n");
            Console.Write("Коэффициенты: ");

            string input = Console.ReadLine();
            string[] parts = input.Split(' ');

            List<string> filteredParts = new List<string>();
            foreach (string part in parts)
            {
                if (part != "")
                {
                    filteredParts.Add(part);
                }
            }

            if (filteredParts.Count < 1 || filteredParts.Count > 3)
            {
                Console.WriteLine("Ошибка: нужно ввести от 1 до 3 коэффициентов");
                return;
            }

            try
            {
                double[] coefficients = new double[filteredParts.Count];
                for (int i = 0; i < filteredParts.Count; i++)
                {
                    coefficients[i] = double.Parse(filteredParts[i]);
                }

                Console.Write("\nУравнение: ");
                PrintEquation(coefficients);

                double[] roots = Solve(coefficients);

                Console.Write("Корни: ");
                Print(roots);

                Console.WriteLine("\nПояснение:");
                ExplainSolution(coefficients, roots);
            }
            catch (FormatException)
            {
                Console.WriteLine("Ошибка: введите числа, разделенные пробелами");
            }
        }

        static double[] Solve(params double[] coefficients)
        {

            if (coefficients.Length == 1)
            {
                return new double[0];
            }
            else if (coefficients.Length == 2)
            {
                double b = coefficients[0];
                double c = coefficients[1];

                if (b == 0)
                {
                    return new double[0];
                }
                else
                {
                    double root = -c / b;
                    return new double[] { root };
                }
            }
            else if (coefficients.Length == 3)
            {
                double a = coefficients[0];
                double b = coefficients[1];
                double c = coefficients[2];

                if (a == 0)
                {
                    return Solve(b, c);
                }

                double discriminant = b * b - 4 * a * c;

                if (discriminant < 0)
                {
                    return new double[0];
                }
                else if (discriminant == 0)
                {
                    double root = -b / (2 * a);
                    return new double[] { root };
                }
                else
                {
                    double sqrtDiscriminant = Math.Sqrt(discriminant);
                    double root1 = (-b - sqrtDiscriminant) / (2 * a);
                    double root2 = (-b + sqrtDiscriminant) / (2 * a);

                    if (root1 < root2)
                    {
                        return new double[] { root1, root2 };
                    }
                    else
                    {
                        return new double[] { root2, root1 };
                    }
                }
            }
            else
            {
                return new double[0];
            }
        }

        static void Print(params double[] roots)
        {
            if (roots.Length == 0)
            {
                Console.WriteLine("нет действительных корней");
            }
            else
            {
                for (int i = 0; i < roots.Length; i++)
                {
                    if (roots[i] == Math.Floor(roots[i]))
                    {
                        Console.Write((int)roots[i]);
                    }
                    else
                    {
                        Console.Write(roots[i].ToString("F2"));
                    }

                    if (i < roots.Length - 1)
                    {
                        Console.Write(" ");
                    }
                }
                Console.WriteLine();
            }
        }

        static void PrintEquation(double[] coefficients)
        {
            if (coefficients.Length == 3)
            {
                PrintTerm(coefficients[0], "x^2");
                PrintTerm(coefficients[1], "x");
                PrintConstant(coefficients[2]);
                Console.WriteLine(" = 0");
            }
            else if (coefficients.Length == 2)
            {
                PrintTerm(coefficients[0], "x");
                PrintConstant(coefficients[1]);
                Console.WriteLine(" = 0");
            }
            else
            {
                Console.WriteLine($"{coefficients[0]} = 0");
            }
        }

        static void PrintTerm(double coefficient, string variable)
        {
            if (coefficient == 0) return;

            if (coefficient > 0)
            {
                if (coefficient == 1)
                    Console.Write($"+ {variable} ");
                else
                    Console.Write($"+ {coefficient}{variable} ");
            }
            else
            {
                if (coefficient == -1)
                    Console.Write($"- {variable} ");
                else
                    Console.Write($"- {Math.Abs(coefficient)}{variable} ");
            }
        }

        static void PrintConstant(double constant)
        {
            if (constant == 0) return;

            if (constant > 0)
                Console.Write($"+ {constant} ");
            else
                Console.Write($"- {Math.Abs(constant)} ");
        }

        static void ExplainSolution(double[] coefficients, double[] roots)
        {
            if (coefficients.Length == 1)
            {
                Console.WriteLine($"- Это уравнение вида {coefficients[0]} = 0");
                if (coefficients[0] == 0)
                {
                    Console.WriteLine("- 0 = 0 верно для любого x, но по условию выводим пустую строку");
                }
                else
                {
                    Console.WriteLine($"- {coefficients[0]} ≠ 0, поэтому нет решений");
                }
            }
            else if (coefficients.Length == 2)
            {
                Console.WriteLine($"- Это линейное уравнение: {coefficients[0]}x + {coefficients[1]} = 0");
                if (coefficients[0] == 0)
                {
                    Console.WriteLine($"- Коэффициент при x равен 0, значит это не линейное уравнение");
                }
                else
                {
                    Console.WriteLine($"- x = -{coefficients[1]} / {coefficients[0]} = {-coefficients[1] / coefficients[0]:F2}");
                }
            }
            else if (coefficients.Length == 3)
            {
                if (coefficients[0] == 0)
                {
                    Console.WriteLine($"- Коэффициент a = 0, поэтому это линейное уравнение");
                }
                else
                {
                    double a = coefficients[0];
                    double b = coefficients[1];
                    double c = coefficients[2];
                    double d = b * b - 4 * a * c;

                    Console.WriteLine($"- Это квадратное уравнение: {a}x^2 + {b}x + {c} = 0");
                    Console.WriteLine($"- Дискриминант D = b² - 4ac = {b}² - 4·{a}·{c} = {d:F2}");

                    if (d < 0)
                    {
                        Console.WriteLine($"- D < 0, поэтому нет действительных корней");
                    }
                    else if (d == 0)
                    {
                        Console.WriteLine($"- D = 0, поэтому один корень: x = -b/(2a) = {-b}/(2·{a}) = {-b / (2 * a):F2}");
                    }
                    else
                    {
                        Console.WriteLine($"- D > 0, поэтому два корня:");
                        Console.WriteLine($"  x₁ = (-b - √D)/(2a) = ({-b} - {Math.Sqrt(d):F2})/(2·{a}) = {(-b - Math.Sqrt(d)) / (2 * a):F2}");
                        Console.WriteLine($"  x₂ = (-b + √D)/(2a) = ({-b} + {Math.Sqrt(d):F2})/(2·{a}) = {(-b + Math.Sqrt(d)) / (2 * a):F2}");
                    }
                }
            }
        }

        static void Task4()
        {
            Console.WriteLine("=== Задача 4: Карточная игра ===\n");
            Console.WriteLine("Правила игры:");
            Console.WriteLine("- У каждого игрока по 3 карты от 1 до 9");
            Console.WriteLine("- Игроки по очереди вскрывают верхние карты");
            Console.WriteLine("- У кого карта больше, забирает обе карты себе");
            Console.WriteLine("- Победитель кладет под низ сначала свою карту, затем карту соперника");
            Console.WriteLine("- Игра идет до 100 ходов максимум\n");

            try
            {
                Console.Write("Введите 3 карты первого игрока (через пробел): ");
                string[] firstInput = Console.ReadLine().Split(' ');

                Console.Write("Введите 3 карты второго игрока (через пробел): ");
                string[] secondInput = Console.ReadLine().Split(' ');

                if (firstInput.Length != 3 || secondInput.Length != 3)
                {
                    Console.WriteLine("Ошибка: нужно ввести ровно 3 карты для каждого игрока");
                    return;
                }

                Queue<int> firstPlayer = new Queue<int>();
                Queue<int> secondPlayer = new Queue<int>();

                Console.WriteLine("\nНачальные колоды:");
                Console.Write("Первый игрок: ");
                for (int i = 0; i < 3; i++)
                {
                    int card = int.Parse(firstInput[i]);

                    if (card < 1 || card > 9)
                    {
                        Console.WriteLine("Ошибка: карты должны быть от 1 до 9");
                        return;
                    }

                    firstPlayer.Enqueue(card);
                    Console.Write(card + " ");
                }
                Console.WriteLine();

                Console.Write("Второй игрок: ");
                for (int i = 0; i < 3; i++)
                {
                    int card = int.Parse(secondInput[i]);

                    if (card < 1 || card > 9)
                    {
                        Console.WriteLine("Ошибка: карты должны быть от 1 до 9");
                        return;
                    }

                    secondPlayer.Enqueue(card);
                    Console.Write(card + " ");
                }
                Console.WriteLine("\n");

                int moves = 0;
                int maxMoves = 100;
                bool gameFinished = false;

                while (moves < maxMoves && !gameFinished)
                {
                    moves++;
                    Console.WriteLine($"Ход {moves}:");

                    if (firstPlayer.Count == 0)
                    {
                        Console.WriteLine($"Второй игрок победил! Первый игрок остался без карт.");
                        Console.WriteLine($"Количество ходов: {moves - 1}");
                        return;
                    }
                    if (secondPlayer.Count == 0)
                    {
                        Console.WriteLine($"Первый игрок победил! Второй игрок остался без карт.");
                        Console.WriteLine($"Количество ходов: {moves - 1}");
                        return;
                    }

                    int firstCard = firstPlayer.Dequeue();
                    int secondCard = secondPlayer.Dequeue();

                    Console.WriteLine($"Первый игрок показывает карту: {firstCard}");
                    Console.WriteLine($"Второй игрок показывает карту: {secondCard}");

                    if (firstCard > secondCard)
                    {
                        Console.WriteLine($"Первый игрок забирает карты!");

                        firstPlayer.Enqueue(firstCard);   
                        firstPlayer.Enqueue(secondCard);  
                    }
                    else if (secondCard > firstCard)
                    {
                        Console.WriteLine($"Второй игрок забирает карты!");

                        secondPlayer.Enqueue(secondCard);
                        secondPlayer.Enqueue(firstCard);  
                    }
                    else
                    {
                        Console.WriteLine($"Ничья! Карты равны, возвращаем их обратно в колоды");

                        firstPlayer.Enqueue(firstCard);
                        secondPlayer.Enqueue(secondCard);
                    }

                    Console.Write("Колода первого игрока: ");
                    if (firstPlayer.Count == 0)
                        Console.Write("пуста");
                    else
                    {
                        foreach (int card in firstPlayer)
                        {
                            Console.Write(card + " ");
                        }
                    }
                    Console.WriteLine();

                    Console.Write("Колода второго игрока: ");
                    if (secondPlayer.Count == 0)
                        Console.Write("пуста");
                    else
                    {
                        foreach (int card in secondPlayer)
                        {
                            Console.Write(card + " ");
                        }
                    }
                    Console.WriteLine("\n");

                    if (firstPlayer.Count == 0)
                    {
                        Console.WriteLine($"Игра окончена! Второй игрок победил!");
                        Console.WriteLine($"Количество ходов: {moves}");
                        gameFinished = true;
                    }
                    else if (secondPlayer.Count == 0)
                    {
                        Console.WriteLine($"Игра окончена! Первый игрок победил!");
                        Console.WriteLine($"Количество ходов: {moves}");
                        gameFinished = true;
                    }
                }

                if (!gameFinished)
                {
                    Console.WriteLine($"Игра не закончилась за {maxMoves} ходов!");
                    Console.WriteLine("Возможно, возник цикл или требуется больше ходов.");
                }
            }
            catch (FormatException)
            {
                Console.WriteLine("Ошибка: введите целые числа");
            }
        }
        static void Task5()
        {
            Console.WriteLine("=== Задача 5: Класс Rectangle (Прямоугольник) ===\n");

            try
            {
                Console.Write("Введите ширину и высоту прямоугольника через пробел (от 1 до 100): ");
                string input = Console.ReadLine();

                string[] parts = input.Split(' ');

                List<string> filteredParts = new List<string>();
                foreach (string part in parts)
                {
                    if (part != "")
                    {
                        filteredParts.Add(part);
                    }
                }

                if (filteredParts.Count != 2)
                {
                    Console.WriteLine("Ошибка: нужно ввести ровно два числа (ширину и высоту)");
                    return;
                }

                int width = int.Parse(filteredParts[0]);
                int height = int.Parse(filteredParts[1]);

                if (width < 1 || width > 100 || height < 1 || height > 100)
                {
                    Console.WriteLine("Ошибка: ширина и высота должны быть от 1 до 100");
                    return;
                }

                Rectangle rect = new Rectangle(width, height);

                Console.WriteLine("\nСоздан объект Rectangle:");
                Console.WriteLine($"Ширина: {rect.Width}");
                Console.WriteLine($"Высота: {rect.Height}");

                int area = rect.GetArea();
                int perimeter = rect.GetPerimeter();

                Console.WriteLine($"\nПлощадь: {area}");
                Console.WriteLine($"Периметр: {perimeter}");
                Console.WriteLine($"Метод ToString(): {rect.ToString()}");
            }
            catch (FormatException)
            {
                Console.WriteLine("Ошибка: введите целые числа");
            }
        }



        static void Task6()
        {
            Console.WriteLine("=== Задача 6: Минимальный путь в таблице ===\n");
            Console.WriteLine("Игрок начинает в левом верхнем углу (0,0) и должен дойти до правого нижнего угла.");
            Console.WriteLine("Двигаться можно только вправо или вниз. В каждой клетке берется еда.\n");

            try
            {
                // Ввод размеров таблицы
                Console.Write("Введите размеры таблицы N и M через пробел: ");
                string[] sizeInput = Console.ReadLine().Split(' ');

                // Фильтруем пустые элементы
                List<string> filteredSize = new List<string>();
                foreach (string s in sizeInput)
                {
                    if (s != "")
                        filteredSize.Add(s);
                }

                if (filteredSize.Count != 2)
                {
                    Console.WriteLine("Ошибка: нужно ввести два числа (N и M)");
                    return;
                }

                int N = int.Parse(filteredSize[0]);
                int M = int.Parse(filteredSize[1]);

                // Проверка размеров
                if (N < 1 || N > 20 || M < 1 || M > 20)
                {
                    Console.WriteLine("Ошибка: N и M должны быть от 1 до 20");
                    return;
                }

                // Создаем таблицу для хранения значений
                int[,] table = new int[N, M];

                // Ввод значений таблицы
                Console.WriteLine($"Введите {N} строк по {M} чисел в каждой (штрафы от 0 до 100):");

                for (int i = 0; i < N; i++)
                {
                    Console.Write($"Строка {i + 1}: ");
                    string[] rowInput = Console.ReadLine().Split(' ');

                    // Фильтруем пустые элементы
                    List<string> filteredRow = new List<string>();
                    foreach (string s in rowInput)
                    {
                        if (s != "")
                            filteredRow.Add(s);
                    }

                    if (filteredRow.Count != M)
                    {
                        Console.WriteLine($"Ошибка: в строке {i + 1} должно быть {M} чисел");
                        return;
                    }

                    for (int j = 0; j < M; j++)
                    {
                        int value = int.Parse(filteredRow[j]);

                        // Проверка значения
                        if (value < 0 || value > 100)
                        {
                            Console.WriteLine("Ошибка: значения должны быть от 0 до 100");
                            return;
                        }

                        table[i, j] = value;
                    }
                }

                // Выводим введенную таблицу
                Console.WriteLine("\nВведенная таблица штрафов:");
                for (int i = 0; i < N; i++)
                {
                    for (int j = 0; j < M; j++)
                    {
                        Console.Write($"{table[i, j],4}");
                    }
                    Console.WriteLine();
                }

                // Создаем таблицу для динамического программирования
                int[,] dp = new int[N, M];

                // Начальная клетка (левый верхний угол)
                dp[0, 0] = table[0, 0];

                // Заполняем первую строку (можно двигаться только вправо)
                for (int j = 1; j < M; j++)
                {
                    dp[0, j] = dp[0, j - 1] + table[0, j];
                }

                // Заполняем первый столбец (можно двигаться только вниз)
                for (int i = 1; i < N; i++)
                {
                    dp[i, 0] = dp[i - 1, 0] + table[i, 0];
                }

                // Заполняем остальные клетки (выбираем минимальный путь сверху или слева)
                for (int i = 1; i < N; i++)
                {
                    for (int j = 1; j < M; j++)
                    {
                        // Минимальная сумма пути до текущей клетки = 
                        // значение в текущей клетке + минимум из верхней и левой клетки
                        int fromTop = dp[i - 1, j];      // путь сверху
                        int fromLeft = dp[i, j - 1];      // путь слева

                        // Выбираем минимальный предыдущий путь
                        int minPrev = Math.Min(fromTop, fromLeft);

                        dp[i, j] = minPrev + table[i, j];
                    }
                }

                // Выводим таблицу динамического программирования
                Console.WriteLine("\nТаблица минимальных путей (DP):");
                for (int i = 0; i < N; i++)
                {
                    for (int j = 0; j < M; j++)
                    {
                        Console.Write($"{dp[i, j],6}");
                    }
                    Console.WriteLine();
                }

                // Результат - значение в правом нижнем углу
                int result = dp[N - 1, M - 1];

                Console.WriteLine($"\nМинимальный вес еды: {result} кг");

                // Восстанавливаем путь для наглядности
                Console.WriteLine("\nОптимальный путь (координаты [ряд,столбец] и штраф):");

                // Создаем список для хранения пути
                List<string> path = new List<string>();

                int row = N - 1;
                int col = M - 1;

                // Идем от конца к началу
                while (row > 0 || col > 0)
                {
                    path.Add($"[{row + 1},{col + 1}] ({table[row, col]})");

                    // Определяем, откуда пришли
                    if (row == 0)
                    {
                        // В первой строке - пришли слева
                        col--;
                    }
                    else if (col == 0)
                    {
                        // В первом столбце - пришли сверху
                        row--;
                    }
                    else
                    {
                        // Сравниваем, откуда выгоднее пришли
                        if (dp[row - 1, col] < dp[row, col - 1])
                        {
                            // Пришли сверху
                            row--;
                        }
                        else
                        {
                            // Пришли слева
                            col--;
                        }
                    }
                }

                // Добавляем стартовую клетку
                path.Add($"[1,1] ({table[0, 0]})");

                // Разворачиваем путь (шли от конца к началу)
                path.Reverse();

                // Выводим путь (исправлено: используем string.Join вместо метода Join)
                Console.WriteLine(string.Join(" -> ", path));

                // Проверяем сумму пути
                int sumCheck = 0;
                foreach (string step in path)
                {
                    // Извлекаем число из строки вида "[1,1] (5)"
                    int startIndex = step.IndexOf('(') + 1;
                    int endIndex = step.IndexOf(')');
                    string numStr = step.Substring(startIndex, endIndex - startIndex);
                    sumCheck += int.Parse(numStr);
                }

                Console.WriteLine($"\nПроверка суммы пути: {sumCheck} кг");

                // Дополнительно: показываем все возможные пути для маленьких таблиц
                if (N <= 3 && M <= 3)
                {
                    Console.WriteLine("\nВсе возможные пути (для наглядности):");
                    FindAllPaths(table, N, M, 0, 0, table[0, 0].ToString(), table[0, 0]);
                }
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

        /// <summary>
        /// Задача 7: Компоненты связности в графе
        /// </summary>
        static void Task7()
        {
            Console.WriteLine("=== Задача 7: Компоненты связности в графе ===\n");

            try
            {
                // Ввод количества вершин и ребер
                Console.Write("Введите количество вершин N и ребер M через пробел: ");
                string[] firstLine = Console.ReadLine().Split(' ');

                // Фильтруем пустые элементы
                List<string> filteredFirst = new List<string>();
                foreach (string s in firstLine)
                {
                    if (s != "")
                        filteredFirst.Add(s);
                }

                if (filteredFirst.Count != 2)
                {
                    Console.WriteLine("Ошибка: нужно ввести два числа (N и M)");
                    return;
                }

                int N = int.Parse(filteredFirst[0]);
                int M = int.Parse(filteredFirst[1]);

                // Проверка ограничений
                if (N <= 0 || N > 100000)
                {
                    Console.WriteLine("Ошибка: N должно быть от 1 до 100000");
                    return;
                }

                if (M < 0 || M > 100000)
                {
                    Console.WriteLine("Ошибка: M должно быть от 0 до 100000");
                    return;
                }

                // Создаем список смежности для графа
                // Используем List<List<int>> для хранения связей
                List<List<int>> graph = new List<List<int>>();
                for (int i = 0; i <= N; i++) // индексация с 1 для удобства
                {
                    graph.Add(new List<int>());
                }

                // Ввод ребер
                Console.WriteLine($"Введите {M} ребер (каждая строка: номер вершины i и номер вершины j):");
                for (int k = 0; k < M; k++)
                {
                    Console.Write($"Ребро {k + 1}: ");
                    string[] edgeLine = Console.ReadLine().Split(' ');

                    // Фильтруем пустые элементы
                    List<string> filteredEdge = new List<string>();
                    foreach (string s in edgeLine)
                    {
                        if (s != "")
                            filteredEdge.Add(s);
                    }

                    if (filteredEdge.Count != 2)
                    {
                        Console.WriteLine($"Ошибка: нужно ввести два числа для ребра {k + 1}");
                        return;
                    }

                    int u = int.Parse(filteredEdge[0]);
                    int v = int.Parse(filteredEdge[1]);

                    // Проверка корректности вершин
                    if (u < 1 || u > N || v < 1 || v > N)
                    {
                        Console.WriteLine($"Ошибка: вершины должны быть от 1 до {N}");
                        return;
                    }

                    // Добавляем ребро в граф (неориентированный граф - добавляем в обе стороны)
                    graph[u].Add(v);
                    graph[v].Add(u);
                }

                // Массив для отслеживания посещенных вершин
                bool[] visited = new bool[N + 1]; // индексация с 1

                // Список для хранения всех компонент связности
                List<List<int>> components = new List<List<int>>();

                // Обходим все вершины
                for (int vertex = 1; vertex <= N; vertex++)
                {
                    if (!visited[vertex])
                    {
                        // Начинаем новую компоненту связности
                        List<int> component = new List<int>();

                        // Используем стек для DFS (обход в глубину)
                        Stack<int> stack = new Stack<int>();
                        stack.Push(vertex);
                        visited[vertex] = true;

                        while (stack.Count > 0)
                        {
                            int current = stack.Pop();
                            component.Add(current);

                            // Добавляем всех соседей, которые еще не посещены
                            foreach (int neighbor in graph[current])
                            {
                                if (!visited[neighbor])
                                {
                                    visited[neighbor] = true;
                                    stack.Push(neighbor);
                                }
                            }
                        }

                        // Добавляем компоненту в список компонент
                        components.Add(component);
                    }
                }

                // Выводим результат
                Console.WriteLine($"\nКоличество компонент связности: {components.Count}");
                Console.WriteLine("\nКомпоненты связности:");

                for (int i = 0; i < components.Count; i++)
                {
                    Console.WriteLine($"\nКомпонента {i + 1}:");
                    Console.WriteLine($"Количество вершин: {components[i].Count}");

                    // Сортируем вершины для красивого вывода
                    components[i].Sort();

                    Console.Write("Вершины: ");
                    for (int j = 0; j < components[i].Count; j++)
                    {
                        Console.Write(components[i][j]);
                        if (j < components[i].Count - 1)
                            Console.Write(" ");
                    }
                    Console.WriteLine();
                }

                // Для больших графов выводим только статистику
                if (N > 50)
                {
                    Console.WriteLine($"\nПримечание: показаны только компоненты (всего {components.Count} шт.)");
                    Console.WriteLine("Для каждой компоненты показано количество вершин:");
                    for (int i = 0; i < components.Count; i++)
                    {
                        Console.WriteLine($"Компонента {i + 1}: {components[i].Count} вершин");
                    }
                }
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

        /// <summary>
        /// Альтернативная версия с использованием BFS (обход в ширину)
        /// </summary>
        static void Task7BFS()
        {
            Console.WriteLine("=== Задача 7: Компоненты связности в графе (BFS) ===\n");

            try
            {
                // Ввод количества вершин и ребер
                Console.Write("Введите количество вершин N и ребер M через пробел: ");
                string[] firstLine = Console.ReadLine().Split(' ');

                // Фильтруем пустые элементы
                List<string> filteredFirst = new List<string>();
                foreach (string s in firstLine)
                {
                    if (s != "")
                        filteredFirst.Add(s);
                }

                if (filteredFirst.Count != 2)
                {
                    Console.WriteLine("Ошибка: нужно ввести два числа (N и M)");
                    return;
                }

                int N = int.Parse(filteredFirst[0]);
                int M = int.Parse(filteredFirst[1]);

                // Создаем список смежности
                List<List<int>> graph = new List<List<int>>();
                for (int i = 0; i <= N; i++)
                {
                    graph.Add(new List<int>());
                }

                // Ввод ребер
                Console.WriteLine($"Введите {M} ребер (каждая строка: i j):");
                for (int k = 0; k < M; k++)
                {
                    Console.Write($"Ребро {k + 1}: ");
                    string[] edgeLine = Console.ReadLine().Split(' ');

                    // Фильтруем пустые элементы
                    List<string> filteredEdge = new List<string>();
                    foreach (string s in edgeLine)
                    {
                        if (s != "")
                            filteredEdge.Add(s);
                    }

                    int u = int.Parse(filteredEdge[0]);
                    int v = int.Parse(filteredEdge[1]);

                    graph[u].Add(v);
                    graph[v].Add(u);
                }

                // Поиск компонент связности с помощью BFS
                bool[] visited = new bool[N + 1];
                List<List<int>> components = new List<List<int>>();

                for (int start = 1; start <= N; start++)
                {
                    if (!visited[start])
                    {
                        // BFS обход
                        Queue<int> queue = new Queue<int>();
                        List<int> component = new List<int>();

                        queue.Enqueue(start);
                        visited[start] = true;

                        while (queue.Count > 0)
                        {
                            int current = queue.Dequeue();
                            component.Add(current);

                            foreach (int neighbor in graph[current])
                            {
                                if (!visited[neighbor])
                                {
                                    visited[neighbor] = true;
                                    queue.Enqueue(neighbor);
                                }
                            }
                        }

                        components.Add(component);
                    }
                }

                // Вывод результатов
                Console.WriteLine($"\nКоличество компонент связности: {components.Count}");

                // Сортируем компоненты по размеру (для наглядности)
                components.Sort((a, b) => b.Count.CompareTo(a.Count));

                for (int i = 0; i < components.Count; i++)
                {
                    components[i].Sort();
                    Console.WriteLine($"\nКомпонента {i + 1} (размер: {components[i].Count}):");
                    Console.WriteLine(string.Join(" ", components[i]));
                }
            }
            catch (Exception ex)
            {
                Console.WriteLine($"Ошибка: {ex.Message}");
            }
        }

        /// <summary>
        /// Задача 8: Кафе и купоны (динамическое программирование)
        /// </summary>
        static void Task8()
        {
            Console.WriteLine("=== Задача 8: Кафе и купоны ===\n");

            try
            {
                // Ввод количества дней
                Console.Write("Введите количество дней N (0-100): ");
                string nInput = Console.ReadLine().Trim();

                int N = int.Parse(nInput);

                // Проверка ограничений
                if (N < 0 || N > 100)
                {
                    Console.WriteLine("Ошибка: N должно быть от 0 до 100");
                    return;
                }

                // Если дней нет, выводим нулевой результат
                if (N == 0)
                {
                    Console.WriteLine("\nМинимальная сумма: 0");
                    Console.WriteLine("Неиспользованных купонов: 0");
                    Console.WriteLine("Использованных купонов: 0");
                    return;
                }

                // Массив стоимостей обедов
                int[] prices = new int[N + 1]; // индексация с 1 для удобства

                Console.WriteLine($"Введите стоимость обеда для каждого из {N} дней:");
                for (int i = 1; i <= N; i++)
                {
                    Console.Write($"День {i}: ");
                    prices[i] = int.Parse(Console.ReadLine().Trim());

                    // Проверка стоимости
                    if (prices[i] < 0 || prices[i] > 300)
                    {
                        Console.WriteLine("Ошибка: стоимость должна быть от 0 до 300");
                        return;
                    }
                }

                // Максимальное количество купонов, которое можно получить за N дней
                int maxCoupons = N; // в худшем случае каждый день получаем купон

                // Таблица динамического программирования
                // dp[i][j] - минимальная стоимость после i дней с j неиспользованными купонами
                int[,] dp = new int[N + 1, maxCoupons + 2];

                // Массив для восстановления пути (откуда пришли)
                Tuple<int, int>[,] prev = new Tuple<int, int>[N + 1, maxCoupons + 2];

                // Инициализация большими числами
                for (int i = 0; i <= N; i++)
                {
                    for (int j = 0; j <= maxCoupons + 1; j++)
                    {
                        dp[i, j] = int.MaxValue / 2; // чтобы избежать переполнения
                    }
                }

                // Начальное состояние: 0 дней, 0 купонов, стоимость 0
                dp[0, 0] = 0;

                // Заполнение таблицы DP
                for (int i = 1; i <= N; i++)
                {
                    for (int j = 0; j <= maxCoupons; j++)
                    {
                        // Если текущее состояние недостижимо, пропускаем
                        if (dp[i - 1, j] == int.MaxValue / 2)
                            continue;

                        int cost = prices[i];

                        // Вариант 1: Покупаем обед за деньги
                        if (cost > 100)
                        {
                            // Если обед дороже 100, получаем купон
                            if (j + 1 <= maxCoupons)
                            {
                                if (dp[i, j + 1] > dp[i - 1, j] + cost)
                                {
                                    dp[i, j + 1] = dp[i - 1, j] + cost;
                                    prev[i, j + 1] = new Tuple<int, int>(i - 1, j);
                                }
                            }
                        }
                        else
                        {
                            // Если обед не дороже 100, купон не получаем
                            if (dp[i, j] > dp[i - 1, j] + cost)
                            {
                                dp[i, j] = dp[i - 1, j] + cost;
                                prev[i, j] = new Tuple<int, int>(i - 1, j);
                            }
                        }

                        // Вариант 2: Используем купон (если есть)
                        if (j > 0)
                        {
                            if (dp[i, j - 1] > dp[i - 1, j])
                            {
                                dp[i, j - 1] = dp[i - 1, j];
                                prev[i, j - 1] = new Tuple<int, int>(i - 1, j);
                            }
                        }
                    }
                }

                // Поиск оптимального состояния после всех дней
                int minCost = int.MaxValue;
                int bestCoupons = -1;

                for (int j = 0; j <= maxCoupons; j++)
                {
                    if (dp[N, j] < minCost)
                    {
                        minCost = dp[N, j];
                        bestCoupons = j;
                    }
                    else if (dp[N, j] == minCost && j > bestCoupons)
                    {
                        // Если стоимость одинаковая, выбираем с бОльшим количеством оставшихся купонов
                        bestCoupons = j;
                    }
                }

                // Восстанавливаем, в какие дни использовались купоны
                List<int> usedCouponDays = new List<int>();
                int currentDay = N;
                int currentCoupons = bestCoupons;

                while (currentDay > 0)
                {
                    Tuple<int, int> previous = prev[currentDay, currentCoupons];
                    int prevDay = previous.Item1;
                    int prevCoupons = previous.Item2;

                    // Если количество купонов уменьшилось, значит в этот день использовали купон
                    if (prevCoupons > currentCoupons)
                    {
                        usedCouponDays.Add(currentDay);
                    }

                    currentDay = prevDay;
                    currentCoupons = prevCoupons;
                }

                // Сортируем дни использования купонов по возрастанию
                usedCouponDays.Sort();

                // Количество использованных купонов
                int usedCount = usedCouponDays.Count;

                // Вывод результатов
                Console.WriteLine($"\nМинимальная сумма: {minCost}");
                Console.WriteLine($"Неиспользованных купонов: {bestCoupons}");
                Console.WriteLine($"Использованных купонов: {usedCount}");

                if (usedCount > 0)
                {
                    Console.WriteLine("Дни использования купонов:");
                    foreach (int day in usedCouponDays)
                    {
                        Console.WriteLine(day);
                    }
                }

                // Дополнительная информация для отладки
                Console.WriteLine("\nДетализация по дням:");
                int sum = 0;
                int coupons = 0;

                for (int i = 1; i <= N; i++)
                {
                    if (usedCouponDays.Contains(i))
                    {
                        Console.WriteLine($"День {i}: использован купон (бесплатно)");
                        coupons--;
                    }
                    else
                    {
                        sum += prices[i];
                        if (prices[i] > 100)
                        {
                            Console.WriteLine($"День {i}: куплен за {prices[i]} руб. (получен купон)");
                            coupons++;
                        }
                        else
                        {
                            Console.WriteLine($"День {i}: куплен за {prices[i]} руб.");
                        }
                    }
                }

                Console.WriteLine($"\nПроверка: итоговая сумма = {sum}, оставшиеся купоны = {coupons}");
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

        /// <summary>
        /// Упрощенная версия для класса Tuple (если используется старая версия C#)
        /// </summary>
        public class Tuple<T1, T2>
        {
            public T1 Item1 { get; private set; }
            public T2 Item2 { get; private set; }

            public Tuple(T1 item1, T2 item2)
            {
                Item1 = item1;
                Item2 = item2;
            }
        }

        /// <summary>
        /// Вспомогательный класс для создания кортежей
        /// </summary>
        public static class Tuple
        {
            public static Tuple<T1, T2> Create<T1, T2>(T1 item1, T2 item2)
            {
                return new Tuple<T1, T2>(item1, item2);
            }
        }

        /// <summary>
        /// Вспомогательный метод для поиска всех путей (только для небольших таблиц)
        /// </summary>
        static void FindAllPaths(int[,] table, int N, int M, int row, int col, string path, int sum)
        {
            // Если дошли до правого нижнего угла
            if (row == N - 1 && col == M - 1)
            {
                Console.WriteLine($"Путь: {path} = {sum}");
                return;
            }

            // Двигаемся вправо
            if (col + 1 < M)
            {
                FindAllPaths(table, N, M, row, col + 1,
                    path + $" -> [{row + 1},{col + 2}] ({table[row, col + 1]})",
                    sum + table[row, col + 1]);
            }

            // Двигаемся вниз
            if (row + 1 < N)
            {
                FindAllPaths(table, N, M, row + 1, col,
                    path + $" -> [{row + 2},{col + 1}] ({table[row + 1, col]})",
                    sum + table[row + 1, col]);
            }
        }

    }


    class Rectangle ///////////////////////////////////////////////////////////////////////////////
    {
        public int Width { get; set; }
        public int Height { get; set; }

        public Rectangle(int width, int height)
        {
            Width = width;
            Height = height;
        }


        public int GetArea()
        {
            return Width * Height;
        }

        public int GetPerimeter()
        {
            return 2 * (Width + Height);
        }

        public override string ToString()
        {
            return $"Rectangle {Width}x{Height}";
        }
    } /////////////////////////////////////////////////////////////////////////////////////////////


}