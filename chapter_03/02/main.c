#include "../LinkedStack/LinkedStack.h"
#include <string.h>

Status Palindrome(char str[])
{
  LinkedStack S;
  SElemType e;
  InitStack(&S);

  int size = (int)strlen(str);
  // eg: size = 3, half = 2; size = 4, half = 2;
  int half = size & 01 ? (size / 2) + 1 : size / 2;
  for (int i = 0; i != half; ++i)
    Push(&S, str[i]);
  half = size & 01 ? half : half + 1;
  while (StackEmpty(S) != TRUE) {
    Pop(&S, &e);
    if (e != str[half-1]) return FALSE;
    half += 1;
  }

  //DestoryStack(&S); // Pop会自动销毁结点
  return TRUE;
}



int main(void)
{
  char str[20];
  printf("输入需要判定的字符序列: ");
  scanf("%s", str);

  Palindrome(str) ? printf("%s 是回文!!\n", str)
    : printf("%s 不是回文!!\n", str);
  
  return 0;
}
