#ifndef DBLSTACK_H
#define DBLSTACK_H

#include <stdio.h>
#include <stdlib.h>
#include "../Status/Status.h"
#define MAXSIZE 10
typedef int SElemType;
typedef struct
{
  int top[2], bot[2];          // 栈顶和栈底指针
  SElemType *V;                // 栈数组
  int m;                       // 栈最大可容纳元素个数
} DblStack;

Status InitStatck(DblStack *S);
Status DestoryStack(DblStack *S);
Status StackEmpty(DblStack S);
Status Stack_i_Empty(DblStack S, int i);
Status StackFull(DblStack S);
Status Push(DblStack *S, int i, SElemType e);
Status Pop(DblStack *S, int i, SElemType *e);
Status StackTraverse(DblStack S, void (*Visit)(SElemType));



#endif
