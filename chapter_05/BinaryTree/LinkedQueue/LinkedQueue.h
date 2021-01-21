/*
 * 链队用单链表来表示
 * 为了方便，给链队添加一个头结点
 */


#ifndef LINKEDQUEUE_H
#define LINKEDQUEUE_H

#include <stdio.h>
#include <stdlib.h>
#include "../Status/Status.h"

typedef int QElemType;
typedef struct QNode
{
  QElemType data;
  struct QNode *next;
} QNode, *Queueptr;
typedef struct
{
  Queueptr front;     // 队头指针
  Queueptr rear;      // 队尾指针
} LinkedQueue;

Status InitQueue(LinkedQueue *Q);
Status DestoryQueue(LinkedQueue *Q);
Status QueueEmpty(LinkedQueue Q);
Status ClearQueue(LinkedQueue *Q);
int QueueLength(LinkedQueue Q);
Status GetHead(LinkedQueue Q, QElemType *e);
Status EnQueue(LinkedQueue *Q, QElemType e);
Status DeQueue(LinkedQueue *Q, QElemType *e);
Status QueueTraverse(LinkedQueue Q, void (*Visit)(QElemType));

#endif
