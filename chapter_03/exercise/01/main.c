#include "./DblStack.h"


void PrintElem(SElemType e)
{
  printf("%d ", e);
}

int main(void)
{
  DblStack S;
  SElemType e;
  int i;

  {
    printf("初始化双栈...\n");
    InitStatck(&S);
  }
  PressEnterToContinue(debug);

  {
    StackEmpty(S) ? printf("双栈S为空!!\n") : printf("双栈S不为空!!\n");
    StackFull(S) ? printf("双栈S为满!!\n") : printf("双栈S不为满!!\n");
  }
  PressEnterToContinue(debug);

  {
    for (i = 1; i <= 5; ++i) {
      Push(&S, 0, i);
      printf("元素 %d 压入栈0...\n", i);
    }
    PressEnterToContinue(debug);
    Stack_i_Empty(S, 0) ? printf("栈0为空!!\n") : printf("栈0不为空!!\n");
    Stack_i_Empty(S, 1) ? printf("栈1为空!!\n") : printf("栈1不为空!!\n");
    PressEnterToContinue(debug);
    for (i = 1; i <= 5; ++i) {
      Push(&S, 1, i);
      printf("元素 %d 压入栈1...\n", i);
    }
    Stack_i_Empty(S, 1) ? printf("栈1为空!!\n") : printf("栈1不为空!!\n");
  }
  PressEnterToContinue(debug);

  {
    printf("遍历双栈...\n");
    StackTraverse(S, PrintElem);
    StackFull(S) ? printf("双栈S为满!!\n") : printf("双栈S不为满!!\n");
  }
  PressEnterToContinue(debug);

  {
    Pop(&S, 0, &e);
    printf("0号栈顶元素 %d 出栈...\n", e);
    Pop(&S, 1, &e);
    printf("1号栈顶元素 %d 出栈...\n", e);
    PressEnterToContinue(debug);
    StackFull(S) ? printf("双栈S为满!!\n") : printf("双栈S不为满!!\n");
  }
  PressEnterToContinue(debug);

  {
    printf("销毁前: ");
    S.V != NULL ? printf("双栈存在!!\n") : printf("双栈不存在!!\n");

    DestoryStack(&S);

    printf("销毁后: ");
    S.V != NULL ? printf("双栈存在!!\n") : printf("双栈不存在!!\n");
  }
  PressEnterToContinue(debug);
  return 0;
}
