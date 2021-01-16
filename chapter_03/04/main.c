#include "../LinkedStack/LinkedStack.h"
#include <string.h>


Status expr()
{
  LinkedStack S;
  InitStack(&S);
  char arr[10];

  char ch;
  int i = 0;
  float num1, num2, res;
  printf("正确输入后缀表达式: ");
  while (scanf("%c", &ch) && ch != '$')
  {
    while (ch >= '0' && ch <= '9' || ch == '.')
    {
      arr[i++] = ch;
      scanf("%c", &ch);
      if (ch == ' ') {
        float tmp = atof(arr);
        Push(&S, tmp);
        i = 0;
        memset(arr, '\0', sizeof(arr));
        break;
      }
    }
    if (ch == '+' || ch == '-' || ch == '*' || ch == '/')
    {
      Pop(&S, &num1); Pop(&S, &num2);
      switch (ch)
      {
        case '+':
          res = num1 + num2;
          Push(&S, res);
          break;
        case '-':
          res = num2 - num1;
          Push(&S, res);
          break;
        case '*':
          res = num1 * num2;
          Push(&S, res);
          break;
        case '/':
          res = num2 / num1;
          Push(&S, res);
          break;
      }
    }
  }
  Pop(&S, &res);
  printf("结果为: %f \n", res);
  return OK;
}


int main()
{
  expr();
  return 0;
}
