#include "./SqQueue.h"

/*************************************************************
 * 初始化
 * 构造一个空的顺序队列
 * 成功返回OK，否则返回ERROR
 *
 * 注：这里的顺序队列为循环队列
 *************************************************************/
Status InitQueue(SqQueue *Q)
{
  if (Q == NULL) return ERROR; // Q为NULL
  (*Q).base = (QElemType*)malloc(sizeof(QElemType) * MAXQSIZE);
  if (Q->base == NULL) exit(OVERFLOW); // 内存分配失败
  Q->front = Q->rear = 0;  // 标志队空
  return OK;
}



/*************************************************************
 * 销毁
 * 释放循环队列所占内存
 *************************************************************/
Status DestoryQueue(SqQueue *Q)
{
  if (Q == NULL) return ERROR; // Q为NULL，队列不存在
  if (Q->base != NULL) free(Q->base); // base不为NULL时，free(base)
  Q->base = NULL;
  Q->front = Q->rear = 0;
  return OK;
}



/*************************************************************
 * 置空
 * 只是清理循环顺序队列中存储的数据，
 * 不释放占的内存
 *************************************************************/
Status ClearQueue(SqQueue *Q)
{
  if (Q == NULL || Q->base == NULL) return ERROR;
  Q->front = Q->rear = 0;  // 表示该队列为空队列
  return OK;
}


/*************************************************************
 * 判空
 *
 * 判断循环顺序队列是否包含有效数据
 *************************************************************/
Status QueueEmpty(SqQueue Q)
{
  if (Q.front == Q.rear) return TRUE;
  else return FALSE;
}



/*************************************************************
 * 计算队列中有效元素的数量
 *
 * 返回该值
 * ***********************************************************/
int QueueLength(SqQueue Q)
{
  if (Q.base == NULL) return 0;
  // 循环队列，rear - front可能是负值，需要使用一下操作
  return (Q.rear - Q.front + MAXQSIZE) % MAXQSIZE;
}



/*************************************************************
 * 取值
 *
 * 获取队头元素，将其保存到e中
 * ***********************************************************/
Status GetHead(SqQueue Q, QElemType *e)
{
  if (Q.base == NULL || Q.rear == Q.front) return ERROR;
  *e = Q.base[Q.front];
  return OK;
}



/*************************************************************
 * 入队
 *
 * 将元素e添加到队列的尾部
 * ***********************************************************/
Status EnQueue(SqQueue *Q, QElemType e)
{
  if (Q == NULL || Q->base == NULL) return ERROR;
  // 队满了(会浪费一个空间来区分队满和队空)
  if (Q->front == (Q->rear + 1) % MAXQSIZE) return ERROR;
  Q->base[Q->rear] = e; // 入队
  Q->rear = (Q->rear + 1) % MAXQSIZE;
  return OK;
}



/*************************************************************
 * 出队
 *
 * 移除队列的头部元素，将其保存到e中
 * ***********************************************************/
Status DeQueue(SqQueue *Q, QElemType *e)
{
  if (Q == NULL || Q->base == NULL) return ERROR;
  if (Q->front == Q->rear) return ERROR; // 队空
  *e = Q->base[Q->front]; // 队头元素保存到e中
  Q->front = (Q->front + 1) % MAXQSIZE;
  return OK;
}



/*************************************************************
 * 遍历
 * 用Visit函数访问队列
 * ***********************************************************/
Status QueueTraverse(SqQueue Q, void (*Vistit)(QElemType))
{
  if (Q.base == NULL) return ERROR;
  for (int i = Q.front; i != Q.rear; i = (i+1) % MAXQSIZE)
    Vistit(Q.base[i]);
  putchar('\n');
  return OK;
}
