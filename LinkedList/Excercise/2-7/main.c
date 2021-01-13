
/*
 * 设计一个算法，
 * 将链表中所有结点的链接方向“原地”逆转，
 * 即要求仅利用原表的存储空间，
 * 换句话说，要求算法的空间复杂度为O(1)。
 *
 */

#include "../LinkedList.h"

void PrintElem(ElemType e)
{
  printf("%d ", e);
}


/*
 * 思路：
 * 头变尾，尾变头
 * 使用头插法即可
 */
void Reversed(LinkedList *L)
{
  if (ListEmpty(*L))
    return;

  Node *p = (*L)->next;    // 指向首元结点
  (*L)->next = NULL;       // 将L变为头结点的空表

  Node *q;
  while (p != NULL) {
    q = p->next;
    // 头插法达到逆转
    p->next = (*L)->next;
    (*L)->next = p;
    p = q;
  }
}



int main(int argc, char *argv[])
{
  LinkedList L;

  CreateList_Tail(&L, 5);
  ListTraverse(L, PrintElem);

  Reversed(&L);
  ListTraverse(L, PrintElem);

  DestoryList(&L);

  return EXIT_SUCCESS;
}
