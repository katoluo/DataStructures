#include "../SequenceStack/SqStack.h"

void PrintElem(SElemType e)
{
  printf("%d ", e);
}

Status Playgame()
{
  SqStack S;
  InitStack(&S);

  SElemType e;
  printf("输入整数序列(q for quit): ");
  while (scanf("%d", &e))
  {
    if (e != -1) {
      if (S.top - S.base == S.stacksize) {
        printf("游戏栈满了,游戏退出!!\n");
        break;
      }
      printf("读取到游戏栈需要的整数，吞了!!\n");
      Push(&S, e);
    }
    else {
      if (StackEmpty(S) == TRUE) {
        printf("游戏栈空，还输入-1，不玩了不玩了!!\n");
        break;
      }
      Pop(&S, &e);
      printf("读取到-1，栈顶元素 %d 被抛弃了!!\n", e);
    }
  }
  printf("看看游戏栈吃了什么整数序列: ");
  StackTraverse(S, PrintElem);
  DestroyStack(&S);
  return OK;
}



int main(void)
{
  Playgame();

  return 0;
}
