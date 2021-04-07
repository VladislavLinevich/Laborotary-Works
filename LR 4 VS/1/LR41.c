#pragma hdrstop
#pragma argsused

#include <stdio.h>
#include <string.h>
#include <conio.h>

#ifdef _WIN32
#include <tchar.h>
#else
  typedef char _TCHAR;
  #define _tmain main
#endif

int _tmain(int argc, _TCHAR* argv[])
{
	char a[81];
	char b[200];
	int k, t;

	for (int i = 0; i < 199; i++) {
		b[i] = ' ';
	}
    b[199] = '\0';

	k = 40;
	t = 0;
    printf("Enter string\n");
	fgets(a, 81, stdin);

	for (int i = 0; i < strlen(a); i++) {
		if ((i + 1) % 2 != 0 && i > 0) {  //При каждом нечетном номере > 1 сдвигаем все элементы влево на 1
			for (int j = t; j > 0; j--) {
				b[k - j - 1] = b[k - j];
			}
			k--;
			b[k] = a[i];  //Записывем элемент после внесенных символов
		}
		else {
			b[k] = a[i];
		}
		k++;
		t++;
	}
	puts(b);

	getch();
	return 0;
}