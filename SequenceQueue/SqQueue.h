/******************************************************
 * 循环队列——队列的顺序表示和实现
 *
 */
#ifndef SQQUEUE_H
#define SQQUEUE_H

#include <stdio.h>
#include <stdlib.h>
#include "../Status/Status.h"

#define MAXQSIZE 100                    // 队列可能达到的最大长度

typedef int QElemType;
// ------------ 循环队列的顺序存储结构 -------------------
typedef struct
{
  QElemType *base;      // 存储空间的基地址
  int front;            // 若队列不空，值为头元素在数组中的索引
  int rear;             // 若队列不空，值为尾元素在数组中的索引+1
} SqQueue;

Status InitQueue(SqQueue *Q);
Status DestoryQueue(SqQueue *Q);
Status ClearQueue(SqQueue *Q);
Status QueueEmpty(SqQueue Q);
int QueueLength(SqQueue Q);
Status GetHead(SqQueue Q, QElemType *e);
Status EnQueue(SqQueue *Q, QElemType e);
Status DeQueue(SqQueue *Q, QElemType *e);
Status QueueTraverse(SqQueue Q, void (*Vistit)(QElemType));


#endif
