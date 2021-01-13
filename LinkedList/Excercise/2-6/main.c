/*
 * 设计一个算法，通过一趟遍历确定长度为n的单链表中
 * 值最大的结点
 *
 */

#include "../LinkedList.h"

void PrintElem(ElemType e)
{
  printf("%d ", e);
}


Node* Max(LinkedList L)
{
  // 如果为空链表返回NULL
  if (ListEmpty(L))
    return NULL;

  Node *p = L->next;      // p指向首元结点
  Node *p_max = p;        // 最终指向元素值最大的结点

  while (p != NULL) {
    
    if (p->data > p_max->data)
      p_max = p;

    p = p->next;
  }

  return p_max;
}


int main(int argc, char *argv[])
{
  LinkedList L;

  CreateList_Tail(&L, 5);
  ListTraverse(L, PrintElem);

  Node *p_max = Max(L);
  printf("\n%d \n", p_max->data);

  DestoryList(&L);
  
  return EXIT_SUCCESS;
}
