#include <stdio.h>

/* 1. 初始建堆 */
void build_heap(int A[], int len);
/* 2. 将以k为根的子树调整为大根堆 */
void heap_adjust(int A[], int k, int len);
/* 3. 堆排序的完整逻辑 */
void heap_sort(int A[], int len);


int main(void)
{
  int A[] = { 0, 3, 2, 1, 6, 10, 7, 8, 4, 9, 5 };
  heap_sort(A, 10);
  for (int i = 1; i != 11; ++i)
    printf("%d ", A[i]);
  printf("\n");

  return 0;
}

void build_heap(int A[], int len)
{
  for (int i = len / 2; i > 0; --i)
    heap_adjust(A, i, len);
}

void heap_adjust(int A[], int k, int len)
{
  A[0] = A[k];
  for (int i = 2*k; i <= len; i *= 2) {
    if (i < len && A[i] < A[i+1])
      ++i;
    if (A[0] >= A[i])
      break;
    else {
      A[k] = A[i];
      k = i;
    }
  }
  A[k] = A[0];
}

void swap(int *a, int *b)
{
  int temp = *a;
  *a = *b;
  *b = temp;
}

void heap_sort(int A[], int len)
{
  build_heap(A, len);

  for (int i = len; i > 1; --i)
  {
    swap(&A[i], &A[1]);
    heap_adjust(A, 1, i - 1);
  }
}
