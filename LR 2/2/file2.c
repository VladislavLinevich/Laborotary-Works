#pragma hdrstop
#pragma argsused

#include <stdio.h>
#include <conio.h>
#include <math.h>

#ifdef _WIN32
#include <tchar.h>
#else
  typedef char _TCHAR;
  #define _tmain main
#endif

double fact(unsigned long int a) { //Вычисление факториала
	if (a <= 1) {
		return 1;
	}
	else {
		return a * fact(a - 1);
	}
}

double iterative(unsigned long int x, unsigned long int n) {// Итеративная функция вычисления ряда
	double a;

	a = 0;
	for (double i = 1; i <= n; i++) {
		a = a + pow(-1, i - 1) * pow(x, 2 * i - 1) / fact(2 * i - 1);
	}

	return a;

}

void DifferenceIterative(double e, unsigned long int x) {//Меньше ли sin(x) минус его разложение чем заданная погрешность е(через итеративную функцию)
	for (unsigned long int i = 1; i < 100; i++) {
		if ( e > fabs(sin(x) - iterative(x, i))) {
			printf("n = %0.lu\n", i);
			break;
		}
	}
}

double recursion(unsigned long int x, unsigned long int n){// рекурсивная функция вычисления ряда
	if (n == 1) {
		return x;
	}
	else {
		return recursion(x, n - 1) + pow(-1, n - 1) * pow(x, 2 * n - 1) / fact(2 * n - 1);
    }

}

void DifferenceRecursion(double e, unsigned long int x){//Меньше ли sin(x) минус его разложение чем заданная погрешность е(через рекурсивную функцию)
	for (unsigned long int i = 1; i < 100; i++) {
		if ( e > fabs(sin(x) - recursion(x, i))) {
			printf("n = %0.lu\n", i);
			break;
		}
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	unsigned long int x, n;
	double e;

	printf("Enter x = ");//Ввод Х для функции и ряда
	scanf("%lu", &x);

	printf("Enter n = ");//Ввод количества слагаемых для ряда
	scanf("%lu", &n);
		
	printf("\n1. Iterative\nsin(x) = %lf", sin(x));//Вычисление sin(x)
	printf("\nThe sum of the series = %lf", iterative(x, n));//Вычисления суммы ряда через итерации

	printf("\nEnter e = ");//Ввод погрешности
	scanf("%lf", &e);
	DifferenceIterative(e, x);//Меньше ли sin(x) минус его разложение чем заданная погрешность е(через итеративную функцию)

	printf("\n2. Recursion\nsin(x) = %lf", sin(x));
	printf("\nThe sum of the series = %lf\n", recursion(x, n));//Вычисления суммы ряда через рекурсию
	DifferenceRecursion(e, x);//Меньше ли sin(x) минус его разложение чем заданная погрешность е(через рекурсивную функцию)
	
	getch();
	return 0;
}