#pragma hdrstop
#pragma argsused

#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <stdlib.h>

#ifdef _WIN32
#include <tchar.h>
#else
  typedef char _TCHAR;
  #define _tmain main
#endif

void SetMass(int *m){
	scanf("%d", &(*m));
}

void SetRadius(int *r)
{
	scanf("%d", &(*r));
}

void SetSpeed(int *s)
{
	scanf("%d", &(*s));
}

float YearLength(int r, int s)
{
	return ((2 * 3.14 * r) / s)/24;
}

float DistanceBetweenPlanets(int r1, int r2, int v1, int v2, int t)
{
	int s1, s2;
	s1 = v1 * t;
	s2 = v2 * t;
	return sqrt(pow(abs(r2 - r1), 2) + pow(abs(s2 - s1), 2));
}

float GravitationalForce(int m1, int m2, float G, int r)
{
	return G * m1 * m2 / pow(r, 2);
}

void finish()
{
	exit(0);
}


int _tmain(int argc, _TCHAR* argv[])
{
	int E2G_1m, E2G_1r, E2G_1s, E2G_2m, E2G_2r, E2G_2s, E2G_3m, E2G_3r, E2G_3s, t;
	float E2G_1year, E2G_2year, E2G_3year, s12, s13, s23, F12, F13, F23;
	char k;
	const float G = 6.67 * pow(10.0, -11);

	printf("E2G_1 mass(kg) = ");
	SetMass(&E2G_1m);
	printf("E2G_1 radius(km) = ");
	SetRadius(&E2G_1r);
	printf("E2G_1 speed(km/h) = ");
	SetSpeed(&E2G_1s);

	printf("\nE2G_2 mass(kg) = ");
	SetMass(&E2G_2m);
	printf("E2G_2 radius(km) = ");
	SetRadius(&E2G_2r);
	printf("E2G_2 speed(km/h) = ");
	SetSpeed(&E2G_2s);

	printf("\nE2G_3 mass(kg) = ");
	SetMass(&E2G_3m);
	printf("E2G_3 radius(km) = ");
	SetRadius(&E2G_3r);
	printf("E2G_3 speed(km/h) = ");
	SetSpeed(&E2G_3s);

	for (; ; ) {
		printf("Choose: 1) Enter, 2) Length of the year, 3) Distance between planets after time t, 4) Gravitational force, 5) Exit\n");
		scanf("%s", &k);
		while(k != '1' && k != '2' && k != '3' && k != '4' && k != '5')
		{
			printf("\nEnter a correct number\n");
			scanf("%s", &k);
		}
		if (k == '1') {
			printf("E2G_1 mass(kg) = ");
			SetMass(&E2G_1m);
			printf("E2G_1 radius(km) = ");
			SetRadius(&E2G_1r);
			printf("E2G_1 speed(km/h) = ");
			SetSpeed(&E2G_1s);

			printf("\nE2G_2 mass(kg) = ");
			SetMass(&E2G_2m);
			printf("E2G_2 radius(km) = ");
			SetRadius(&E2G_2r);
			printf("E2G_2 speed(km/h) = ");
			SetSpeed(&E2G_2s);

			printf("\nE2G_3 mass(kg) = ");
			SetMass(&E2G_3m);
			printf("E2G_3 radius(km) = ");
			SetRadius(&E2G_3r);
			printf("E2G_3 speed(km/h) = ");
			SetSpeed(&E2G_3s);
		}
		if (k == '2') {
			E2G_1year = YearLength(E2G_1r, E2G_1s);
			printf("\nE2G_1 length of the year(in the Earth days) = %f", E2G_1year);
			E2G_2year = YearLength(E2G_2r, E2G_2s);
			printf("\nE2G_2 length of the year(in the Earth days) = %f", E2G_2year);
			E2G_3year = YearLength(E2G_3r, E2G_3s);
			printf("\nE2G_3 length of the year(in the Earth days) = %f\n", E2G_3year);
		}
		if (k == '3') {
            printf("\nEnter t(h) = ");
			scanf("%d", &t);

			s12 = DistanceBetweenPlanets(E2G_1r, E2G_2r, E2G_1s, E2G_2s, t);
			printf("\nDistance between planet 1 and planet 2 = %f km", s12);
			s13 = DistanceBetweenPlanets(E2G_1r, E2G_3r, E2G_1s, E2G_3s, t);
			printf("\nDistance between planet 1 and planet 3 = %f km", s13);
			s23 = DistanceBetweenPlanets(E2G_2r, E2G_3r, E2G_2s, E2G_3s, t);
			printf("\nDistance between planet 2 and planet 3 = %f km\n", s23);
		}
		if (k == '4') {
            F12 = GravitationalForce(E2G_1m, E2G_2m, G, s12);
			printf("\nGravitational force between planet 1 and planet 2 = %.15f N", F12);
			F13 = GravitationalForce(E2G_1m, E2G_3m, G, s13);
			printf("\nGravitational force between planet 1 and planet 3 = %.15f N", F13);
			F23 = GravitationalForce(E2G_2m, E2G_3m, G, s23);
			printf("\nGravitational force between planet 2 and planet 3 = %.15f N\n", F23);
		}
		if (k == '5') {
			finish();
		}
	}
	getch();
}