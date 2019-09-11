/*
 * Find the minimum in entire set and place it in appropriate place.
 * Ex: Find minimum from full array and keep it in 0th index.
 *     Find minimum from full array except 0th index  and keep it in 1st index.
 */

#include <stdio.h>
#include <stdlib.h>

#define MAX_ARRAY 1000

void swap(int *x, int *y);
void selection_sort(int *a);

void swap(int *x, int *y)
{
    *x = *x + *y;
    *y = *x - *y;
    *x = *x - *y;
}

void selection_sort(int *a)
{
    int i = 0;
    int j = 0;
    int min = 0;

    for (i = 0; i < MAX_ARRAY;i++){
	min = i;
	for(j = i + 1; j < MAX_ARRAY; j++) {
	    if (a[min] > a[j])
		min = j;
	}
	if (min != i)
	    swap(&a[i],&a[min]);
    }
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
    selection_sort(a);
    for(i = 0; i < MAX_ARRAY; i++) {
	printf("%d\t",a[i]);
    }
    printf("\n");
    return 0;
}
