/*
 * 给你两个非空的链表，表示两个非负的整数。
 * 它们每位数字都是按照逆序的方式存储的，
 * 并且每个结点只能存储一位数字。
 * 请你将两个数相加，并以相同的形式返回一个表示和的链表。
 *
 * 注: 
 * 你可以假设除了数字0之外，这两个数都不会以0开头。
 *
 * 例1:        例2:       例3: 
 * 2->4->3     0          9->9->-9->9->9->9->9
 * 5->6->4     0          9->9->9->9
 * 结果为:             
 * 8->0->7     0          8->9->9->9->0->0->0->1
 *
 */

#include "../LinkedList.h"

void PrintElem(ElemType e)
{
  printf("%d ", e);
}

void AddTwoNumbers(LinkedList la, LinkedList lb, LinkedList *lc)
{

  if (ListEmpty(la) && ListEmpty(lb)) return;

  Node *pa = la->next;       // pa指向la首元结点
  Node *pb = lb->next;       // pb指向lb首元结点
  Node *tail = *lc;           // tail指向lc的尾结点

  int sum = 0;
  int carry = 0;

  while (pa != NULL || pb != NULL) {
    
    int a = pa ? pa->data : 0;
    int b = pb ? pb->data : 0;

    sum = a + b + carry;

    tail->next = (Node*)malloc(sizeof(Node));
    tail->next->data = sum % 10;
    tail = tail->next;

    carry = sum / 10;

    if (pa != NULL) pa = pa->next;
    if (pb != NULL) pb = pb->next;

  }

  if (pa == NULL && pb == NULL && carry == 1) {
    tail->next = (Node*)malloc(sizeof(Node));
    tail->next->data = carry;
    tail->next->next = NULL;
  }
  
}


int main(int argc, char *argv[])
{
  LinkedList la, lb, lc;

  CreateList_Tail(&la, 3);
  ListTraverse(la, PrintElem);
  CreateList_Tail(&lb, 3);
  ListTraverse(lb, PrintElem);

  InitList(&lc);

  AddTwoNumbers(la, lb, &lc);
  ListTraverse(lc, PrintElem);

  DestoryList(&la);
  DestoryList(&lb);
  DestoryList(&lc);

  return EXIT_SUCCESS;
}
