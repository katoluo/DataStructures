#include "./LinkedQueue.h"

void PrintElem(QElemType e)
{
  printf("%d ", e);
}



int main(void)
{
  LinkedQueue Q;
  QElemType e;
  int i;

  {
    printf("初始化队列Q...\n");
    InitQueue(&Q);
  }
  PressEnterToContinue(debug);

  {
    QueueEmpty(Q) ? printf("Q为空!!\n") : printf("Q不为空!!\n");
  }
  PressEnterToContinue(debug);

  {
    for (i = 1; i <= 6; ++i) {
      Push(&Q, i * 2);
      printf("元素 %d 进队...\n", i * 2);
    }
  }
  PressEnterToContinue(debug);

  {
    printf("Q中的元素: ");
    QueueTraverse(Q, PrintElem);
  }
  PressEnterToContinue(debug);

  {
    Pop(&Q, &e);
    printf("队头元素 %d 出队...\n", e);
    printf("Q中的元素: ");
    QueueTraverse(Q, PrintElem);
  }
  PressEnterToContinue(debug);
  
  {
    printf("清理Q前: ");
    QueueEmpty(Q) ? printf("Q为空!!\n") : printf("Q不为空!!\n");

    ClearQueue(&Q);

    printf("清理Q后: ");
    QueueEmpty(Q) ? printf("Q为空!!\n") : printf("Q不为空!!\n");
  }
  PressEnterToContinue(debug);

  {
    printf("销毁Q前: ");
    Q.rear ? printf("Q存在!!\n") : printf("Q不存在!!\n");

    DestoryQueue(&Q);

    printf("销毁Q后: ");
    Q.rear ? printf("Q存在!!\n") : printf("Q不存在!!\n");
  }
  PressEnterToContinue(debug);

  return 0;
}
