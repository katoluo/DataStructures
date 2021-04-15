#include <stdio.h>
#include <stdlib.h>

// 建立大根堆
void BuildMaxHeap(int A[], int len);
// 将以k为根的子树调整为大根堆
void HeadAdjust(int A[], int k, int len);
// 堆排序的完整逻辑
void HeapSort(int A[], int len);
void swap(int *a, int *b);


int main(void)
{
  int A[11] = { 0, 1, 3, 10, 2, 4, 9, 6, 5, 7, 8 };
  HeapSort(A, 10);

  for (int i = 1; i != 11; ++i)
    printf("%d ", A[i]);
  printf("\n");

  return EXIT_SUCCESS;
}


void BuildMaxHeap(int A[], int len)
{
  for (int i = len / 2; i > 0; --i) // 从后往前调整所有非终端结点
    HeadAdjust(A, i, len);
}

void HeadAdjust(int A[], int k, int len)
{
  A[0] = A[k];  // A[0]暂存子树的根结点
  for (int i = 2*k; i <= len; i *= 2) { // 沿key较大的字节点向下筛选
    if (i < len && A[i] < A[i+1])
      ++i;  // 右结点大于左结点，取右结点的下标
    if (A[0] >= A[i]) // 筛选结束
      break;
    else {
      A[k] = A[i]; // 将A[i]调整到双亲结点上
      k = i; // 修改k值，以便继续向下筛选
    }
  }
  A[k] = A[0]; // 被筛选结点的值放入最终位置
}

void swap(int *a, int *b)
{
  int temp = *a;
  *a = *b;
  *b = temp;
}

void HeapSort(int A[], int len)
{
  BuildMaxHeap(A, len);     // 初始建堆
  for (int i = len; i > 1; --i) {
    swap(&A[i], &A[1]);   // 堆顶元素和堆底元素交换
    HeadAdjust(A, 1, i-1); // 把剩余的待排序元素整理成堆
  }
}
