/******************************************************************
 * 将两个非递减的有序链表合并为一个非递增的有序链表。
 * 要求结果链表仍使用原来两个链表的存储空间，
 * 表中允许有重复的数据。
 *
 * 非递减有序，如: 1 1 2 3 3 4 5 6
 * 非递增有序, 如: 6 5 4 3 3 2 1 1
 *
 * 思路: 
 * 非递增有序，即越大的结点在链表的位置越靠前，
 * 而我们从l1和l2先接触到的值的最小的，然后逐渐变大，
 * 然后靠这样遍历一次就可以合并成新的链表，
 * 我们可以使用头插法来完成。
 ******************************************************************/ 

#include "../LinkedList.h"

void PrintElem(ElemType e)
{
  printf("%d ", e);
}


Node* MergeTwoLists2(LinkedList *l1, LinkedList *l2)
{
  Node *p1 = (*l1)->next; // p1指向l1的首元结点
  Node *p2 = (*l2)->next; // p2指向l2的首元结点

  Node *l3 = *l1;         // 使用l1的头结点
  l3->next = NULL;        // l3为带头结点的空链表
  free(*l2);              // 释放l2的头结点
  *l2 = NULL;

  /*
   * 找出链表中元素较小的，让q指向这个结点
   * 相应的p*指针后移，知道p1和p2都指向NULL
   * 使用头插法将q指向的结点加入到l3中
   *
   * 结果返回l3
   */
  Node *q;
  while (p1 != NULL || p2 != NULL) {
    if (p1 == NULL) {
      q = p2;
      p2 = p2->next;
    }
    else if(p2 == NULL) {
      q = p1;
      p1 = p1->next;
    }
    else if (p1->data <= p2->data) {
      q = p1;
      p1 = p1->next;
    }
    else {
      q = p2;
      p2 = p2->next;
    }

    q->next = l3->next;
    l3->next = q;
  }

  return l3;
}


int main(int argc, char *argv[])
{
  LinkedList l1;
  LinkedList l2;

  CreateList_Tail(&l1, 5);
  ListTraverse(l1, PrintElem);
  CreateList_Tail(&l2, 5);
  ListTraverse(l2, PrintElem);

  LinkedList new_l = MergeTwoLists2(&l1, &l2);
  ListTraverse(new_l, PrintElem);

  DestoryList(&new_l);

  return EXIT_SUCCESS;
}
