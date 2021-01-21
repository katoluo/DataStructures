#include "./LinkedQueue.h"

/*
 * 初始化
 * 构造一个空的链队
 * 注：带头结点的队列
 *
 */
Status InitQueue(LinkedQueue *Q)
{
  if (Q == NULL) return ERROR;
  Q->front = Q->rear = (Queueptr)malloc(sizeof(QNode));
  if (Q->front == NULL) exit(OVERFLOW);
  Q->front->next = NULL;
  return OK;
}


/*
 * 销毁
 *
 * 释放链队所占内存
 */
Status DestoryQueue(LinkedQueue *Q)
{
  if (Q == NULL) return ERROR;
  while (Q->front != NULL) {
    Q->rear = Q->front->next;
    free(Q->front);
    Q->front = Q->rear;
  }
  return OK;
}



/*
 * 置空
 *
 * 这里需要释放链队中并非头结点处的空间
 */
Status ClearQueue(LinkedQueue *Q)
{
  if (Q == NULL) return ERROR;
  Q->rear = Q->front->next;
  while (Q->rear != NULL) {
    Q->front->next = Q->rear->next;
    free(Q->rear);
    Q->rear = Q->front->next;
  }
  Q->rear = Q->front;
  return OK;
}


/*
 * 判空
 *
 * 判断链队是否包含有效数据
 */
Status QueueEmpty(LinkedQueue Q)
{
  if (Q.front == Q.rear) return TRUE;
  else return FALSE;
}


/*
 * 计数
 *
 * 返回链队包含的有效元素的数量
 */
int QueueLength(LinkedQueue Q)
{
  int count = 0;
  Queueptr p = Q.front;
  while (p != Q.rear) {
    p = p->next;
    ++count;
  }
  return count;
}


/*
 * 取值
 *
 * 获取队头元素，将其保存到e中
 */
Status GetHead(LinkedQueue Q, QElemType *e)
{
  if (Q.front == NULL || Q.front == Q.rear) return ERROR;
  *e = Q.front->next->data;
  return OK;
}



/*
 * 入队
 *
 * 将元素e添加到队列尾部
 */
Status EnQueue(LinkedQueue *Q, QElemType e)
{
  if (Q == NULL || Q->front == NULL) return ERROR;
  Queueptr p = (Queueptr)malloc(sizeof(QNode));
  p->data = e;
  p->next = NULL;
  Q->rear->next = p;
  Q->rear = p;
  return OK;
}



/*
 * 出队
 *
 * 移除队头元素，将其保存到e中
 */
Status DeQueue(LinkedQueue *Q, QElemType *e)
{
  if (Q == NULL || Q->front == NULL
      || Q->front == Q->rear) return ERROR;
  Queueptr p = Q->front->next; // p指向第一个有效数据的结点
  *e = p->data; // 保存队头元素
  Q->front->next = p->next;
  if (Q->rear == p) Q->rear = Q->front; // 链队只有一个有效结点
  free(p);
  return OK;
}



/*
 * 遍历
 *
 * 用Visit函数访问链队
 */
Status QueueTraverse(LinkedQueue Q, void (*Visit)(QElemType))
{
  if (Q.front == NULL) return ERROR;
  Queueptr p = Q.front->next;
  while ( p != NULL ) {
    Visit(p->data);
    p = p->next;
  }
  putchar('\n');
  return OK;
}
