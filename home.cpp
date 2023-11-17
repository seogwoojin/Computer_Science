#include<stdio.h>

int main()
{
    int k,n,m;

    scanf("%d %d %d", &k, &n, &m);
    if(n*k<=m){
        printf("0");
    }
    else{
        printf("%d", n*k-m);
    }
    return 0
}