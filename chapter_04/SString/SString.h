#ifndef SSTRING_H
#define SSTRING_H

#include <stdio.h>
#include <string.h>
#include "../Status/Status.h"

// --------- 串的定长顺序存储结构 ------------
#define MAXLEN 255
/*
 * 串的顺序存储类型定义
 *
 * 注:
 * 有效元素从SString的1号索引开始存储(注意位序与索引的区别)
 * SString的0号索引存储串的长度
 */
typedef unsigned char SString[MAXLEN + 1];

Status StringAssign(SString T, const char *chars);
Status DestoryString(SString S);
Status ClearString(SString S);
Status StringEmpty(SString S);
int StringLength(SString S);
Status SubString(SString Sub, SString S, int pos, int len);
int Index_1(SString S, SString T, int pos);
int Index_2(SString S, SString T, int pos);
Status StringInsert(SString S, int pos, SString T);
Status StringDelete(SString S, int pos, int len);
int StringCompare(SString S, SString T);
Status StringCopy(SString T, SString S);
Status Replace(SString S, SString T, SString V);
Status Concat(SString T, SString S1, SString S2);


#endif
