#include "./SqStack.h"


// 测试函数，打印元素
void PrintElem(SElemType e)
{
  printf("%d ", e);
}


int main(int argc, char *argv[])
{
  
  SqStack S;
  SElemType e;
  int i;

  printf("InitStack: \n");
  {
    printf("初始化顺序栈S ...\n");
    InitStack(&S);
  }
  PressEnterToContinue(debug);

  printf("StackEmpty: \n");
  {
    StackEmpty(S) ? printf("S为空!!\n") : printf("S不为空!!\n");
  }
  PressEnterToContinue(debug);

  printf("Push: \n");
  {
    for ( i = 1; i <= 6; ++i ) {
      Push(&S, 2 * i);
      printf("将 %2d 压入栈S ...\n", 2 * i);
    }
  }
  PressEnterToContinue(debug);

  printf("StackTraverse: \n");
  {
    printf("S中的元素为：S = ");
    StackTraverse(S, PrintElem);
  }
  PressEnterToContinue(debug);


  printf("StackLength: \n");
  {
    i = StackLength(S);
    printf("S的长度为 %d \n", i);
  }
  PressEnterToContinue(debug);

  printf("Pop: \n");
  {
    Pop(&S, &e);
    printf("栈顶元素 \"%d\" 出栈...\n", e);
    printf("S中的元素为：S = ");
    StackTraverse(S, PrintElem);
  }
  PressEnterToContinue(debug);

  printf("GetTop \n");
  {
    GetTop(S, &e);
    printf("栈顶元素的值为: %d \n", e);
  }
  PressEnterToContinue(debug);

  printf("CleanStack: \n");
  {
    printf("清空S前: ");
    StackEmpty(S) ? printf("S为空!!\n") : printf("S不为空!!\n");

    CleanStack(&S);

    printf("清空S后: ");
    StackEmpty(S) ? printf("S为空!!\n") : printf("S不为空!!\n");
  }
  PressEnterToContinue(debug);

  printf("DestroyStack: \n");
  {
    printf("销毁S前: ");
    S.base && S.top ? printf("S存在!!\n") : printf("S不存在!!\n");

    DestroyStack(&S);

    printf("销毁S后: ");
    S.base && S.top ? printf("S存在!!\n") : printf("S不存在!!\n");
  }
  PressEnterToContinue(debug);
  
  return EXIT_SUCCESS;
}
