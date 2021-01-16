#include "SqStack.h"

/******************************************************************
 * 初始化
 *
 * 构造一个空栈。
 * 初始化成功则返回OK，否则返回ERROR。
 *
 */
Status InitStack(SqStack *S)
{
  if ( !S ) return ERROR;

  // 为顺序表动态分配一个最大容量为STACK_INIT_SIZE的数组空间
  (*S).base = (SElemType*)malloc(sizeof(SElemType) * STACK_INIT_SIZE);
  if ( !(*S).base ) exit(OVERFLOW);       // 内存分配失败

  (*S).top = (*S).base;                   // top初始为base，空栈
  (*S).stacksize = STACK_INIT_SIZE;       // stacksize置为栈的最大容量

  return OK;
}



/******************************************************************
 * 销毁
 *
 * 释放顺序栈所占内存
 *
 */
Status DestroyStack(SqStack *S)
{
  if ( !S ) return ERROR;

  if ( !(*S).base ) free( (*S).base );    // 如果base不为NULL，释放

  (*S).base = NULL;
  (*S).top = NULL;
  (*S).stacksize = 0;

  return OK;
}



/*****************************************************************
 * 置空
 *
 * 只是清理顺序栈中存储的数据，不释放顺序栈所占内存。
 *
 */
Status CleanStack(SqStack *S)
{
  if ( !S || !(*S).base ) return ERROR;

  (*S).top = (*S).base;     // 表面空栈，实际哈哈哈

  return OK;
}



/*****************************************************************
 * 判断是否为空栈
 *
 * 返回值: 
 * TRUE : 顺序栈为空
 * FALSE: 顺序栈不为空
 *
 */
Status StackEmpty(SqStack S)
{
  if ( S.base == S.top ) return TRUE;
  else return FALSE;
}



/****************************************************************
 *
 * 计算顺序栈中有效的元素个数
 *
 * 并返回这个值
 *
 */
int StackLength(SqStack S)
{
  if ( !S.base ) return 0;

  return (int)(S.top - S.base);
}



/*****************************************************************
 * 取值
 *
 * 返回栈顶元素，并用e接收
 */
Status GetTop(SqStack S, SElemType *e)
{
  if ( !S.base || S.base == S.top ) return ERROR;
  *e = *(S.top - 1);

  return OK;
}


/*****************************************************************
 * 入栈
 * 
 * 将元素e压入到栈顶
 *
 */
Status Push(SqStack *S, SElemType e)
{
  if ( !S || !(*S).base ) return ERROR;

  // 栈满时，追加存储空间
  if ((*S).top - (*S).base >= (*S).stacksize) {
    (*S).base = (SElemType*)realloc((*S).base, 
        ((*S).stacksize + STACK_INCREMENT) * sizeof(SElemType));
    // 存储分配失败
    if ( !(*S).base ) exit(OVERFLOW);

    (*S).top = (*S).base + (*S).stacksize;
    (*S).stacksize += STACK_INCREMENT;
  }

  *(S->top++) = e;

  return OK;
}



/******************************************************************
 * 出栈
 *
 * 将栈顶元素弹出，并用e接收
 */
Status Pop(SqStack *S, SElemType *e)
{
  if ( !S || !(*S).base ) return ERROR;       // 顺序栈结构不存在

  if ((*S).base == (*S).top) return ERROR;    // 空栈

  *e = *(--(*S).top);

  return OK;
}



/******************************************************************
 * 遍历
 *
 * 用Visit函数访问顺序栈S
 *
 */
Status StackTraverse(SqStack S, void (*Visit)(SElemType))
{
  if ( !S.base ) return ERROR;

  SElemType *p = S.base;
  while ( p < S.top ) Visit(*p++);

  putchar('\n');

  return OK;
}
