#include "../LinkedStack/LinkedStack.h"
#include <string.h>

Status Judge(char arr[])
{
  LinkedStack S;
  InitStack(&S);
  SElemType e;
  for (int i = 0; i != strlen(arr); ++i)
  {
    if (arr[i] == 'I') Push(&S, 1);
    else {
      if (StackEmpty(S) == TRUE) return FALSE;
      Pop(&S, &e);
    }
  }
  return StackEmpty(S) ? TRUE : FALSE;
}



int main(void)
{
  char arr[20];
  printf("输入操作序列: ");
  scanf("%s", arr);
  Judge(arr) ? printf("%s 为合法序列!\n", arr) : 
    printf("%s 为非法序列\n", arr);
  return 0;
}
