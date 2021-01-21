
/******************
 * 栈的顺序存储结构
 * （顺序栈）
 ******************/


#ifndef SQSTACK_H
#define SQSTACK_H


#include <stdio.h>
#include <stdlib.h>
#include "../Status/Status.h"

#define STACK_INIT_SIZE 10           // 顺序栈存储空间的初始分配量
#define STACK_INCREMENT 5            // 顺序栈存储空间的分配增量

typedef int SElemType;                // 顺序栈元素类型定义
typedef struct {                      // 顺序栈的存储结构
  SElemType *base;                    // 栈底指针
  SElemType *top;                     // 栈顶指针
  int stacksize;                      // 当前已分配的存储空间
} SqStack;

/* 顺序栈的基本操作 */
Status InitStack(SqStack *S);
Status DestroyStack(SqStack* S);
Status CleanStack(SqStack *S);
Status StackEmpty(SqStack S);
int StackLength(SqStack S);
Status GetTop(SqStack S, SElemType *e);
Status Push(SqStack* S, SElemType e);
Status Pop(SqStack* S, SElemType* e);
Status StackTraverse(SqStack S, void(*Visit)(SElemType));

#endif
