/*
 * Take the element from the unsorted array and search the right spot
 * in sorted array and insert.
 * Ex: initially complete array is unsorted.
 *     Lets assume the first element as sorted and remiaining as unsorted.
 *     For the first iteration take the second element(which is from unsorted array)
 *     and compare with first element (sorted array) and insert.
 *     Now element 1 and 2 are sorted array and remaining elements are unsorted array
 *     For the second iteration take the first element from unsorted array and compare
 *     with elements from sorted array (1 & 2 in this case) and insert appropriately.
 *
 */

#include <stdio.h>
#include <stdlib.h>

#define MAX_ARRAY 1000

void insertion_sort(int *a);
void swap(int *x, int *y);

void insertion_sort(int *a)
{
    int i = 0;
    int j = 0;
    int key = 0;
    
    for (i = 1; i < MAX_ARRAY; i++) {
	key = a[i];
	for(j = i-1; j >= 0 && (a[j] > key); j--) {
	    a[j + 1] = a[j];
	    a[j] = key;
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
