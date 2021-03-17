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

int _tmain(int argc, _TCHAR* argv[])
{
	int ed, des, sot;

	printf("Chisla ravnie summe kubov svoih chisel = ");
	for (int i = 100; i < 1000; i++) {
		ed = (i % 100) % 10;
		des = ((i % 100) - ed) / 10;
		sot = (i - des - ed) / 100;
		if (pow(ed, 3) + pow(des, 3) + pow(sot, 3) == i) {
			printf("%d ", i);
		}
	}
	getch();
	return 0;
}