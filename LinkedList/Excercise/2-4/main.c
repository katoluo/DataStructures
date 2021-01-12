/*
 * 已知两个链表A和B分别表示两个集合，其元素递增排列。
 * 请设计算法求出两个集合A和B的差集（仅由在A中出现而不再B
 * 中出现的素所构成的集合），并以同样的形式存储，
 * 同时返回该集合的元素个数
 */ 

#include "../LinkedList.h"

void PrintElem(ElemType e)
{
  printf("%d ", e);
}


Node* Difference(LinkedList *la, LinkedList *lb)
{

  /*
   * 思路：
   * 1. 当pa->data < pb->data时，这个结点是我们需要的,pa向右移
   * 2. 当pa->data == pb->data时，这个结点需要从la中释放，pb向右移
   * 3. 当pa->data > pb->data时，pb向右移动
   *
   */
  Node *pa = (*la)->next;
  Node *pb = (*lb)->next;

  Node *pre = (*la);
  while (pa != NULL && pb != NULL) {

    if (pa->data < pb->data) {
      pre = pa;
      pa = pa->next;
    }
    else if (pa->data == pb->data) {
      pre->next = pa->next;
      free(pa);
      pa = pre->next;
      pb = pb->next;
    }
    else {
      pb = pb->next;
    }
  }
  // 释放lb内存
  DestoryList(lb);
  return *la;
}


int main(int argc, char *argv[])
{
  LinkedList la, lb, lc;

  CreateList_Tail(&la, 5);
  CreateList_Tail(&lb, 5);

  lc = Difference(&la, &lb);
  ListTraverse(lc, PrintElem);

  DestoryList(&lc);

  return EXIT_SUCCESS;
}
