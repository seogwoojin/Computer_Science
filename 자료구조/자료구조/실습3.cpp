#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

typedef struct {
	int coef;
	int degree;
} Poly;



int main() {
	int a = 2;
	Poly terms[6] = { {8,3},{7,1},{1,0},{10,3},{3,2},{1,0} };

	printf("%d %d", terms[0].coef, terms[0].degree);

}