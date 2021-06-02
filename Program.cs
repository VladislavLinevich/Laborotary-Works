using System;

namespace LR7
{
    class Program
    {
        static void Main(string[] args)
        {
            Rational[] rationals = new Rational[3];
            rationals[0] = new Rational(3, 2);
            rationals[1] = new Rational(2, 4);
            rationals[2] = new Rational(1, 3);
            Console.WriteLine("Ariphmetics operations");
            Console.WriteLine($"{rationals[0]} + {rationals[1].ToString("D")}   ");
            rationals[0] = rationals[0] + rationals[1];
            Console.WriteLine(rationals[0]);
            Console.WriteLine($"{rationals[0]} - {rationals[1].ToString("D")}   ");
            rationals[0] = rationals[0] - rationals[1];
            Console.WriteLine(rationals[0]);
            Console.WriteLine($"{rationals[0]} * {rationals[1].ToString("D")}   ");
            rationals[0] = rationals[0] * rationals[1];
            Console.WriteLine(rationals[0]);
            Console.WriteLine($"{rationals[0]} / {rationals[1].ToString("D")}   ");
            rationals[0] = rationals[0] / rationals[1];
            Console.WriteLine(rationals[0]);

            Console.WriteLine("Comparison operators");
            Console.WriteLine(new Rational(3, 4) > new Rational(2, 3));
            Console.WriteLine(new Rational(5, 6) <= new Rational(1, 6));
            Console.WriteLine(new Rational(1, 2) == new Rational(2, 4));
            Console.WriteLine(new Rational(3, 4) != new Rational(6, 8));

            Console.WriteLine("Converting to string in different formats");
            Rational testing = new Rational(-5, 2);
            Console.WriteLine(testing.ToString("F"));
            Console.WriteLine(testing.ToString("D"));
            Console.WriteLine(testing.ToString("IF"));
            Console.WriteLine(testing.ToString("I"));

            Console.WriteLine("Conversion operators and implementation of IConvertible");
            Console.WriteLine((int)testing);
            Console.WriteLine((double)testing);
            Console.WriteLine(Convert.ToBoolean(testing));
            Console.WriteLine(Convert.ToString(testing));
             Console.WriteLine("Sorting by using IComparable interface");
             Array.Sort(rationals);
             foreach (var x in rationals)
             {
                 Console.WriteLine(x);
             }

            Console.WriteLine("Division by zero exception");
            try
            {
                new Rational(2, 0);
            }
            catch (ArgumentException ex)
            {
                Console.WriteLine(ex.Message);
            }
            Console.WriteLine("Unsupported ToString() format exception");
            try
            {
                testing.ToString("Unsupported format");
            }
            catch (FormatException ex)
            {
                Console.WriteLine(ex.Message);
            }
        }

    }
}
