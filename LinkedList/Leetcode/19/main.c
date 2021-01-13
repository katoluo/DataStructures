/*
 *
 * 19. 删除链表的倒数第N个结点
 *
 * 示例：
 * 链表: 1->2->3->4->5，和 n = 2.
 * 当删除了倒数第2个结点后，
 * 链表: 1->2->3->5.
 *
 * 说明: 
 * 给定的n保证有效的
 */

#include "../LinkedList.h"

void PrintElem(ElemType e)
{
  printf("%d ", e);
}


// 这是一个普通程序
Node* RemoveNthFromEnd(LinkedList *L, int n)
{
  /* Leetcode上面是没有头结点的
   * 这里的创建链表是默认带头结点的
   *
   * 思路:
   * 1. 比较简单粗暴的想法就是先遍历一遍，得出链表长度length
   * 2. 删除的倒数第n个，即第L-n+1个点
   * 3. 再遍历，找到它的前驱即可
   */
  
  if (ListEmpty(*L))
    return *L;

  int length = ListLength(*L);  // 得到链表L的长度
  int pos = length - n + 1;     // 目标结点的位置
  Node *p = (*L)->next;         // p指向链表的首元结点
  Node *pre = NULL;
  int i = 1;

  while (i < pos) {
    pre = p;
    p = p->next;
    ++i;
  }

  if (pre == NULL) {
    // 要删除链表中的第一个有效结点
    (*L)->next = p->next;
    free(p);
  }
  else {
    pre->next = p->next;
    free(p);
  }

  return *L;
}



int main(int argc, char *argv[])
{
  LinkedList L;
  
  CreateList_Tail(&L, 5);
  ListTraverse(L, PrintElem);

  int n = 0;
  printf("删除链表倒数第几个结点: ");
  scanf("%d", &n);
  LinkedList new_l = RemoveNthFromEnd(&L, n);
  ListTraverse(new_l, PrintElem);
  DestoryList(&new_l);

  return EXIT_SUCCESS;
}
