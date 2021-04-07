#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

int _tmain() 
{
	FILE *fp;
	char alphabet[26] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
	char Text[200];
	int quantity[26];//Массив кол-ва каждой строчной буквы находящейся в тексте
	int k,t,max;

	for (int i = 0; i < 26; i++) {
		quantity[i] = 0;
	}

	fp = fopen("C:\\OAIP\\Ctext.txt", "r");
	if (!fp) {                         //Проверка файла
		printf("File not found");
        getch();
		return 0;
	}

	while (fgets(Text, 200, fp) != NULL){ //Считываем текстовый файл
		for (int i = 0; i < strlen(Text); i++) {
			for (int j = 0; j < 26; j++) {
				if (Text[i] == alphabet[j]) {
					quantity[j]++;//Считаем кол-во каждой буквы
				}
			}
		}
	}

	max = quantity[0];
	for (int i = 1; i < 26; i++) {//находим макс. элемент
		if (quantity[i] > max) {
			max = quantity[i];
		}
	}

	char Gisto[max + 1][27];
	for (int i = 0; i < max + 1; i++) {
		for (int j = 0; j < 27; j++) {
			Gisto[i][j] = ' ';
		}
	}

	t = max;
	for (int i = 0; i < max; i++) {//Заполняем вертикальный столбец от 1 до макс. элемента
		Gisto[i][0] = t + '0';
		t--;
	}

	for (int i = 1; i < 27; i++) {//записываем в последнюю строку буквы
		Gisto[max][i] = alphabet[i - 1];
	}

	k = 1;
	for (int i = 0; i < 26; i++) {     //заполняем гистограмму
		if (quantity[i] != 0) {
			for (int j = max - 1; j > max - 1 - quantity[i]; j--) {
				Gisto[j][k] = '|';
			}
		}
		k++;
	}

	for (int i = 0; i < max + 1; i++) {   //Вывод гистограмыы
		for (int j = 0; j < 27; j++) {
			printf("%c", Gisto[i][j]);
		}
		printf("\n");
	}

	fclose(fp);
	getch();
	return 0;
}