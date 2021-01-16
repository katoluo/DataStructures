#include "LinkedQueue.h"

Status InitQueue(LinkedQueue *Q)
{
  (*Q).rear->next = (*Q).rear = (QNode*)malloc(sizeof(QNode));
  if ((*Q).rear == NULL) exit(OVERFLOW);
  return OK;
}


Status DestoryQueue(LinkedQueue *Q)
{
  if (Q == NULL || (*Q).rear == NULL) return ERROR;
  QNode *p = (*Q).rear->next; // p指向头结点
  (*Q).rear->next = NULL;     // 破环
  while (p != NULL) {
    (*Q).rear = p->next;
    free(p);
    p = (*Q).rear;
  }
  return OK;
}

Status QueueEmpty(LinkedQueue Q)
{
  if (Q.rear == Q.rear->next) return TRUE;
  else return FALSE;
}


int QueueLength(LinkedQueue Q)
{
  QNode *p = Q.rear->next; // p指向头结点
  int count = 0;
  while (p != Q.rear)
  {
    count += 1;
    p = p->next;
  }
  return count;
}


Status ClearQueue(LinkedQueue *Q)
{
  if (Q == NULL || (*Q).rear == NULL) return ERROR;
  if (QueueEmpty(*Q) == TRUE) return OK; // *Q若为空，直接返回

  QNode *head = (*Q).rear->next; // head指向头结点
  (*Q).rear->next = NULL; // 破环
  (*Q).rear = head->next; // 指向第一个有效结点
  QNode *p;
  while ((*Q).rear != NULL)
  {
    p = (*Q).rear->next;
    free((*Q).rear);
    (*Q).rear = p;
  }
  (*Q).rear = head;
  (*Q).rear->next = (*Q).rear;
  return OK;
}

Status Push(LinkedQueue *Q, QElemType e)
{
  if (Q == NULL || (*Q).rear == NULL) return ERROR;
  QNode *p = (QNode*)malloc(sizeof(QNode));
  if (p == NULL) exit(OVERFLOW);
  p->data = e;
  p->next = (*Q).rear->next;
  (*Q).rear->next = p;
  (*Q).rear = p;
  return OK;
}


Status Pop(LinkedQueue *Q, QElemType *e)
{
  if (Q == NULL || (*Q).rear == NULL || QueueEmpty(*Q) == TRUE)
    return ERROR;
  QNode *head = (*Q).rear->next;    // head指向头结点
  QNode *p = head->next;            // p指向第一个有效数据结点
  *e = p->data;                     // 保存队头元素
  if (p == (*Q).rear)               // 只有一个有效结点
  {
    (*Q).rear = head;
    (*Q).rear->next = (*Q).rear;
    free(p);
    return OK;
  }
  head->next = p->next;
  free(p);
  return OK;
}


Status QueueTraverse(LinkedQueue Q, void (*visit)(QElemType))
{
  if (QueueEmpty(Q) == TRUE) return ERROR;
  QNode *p = Q.rear->next->next;    // p指向第一个有效数据结点
  while (p != Q.rear->next)
  {
    visit(p->data);
    p = p->next;
  }
  return OK;
}
