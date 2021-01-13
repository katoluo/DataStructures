
/* 
 * 设计一个算法，
 * 删除递增有序链表中值大于mink且小于maxk的所有元素
 * （mink和maxk是给定的两个参数，其值可以和表中的
 * 元素相同，也可以不同）。
 * 
 */

#include "../LinkedList.h"

void PrintElem(ElemType e)
{
  printf("%d ", e);
}

void Delete(LinkedList *L, ElemType mink, ElemType maxk)
{
  if (ListEmpty(*L))
    return;

  Node *p = (*L)->next;       // 指向首元结点
  Node *pre;                  // 指向< mink 的最后一个结点

  Node *q;
  while (p != NULL) {
    // 这些结点是需要保留的
    if (p->data <= mink) {
      pre = p;
      p = p->next;
    }
    // 这些结点是要被删除的
    else if (p->data > mink && p->data < maxk) {
      q = p->next;
      free(p);
      p = q;
    }
    // 当p指向的结点值 >= maxk时，就删除完毕了
    else {
      pre->next = p;
      break;
    }
  }
}


int main(int argc, char *argv[])
{
  LinkedList L;

  CreateList_Tail(&L, 10);
  ListTraverse(L, PrintElem);

  int mink, maxk;
  printf("请输入mink和maxk: ");
  scanf("%d%d", &mink, &maxk);

  Delete(&L, mink, maxk);
  ListTraverse(L, PrintElem);

  DestoryList(&L);

  return EXIT_SUCCESS;
}
