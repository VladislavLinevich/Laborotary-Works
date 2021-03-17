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

double fact(unsigned long int a)
{
	if (a <= 1) {
		return 1;
	}
	else {
		return a * fact(a - 1);
	}
}

double iterative(unsigned long int x, unsigned long int n)
{
	double a;

	a = 0;
	for (double i = 1; i <= n; i++) {
		a = a + pow(-1, i - 1) * pow(x, 2 * i - 1) / fact(2 * i - 1);
	}
	return a;

}

void DifferenceIterative(double e, unsigned long int x)
{
	for (unsigned long int i = 1; i < 100; i++) {
		if ( e > fabs(sin(x) - iterative(x, i))) {
			printf("n = %0.lu\n", i);
			break;
		}
	}
}

double recursion(unsigned long int x, unsigned long int n)
{
	if (n == 1) {
		return x;
	}
	else {
		return recursion(x, n - 1) + pow(-1, n - 1) * pow(x, 2 * n - 1) / fact(2 * n - 1);
    }

}

void DifferenceRecursion(double e, unsigned long int x)
{
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

	printf("Enter x = ");
	scanf("%lu", &x);
	printf("Enter n = ");
	scanf("%lu", &n);
	printf("\n1. Iterative\nsin(x) = %lf", sin(x));
	printf("\nThe sum of the series = %lf", iterative(x, n));
	printf("\nEnter e = ");
	scanf("%lf", &e);
	DifferenceIterative(e, x);
	printf("\n2. Recursion\nsin(x) = %lf", sin(x));
	printf("\nThe sum of the series = %lf\n", recursion(x, n));
	DifferenceRecursion(e, x);
	getch();
	return 0;
}