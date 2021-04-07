
#include <stdio.h>
#include <conio.h>

#ifdef _WIN32
#include <tchar.h>
#else
  typedef char _TCHAR;
  #define _tmain main
#endif

#include <malloc.h>
#include <stdlib.h>
#include <ctime>

void print(int **a,int  n){   //Вывод лабиринта
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			printf("%d ", a[i][j]);
		}
		printf("\n");
	}
}

int _tmain()
{
		int **a, **b;
	int c, n, t, k, temp;

	printf(" Enter n (> 3 and <31) = ");
	scanf("%d", &n);
	while (n <= 2 || n > 30) {
		printf("Enter n (> 3 and <31) = ");
		scanf("%d", &n);
	}
	
	a = (int**)malloc(n *  sizeof(int*));
	for (int i = 0; i < n; i++) {
		a[i] = (int*)malloc(n * sizeof(int));
	}

	b = (int**)malloc(n *  sizeof(int*));
	for (int i = 0; i < n; i++) {
		b[i] = (int*)malloc(n * sizeof(int));
	}

	for (int i = 0; i < n; i++) {   //Массив для вывода пути
		for (int j = 0; j < n; j++) {
			b[i][j] = 1;
		}
	}

	srand(time(0));

	for (int i = 0; i < n; i++) {     //Генерируем лабиринт
		for (int j = 0; j < n; j++) {
			a[i][j] = rand() % 2;
		}
	}

	do {              //Генерируем рандомом место положение путника(не на границе лабиринта)
		t = 1 + rand() % ((n - 2) - 1 + 1 );
		k = 1 + rand() % ((n - 2) - 1 + 1 );
		if (n == 3 && a[1][1] == 1) {
			printf("Maze impossible");
			getch();
			return 0;
		}
	}
	while (a[t][k] != 0);

	b[t][k] = -4;//Начало пути(-4 - это путник)
	a[t][k] = -4;

	printf("\n");
	print(&(*a), n);
	printf("\n");

	if (a[t - 1][k] == 1 && a[t][k - 1] == 1 && a[t + 1][k] == 1 && a[t][k + 1] == 1)  { //Использование метода "волны" для возможных путей
		printf("Maze impossible");
		return 0;	
	}


	if (a[t - 1][k] == 0) { //Использование метода "волны" для возможных путей
		a[t - 1][k] = 2;
		c = 2;
	}
	if (a[t][k - 1] == 0) {
		a[t][k - 1] = 2;
		c = 2;
	}
	if (a[t + 1][k] == 0) {
		a[t + 1][k] = 2;
		c = 2;
	}
	if (a[t][k + 1] == 0) {
		a[t][k + 1] = 2;
		c = 2;
	}
	for (int f = 0; f < 800; f++){
		for (int i = 1; i < n - 1; i++) {
			for (int j = 1; j < n - 1; j++) {
				if (a[i][j] == c ) {
					if (a[i - 1][j] == 0) {
						a[i - 1][j] = ++c;
						c--;
					}
					if (a[i][j - 1] == 0) {
						a[i][j - 1] = ++c;
						c--;
					}
					if (a[i + 1][j] == 0) {
						a[i + 1][j] = ++c;
						c--;
					}
					if (a[i][j + 1] == 0) {
						a[i][j + 1] = ++c;
						c--;
					}
				}
			}
		}
		c++;
	}

	temp = 1;
	for (int l = 0; l < n; l++) { //Проверка есть ли у лабиринта выход
		if (a[0][l] > temp) {
			temp = a[0][l];
			t = 0;
			k = l;
			break;
		}
	}
	if (temp == 1) {
		for (int m = 0; m < n; m++) {
			if (a[m][n - 1] > temp) {
				temp = a[m][n - 1];
				t = m;
				k = n - 1;
				break;
			}
		}
	}
	if (temp == 1) {
		for (int v = 0; v < n; v++) {
			if (a[n - 1][v] > temp) {
				temp = a[n - 1][v];
				t = n - 1;
				k = v;
				break;
			}
		}
	}
	if (temp == 1) {
		for (int q = 0; q < n; q++) {
			if (a[q][0] > temp) {
				temp = a[q][0];
				t = q;
				k = 0;
				break;
			}
		}
	}

	if (temp == 1) {
		printf("Maze impossible");
        getch();
		return 0;
	} 
	else {   
		printf("Maze possible\n");
		for (int l = 0; l < n; l++) {//Есди выход есть, то находим координаты выхода
			if (a[0][l] < temp && a[0][l] > 1) {
				temp = a[0][l];
				t = 0;
				k = l;
			}
		}
		for (int m = 0; m < n; m++) {
			if (a[m][n - 1] < temp && a[m][n - 1] > 1) {
				temp = a[m][n - 1];
				t = m;
				k = n - 1;
			}
		}
		for (int v = 0; v < n; v++) {
			if (a[n - 1][v] < temp && a[n - 1][v] > 1) {
				temp = a[n - 1][v];
				t = n - 1;
				k = v;
			}
		}
		for (int q = 0; q < n; q++) {
			if (a[q][0] < temp && a[q][0] > 1) {
				temp = a[q][0];
				t = q;
				k = 0;
			}
		}
	}

	b[t][k] = temp;//Переносим кратчайший путь
	while (temp > 2){
		if (a[t - 1][k] == temp - 1) {
			b[t - 1][k] = temp - 1;
			t = t - 1;
			temp--;
			continue;
		}
		if (a[t][k - 1] == temp - 1) {
			b[t][k - 1] = temp - 1;
			k = k - 1;
			temp--;
			continue;
		}
		if (a[t + 1][k] == temp - 1) {
			b[t + 1][k] = temp - 1;
			t = t + 1;
			temp--;
			continue;
		}
		if (a[t][k + 1] == temp - 1) {
			b[t][k + 1] = temp - 1;
            k = k + 1;
			temp--;
			continue;
		}
	}

	for (int i = 0; i < n; i++) {//Выводим кратчайший путь
		for (int j = 0; j < n; j++) {
			printf("%d ", b[i][j]);
		}
		printf("\n");
	}

	for (int i = 0; i < n; i++){
		free(a[i]);
	}
	free(a);
	for (int i = 0; i < n; i++){
		free(b[i]);
	}
	free(b);

	getch();
	return 0;
}