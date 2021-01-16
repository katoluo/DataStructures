#include "SqQueue.h"

void PrintElem(QElemType e)
{
  printf("%d ", e);
}

int main(void)
{
  SqQueue Q;
  int i;
  QElemType e;

  {
    printf("初始化循环顺序队列Q...\n");
    InitQueue(&Q);
  }
  PressEnterToContinue(debug);

  {
    QueueEmpty(Q) ? printf("Q为空!!\n") : printf("Q不为空!!\n");
  }
  PressEnterToContinue(debug);

  {
    for (i = 1; i <= 6; ++i) {
      EnQueue(&Q, i * 2);
      printf("元素 %d 入队Q...\n", i * 2);
    }
  }
  PressEnterToContinue(debug);

  {
    printf("Q中的元素为: ");
    QueueTraverse(Q, PrintElem);
  }
  PressEnterToContinue(debug);

  {
    i = QueueLength(Q);
    printf("Q的长度为 %d \n", i);
  }
  PressEnterToContinue(debug);

  {
    DeQueue(&Q, &e);
    printf("队头元素 %d 出队...\n", e);
    printf("Q中的元素为: ");
    QueueTraverse(Q, PrintElem);
  }
  PressEnterToContinue(debug);

  {
    GetHead(Q, &e);
    printf("队头元素的值为 %d \n", e);
  }
  PressEnterToContinue(debug);

  {
    printf("清空Q前: ");
    QueueTraverse(Q, PrintElem);

    ClearQueue(&Q);

    printf("清空Q后: ");
    QueueTraverse(Q, PrintElem);
  }
  PressEnterToContinue(debug);

  {
    printf("销毁Q前: ");
    Q.base ? printf("Q存在!!\n") : printf("Q不存在!!\n");

    DestoryQueue(&Q);

    printf("销毁Q后: ");
    Q.base ? printf("Q存在!!\n") : printf("Q不存在!!\n");
  }
  PressEnterToContinue(debug);

  return 0;
}
