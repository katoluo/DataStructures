
/*
 * 设计算法将一个带头结点的单链表A分解为两个具有相同结构的链表B和C，
 * 其中B表的结点为A表中值小于零的结点，而C表的结点为A表中值大于零的
 * 结点（链表A中的元素为非零整数，要求B、C表利用A表的结点）。
 *
 */

#include "../LinkedList.h"

void PrintElem(ElemType e)
{
  printf("%d ", e);
}

void Discomposed(LinkedList *L)
{
  LinkedList lb, lc;
  InitList(&lb);
  InitList(&lc);

  Node *pa = (*L)->next;
  free(*L);
  *L = NULL;

  Node *q;
  while (pa != NULL) {
    if (pa->data < 0) {
      q = pa->next;
      pa->next = lb->next;
      lb->next = pa;
      pa = q;
    }
    else{
      q = pa->next;
      pa->next = lc->next;
      lc->next = pa;
      pa = q;
    }
  }

  // 遍历
  printf("B: ");
  ListTraverse(lb, PrintElem);
  putchar('\n');

  printf("C: ");
  ListTraverse(lc, PrintElem);
  putchar('\n');

  // free
  DestoryList(&lb);
  DestoryList(&lc);
}


int main(int argc, char *argv[])
{
  LinkedList la;
  CreateList_Tail(&la, 10);
  ListTraverse(la, PrintElem);

  Discomposed(&la);

  return EXIT_SUCCESS;
}
