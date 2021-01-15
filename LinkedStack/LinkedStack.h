
/*****************************************************
 * 
 * 栈的链式存储结构（链栈）
 *
 *****************************************************/


#ifndef LINKEDSTACK_H
#define LINKEDSTACK_H

#include <stdio.h>
#include <stdlib.h>
#include "../Status/Status.h"

typedef int SElemType;
typedef struct SNode {
  SElemType data;
  struct SNode *next;
} SNode, *LinkedStack;


Status InitStack(LinkedStack *S);
Status DestoryStack(LinkedStack *S);
//Status ClearStack(LinkedStack *S); // 跟销毁一样
Status StackEmpty(LinkedStack S);
int StackLength(LinkedStack S);
SElemType GetTop(LinkedStack S);
Status Push(LinkedStack *S, SElemType e);
Status Pop(LinkedStack *S, SElemType *e);
Status StackTraverse(LinkedStack S, void (*Visit)(SElemType e));

#endif
