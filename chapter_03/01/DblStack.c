#include "./DblStack.h"

Status InitStatck(DblStack *S)
{
  if (S == NULL) return ERROR;
  S->V = (SElemType*)malloc(sizeof(SElemType) * MAXSIZE);
  if (S->V == NULL) exit(OVERFLOW);
  S->m = MAXSIZE;
  S->bot[0] = -1; S->bot[1] = S->m;
  S->top[0] = -1; S->top[1] = S->m;
  return OK;
}


Status DestoryStack(DblStack *S)
{
  if (S == NULL || S->V == NULL) return ERROR;
  free(S->V);
  S->V = NULL;
  return OK;
}


Status Stack_i_Empty(DblStack S, int i)
{
  return S.bot[i] == S.top[i] ? TRUE : FALSE;
}


Status StackEmpty(DblStack S)
{
  //if (S.bot[0] == S.top[0] && S.bot[1] == S.top[1]) return TRUE;
  //else return FALSE;
  //return S.bot[0] == S.top[0] && S.bot[1] == S.top[1] ? TRUE : FALSE;
  return Stack_i_Empty(S, 0) && Stack_i_Empty(S, 1) ? TRUE : FALSE;
}


Status StackFull(DblStack S)
{
  if ((S.top[0] - S.bot[0]) + (S.bot[1] - S.top[1]) == S.m)
    return TRUE;
  else return FALSE;
}


Status Push(DblStack *S, int i, SElemType e)
{
  if (S == NULL || S->V == NULL) return ERROR;
  if (StackFull(*S) == TRUE) return ERROR;
  i ? --S->top[i] : ++S->top[i];
  S->V[S->top[i]] = e;
  return OK;
}


Status Pop(DblStack *S, int i, SElemType *e)
{
  if (S == NULL || S->V == NULL) return ERROR;
  if (Stack_i_Empty(*S, i) == TRUE) return ERROR;
  *e = S->V[S->top[i]];
  i ? ++S->top[i] : --S->top[i];
  return OK;
}


Status StackTraverse(DblStack S, void (*Visit)(SElemType))
{
  if (S.V == NULL) return ERROR;
  printf("Stack 0: ");
  for (int i = 0; i <= S.top[0]; ++i)
    Visit(S.V[i]);
  putchar('\n');
  printf("Stack 1: ");
  for (int i = S.m - 1; i >= S.top[1]; --i)
    Visit(S.V[i]);
  putchar('\n');
  return OK;
}
