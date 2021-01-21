/*
 * 串的定长顺序存储结构
 *
 */
#include "./SString.h"

/*
 * 初始条件: chars是字符串常量
 * 操作结果: 生成一个其值等于chars的串T
 *
 */
Status
StringAssign(SString T, const char *chars)
{
  int i, len;
  
  len = (int)strlen(chars);         // 检查chars长度是否超出容量
  if ( len > MAXLEN ) return ERROR; 

  T[0] = len;                       // 0号索引存放字符串长度
  for (i = 1; i <= len; ++i) T[i] = chars[i - 1];

  return OK;
}



/*
 * 初始条件: 串S存在
 * 操作结果: 串S被销毁
 *
 * 注: 定长顺序串的结构无法销毁
 */
Status
DestoryString(SString S)
{
  return OK;
}



/*
 * 初始条件: 串S存在
 * 操作结果: 将S清为空串
 *
 */
Status
ClearString(SString S)
{
  S[0] = 0; 
  return OK;
}



/*
 * 初始条件: 串S存在
 * 操作结果: 若S为空串，则返回TRUE，否则返回FALSE
 *
 */
Status
StringEmpty(SString S)
{
  return S[0] == 0 ? TRUE : FALSE;
}



/*
 * 初始条件: 串S存在
 * 操作结果: 返回S的元素个数，称为串的长度
 *
 */
int
StringLength(SString S)
{
  return S[0];
}



/*
 * 初始条件: 串S存在，1 <= pos <= StringLength(S)
 *                    0 <= len <= StringLength(S) - pos + 1
 * 操作结果: 用Sub返回串S的第pos个字符起长度为len的字串
 *
 */
Status
SubString(SString Sub, SString S, int pos, int len)
{
  int i;

  if (pos < 1 || pos > S[0] || len < 0 || pos + len - 1 > S[0])
    return ERROR;

  for (i = 1; i <= len; ++i) Sub[i] = S[pos + i - 1];

  S[0] = len;

  return OK;
}



/*
 * 查找
 *
 * 从pos出开始搜索模式串T在主串S中首次出现的位置
 * 如果不存在，则返回0
 * 如果查找成功，返回匹配的位置
 *
 * 注:
 * 1. 此实现需要依赖串的最小操作子集
 * 2. 该实现比较低效
 */
int
Index_1(SString S, SString T, int pos)
{
  int i, n, m;
  SString sub;

  if (pos < 0 || pos > S[0] || StringEmpty(T)) return 0;

  n = StringLength(S);
  m = StringLength(T);
  i = pos;

  while ( i <= n - m + 1 )
  {
    SubString(sub, S, i, m);

    if (StringCompare(sub, T) != 0) ++i;
    else return i;
  }

  return 0;
}


/*
 * 查找
 *
 * 从pos出开始搜索模式串T在主串S中首次出现的位置
 * 如果不存在，则返回0
 * 如果查找成功，返回匹配的位置
 *
 * 注:
 * 1. 此实现不需要依赖串的最小操作子集
 * 2. 该实现比较低效
 */
int
Index_2(SString S, SString T, int pos)
{
  int i, j;

  if (pos < 1 || pos > S[0] || StringEmpty(T)) return 0;

  i = pos; j = 1;
  while (i <= S[0] && j <= T[0])
  {
    if (S[i] == T[j]) {
      ++i;
      ++j;

    } else {
      i = i - ( j - 1 ) + 1;
      j = 1;

    }
  }

  if (j > T[0] && T[0] > 0) return i - T[0];
  else return 0;
}



/*
 * 插入
 *
 * 将串T插入到主串S的pos位置处
 *
 */
Status StringInsert(SString S, int pos, SString T)
{
  int i;

  if (pos < 1 || pos > S[0] + 1 || S[0] + T[0] > MAXLEN)
    return ERROR;

  if (StringEmpty(T)) return OK;

  for (i = S[0]; i >= pos; --i)
    S[i + T[0]] = S[i];

  for (i = pos; i <= pos + T[0] - 1; ++i)
    S[i] = T[i - pos + 1];

  S[0] += T[0];

  return OK;
}
