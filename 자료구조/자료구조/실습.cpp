#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main() {
	int n;
	scanf("%d", &n);

	int* arr= (int *)malloc(sizeof(int) * n); //10 이면 40바이트 할당

	srand(time(NULL));

	for (int i = 0; i < n; i++)
		arr[i] = rand() % 100;
	
	for (int i = 0; i < n; i++)
		printf("%d ", *(arr + (2*i)));

}