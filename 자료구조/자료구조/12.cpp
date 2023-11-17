#include<stdio.h>
#include<time.h>


void swap(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}
int main() {
	int a = 1, b = 20;
	swap(&a, &b);

	printf("%d %d\n", a, b);
	int lst[5] = {1,2,3,4};
	lst[5] = 10;
	printf("%d", sizeof(lst)/sizeof(int));
	return 0;
}