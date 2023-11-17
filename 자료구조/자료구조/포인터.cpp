#include <stdio.h>
typedef struct _TEST_T {
	int i;
	short s;
	short t;
	int k;


}TEST_T;
int main(void) {
	printf("size of TEST_T: %d\n", sizeof(TEST_T));
	return 0;
}