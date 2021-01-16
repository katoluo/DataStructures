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
} QNode;
typedef struct
{
  QNode *rear;
} LinkedQueue;

Status InitQueue(LinkedQueue *Q);
Status DestoryQueue(LinkedQueue *Q);
int QueueLength(LinkedQueue Q);
Status ClearQueue(LinkedQueue *Q);
Status QueueEmpty(LinkedQueue Q);
Status Push(LinkedQueue *Q, QElemType e);
Status Pop(LinkedQueue *Q, QElemType *e);
Status QueueTraverse(LinkedQueue Q, void (*visit)(QElemType));


#endif
