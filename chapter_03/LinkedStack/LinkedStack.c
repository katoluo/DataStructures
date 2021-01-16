/*******************************************************************
 *
 * 链栈的表示和实现
 * 
 * 由于栈的主要操作是在栈顶插入和删除，显然以链表的头部作为栈顶
 * 是最方便的，而且没有必要像单链表那样为了操作方便附加头结点。
 *
 */

#include "./LinkedStack.h"

/*********************************************
 * 初始化                                    *
 *                                           *
 * 构造一个空栈，直接将栈顶指针置空即可      *
 *                                           *
 *********************************************/
Status InitStack(LinkedStack *S)
{
  S = NULL;
  return OK;
}


/*********************************************
 * 销毁                                      *
 *                                           *
 * 释放链栈所占的内存，并将S置空             *
 *                                           *
 *********************************************/
Status DestoryStack(LinkedStack *S)
{
  SNode *p;
  while (*S != NULL) {
    p = (*S)->next;
    free(*S);
    *S = p;
  }
  *S = NULL;
  return OK;
}


/*********************************************
 * 判断链栈是否是空栈                        *
 *                                           *
 * 如果是空栈则返回TRUE，                    *
 * 否则返回FALSE                             *
 *********************************************/
Status StackEmpty(LinkedStack S)
{
  if (S == NULL) return TRUE;
  else return FALSE;
}


/*********************************************
 * 计算链栈的结点个数                        *
 *                                           *
 * 返回链栈的结点个数                        *
 *                                           *
 *********************************************/
int StackLength(LinkedStack S)
{
  int count = 0;
  while (S != NULL) {
    ++count;
    S = S->next;
  }
  return count;
}


/*********************************************
 * 获取栈顶元素                              *
 *                                           *
 * 返回链栈的元素值                          *
 *                                           *
 *********************************************/
SElemType GetTop(LinkedStack S)
{
  if (S != NULL)
    return S->data;
}


/*********************************************
 * 入栈                                      *
 *                                           *
 * 将元素e压入栈顶                           *
 *                                           *
 *********************************************/
Status Push(LinkedStack *S, SElemType e)
{
  SNode *p = (SNode*)malloc(sizeof(SNode));
  p->data = e;
  p->next = *S;
  *S = p;
  return OK;
}


/*********************************************
 * 出栈                                      *
 *                                           *
 * 将栈顶元素出栈，并将元素值存放在e中       *
 *                                           *
 *********************************************/
Status Pop(LinkedStack *S, SElemType *e)
{
  if ((*S) == NULL) return ERROR;
  *e = (*S)->data;
  SNode *p = *S;
  *S = (*S)->next;
  free(p);
  return OK;
}


/*********************************************
 * 遍历链栈                                  *
 *                                           *
 *********************************************/
Status StackTraverse(LinkedStack S, void (*Visit)(SElemType e))
{
  while (S != NULL) {
    Visit(S->data);
    S = S->next;
  }
  putchar('\n');
  return OK;
}
