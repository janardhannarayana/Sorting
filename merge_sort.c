#include <stdio.h>
#include <stdlib.h>

#define MAX_ARRAY 5

void merge_sort(int *a, int start, int end);
void merge(int *a, int start, int mid, int end);

void merge(int *a, int start, int mid, int end)
{
  int temp[end - start + 1];

  int i = start;
  int j = mid + 1;
  int k =0;

  while( i <= mid && j <= end) {
    if (a[i] <= a[j]) {
      temp[k] = a[i];
      i++;
      k++;
    } else if (a[i] > a[j]) {
      temp[k] = a[j];
      j++;
      k++;      
    }
  }

  while(i <= mid) {
    temp[k] = a[i];
    i++;
    k++;
  }

  while(j <= end) {
    temp[k] = a[j];
    j++;
    k++;
  }
  for(i = start; i <= end;i++) {
    a[i] = temp[i];
  }
  return;
}

void merge_sort(int *a, int start, int end)
{
  if (start < end) {
    int mid = (start + end)/2;
    merge_sort(a, start, mid);
    merge_sort(a, mid+1, end);
    merge(a, start, mid, end);
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
    merge_sort(a, 0, MAX_ARRAY - 1);
    for(i = 0; i < MAX_ARRAY; i++) {
	printf("%d\t",a[i]);
    }
    printf("\n");
    return 0;
}
