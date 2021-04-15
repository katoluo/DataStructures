#include <stdio.h>

// 不带哨兵
void Insert_sort_one(int A[], int len);
// 带哨兵
void Insert_sort_two(int A[], int len);

int main(void)
{
  int A[] = { 0, 5, 3, 1, 4, 2 };


  return 0;
}


void Insert_sort_one(int A[], int len)
{
}

void Insert_sort_two(int A[], int len)
{
  int i, j;
  for (i = 2; i <= len; ++i)
  {
    if (A[i] < A[i-1])
    {
      A[0] = A[i];
      for (j = i-1; A[0] < A[j]; --j)
        A[j+1] = A[j];
      A[j+1] = A[0];
    }
  }
}
