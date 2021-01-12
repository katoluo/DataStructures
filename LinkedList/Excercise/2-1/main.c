/******************************************************************
 * 将两个递增的有序链表合并为一个递增的有序链表。
 * 要求结构链表仍使用原来两个链表的存储空间，
 * 不另外占用其他的存储空间。
 * 表中不允许有重复的数据。
 ******************************************************************/

#include "../LinkedList.h"


void PrintElem(ElemType e)
{
  printf("%d ", e);
}


Node* MergeTwoLists(LinkedList *l1, LinkedList *l2)
{
  /*
   * l1和l2是带有头结点的单链表
   * 
   */
  // 判断链表是否为空表
  if (ListEmpty(*l1)) return *l2;
  if (ListEmpty(*l2)) return *l1;

  Node *pre;
  Node *p1 = (*l1)->next;      // p1指向链表l1的首元结点
  Node *p2 = (*l2)->next;      // p2指向链表l2的首元结点
  
  // 我们采用l1的头结点，释放l2的头结点
  pre = (*l1); // pre指向头结点
  free(*l2);
  *l2 = NULL;

  while (p1 && p2) {
    if (p1->data < p2->data) {
      pre->next = p1;
      pre = p1;
      p1 = p1->next;
    }
    else if (p1->data == p2->data) {
      pre->next = p1;
      pre = p1;
      p1 = p1->next;
      Node *tmp = p2;
      p2 = p2->next;
      free(tmp);
    }
    else {
      pre->next = p2;
      pre = p2;
      p2 = p2->next;
    }
  }

  if (!p1) pre->next = p2;
  if (!p2) pre->next = p1;

  return *l1;
}



int main(int argc, char *argv[])
{
  LinkedList l1;
  LinkedList l2;

  CreateList_Head(&l1, 5);     // 头插法创建l1
  printf("l1: ");
  ListTraverse(l1, PrintElem);
  CreateList_Tail(&l2, 5);     // 尾插法创建l2
  printf("l2: ");
  ListTraverse(l2, PrintElem);
  LinkedList new_l = MergeTwoLists(&l1, &l2);
  printf("new_l: ");
  ListTraverse(new_l, PrintElem);
  DestoryList(&new_l);

  return EXIT_SUCCESS;
}
