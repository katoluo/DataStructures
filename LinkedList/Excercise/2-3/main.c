/*
 * 已知两个链表A和B分别表示两个集合，其元素递增排列。
 * 请设计一个算法，用于求出A和B的交集，并放在A链表中。
 */

#include "../LinkedList.h"


void PrintElem(ElemType e)
{
  printf("%d ", e);
}



Node* Mix(LinkedList *la, LinkedList *lb)
{
  /*
   * 题目中说要放在A中，那么用到的结点直接使用A结点即可
   * 那么链表B的内存应该要被全部释放
   *
   * 1. 如果pa->data < pb->data，释放pa所指内存，pa向右移动
   * 2. 如果pa->data = pb->data，找到交集，加入到A链表(新)中
   * 3. 如果pa->data > pb->data，pb向右移动；
   * 4. 为了方便，在找交集中就不顺便释放lb了，等到结束时调用函数即可
   */
  Node *pa = (*la)->next;         // pa指向la首元结点
  Node *pb = (*lb)->next;         // pb指向lb首元结点

  (*la)->next = NULL;             // 切断与la的联系
  
  Node *q;
  while (pa != NULL && pb != NULL) {

    // 1.
    if (pa->data < pb->data) {
      q = pa;
      pa = pa->next;
      free(q);
    }
    // 2.
    else if (pa->data == pb->data) {
      q = pa->next;
      pa->next = (*la)->next;
      (*la)->next = pa;
      pa = q;
      pb = pb->next;
    }
    // 3.
    else 
      pb = pb->next;
  }

  // 释放剩余的不使用la结点
  if (pa) {
    while (pa) {
      q = pa->next;
      free(pa);
      pa = q;
    }
  }

  // 释放lb
  DestoryList(lb);

  return *la;
}


int main(int argc, char *argv[])
{
  LinkedList la, lb, lc;

  CreateList_Tail(&la, 5);
  CreateList_Tail(&lb, 5);

  lc = Mix(&la, &lb);
  ListTraverse(lc, PrintElem);

  DestoryList(&lc);
  return EXIT_SUCCESS;
}
