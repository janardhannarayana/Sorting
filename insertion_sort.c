#include <stdio.h>
#include <stdlib.h>

#define MAX_ARRAY 1000

void insertion_sort(int *a);
void swap(int *x, int *y);

void insertion_sort(int *a)
{
    int i = 0;
    int j = 0;
    
    for (i = 1; i < MAX_ARRAY; i++) {
	for(j = i; j > 0; j--) {
	    if (a[j] < a[j-1])
		swap(&a[j], &a[j-1]);
	}
    }
}

void swap(int *x, int *y)
{
    *x = *x + *y;
    *y = *x - *y;
    *x = *x - *y;
}


int main()
{
    int a[MAX_ARRAY];
    int i = 0;
    
    for(i = 0; i < MAX_ARRAY; i++) {
	a[i] = rand()%100000;
	printf("%d\t",a[i]);
    }
    printf("\nSORTED ARRAY\n");
    insertion_sort(a);
    for(i = 0; i < MAX_ARRAY; i++) {
	printf("%d\t",a[i]);
    }
    printf("\n");
    return 0;
}
