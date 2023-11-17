#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

typedef struct {
	int degree;
	float coef[10];
} Poly;


void print(Poly p) {
	int c, e;
	e = p.degree;
	for (c = 0; c <= p.degree; c++, e--) {
		printf("%2fx^%d +", p.coef[c], e);
	}
}

int main() {
	Poly a, b, c;

	scanf("%d %d", &a.degree, &b.degree);

	for (int i = 0; i <= a.degree; i++)
		scanf("%f", (a.coef+i));


	print(a);

}