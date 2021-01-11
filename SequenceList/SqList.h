#ifndef SQLIST_H
#define SQLIST_H

#include <stdio.h>
#include <stdlib.h> // 提供malloc、realloc、free、exit等原型
#include "../Status/Status.h"

#define LIST_INIT_SIZE 100
#define LISTINCREMENT 10

typedef int ElemType;

/*
 * 顺序表结构
 *
 */
typedef struct
{
  ElemType *elem;
  int length;   // 当前顺序表的长度
  int listsize; // 当前顺序表的量
} SqList;

/*
 * 初始化序表
 *
 * 初始化成功则返回OK，否则返回ERROR
 */
Status InitList(SqList *L);

/*
 * 销毁序表
 *
 * 释放顺序表所占内存
 */
Status DestoryList(SqList *L);

/*
 * 清空顺序表
 *
 * 只是清空顺序表中存储的数据，不释放内存
 */
Status CleanList(SqList *L);

/*
 * 判断顺序表是否为空
 *
 * 返回值：
 * TRUE: 顺序表为空
 * FALSE: 顺序表不为空
 *
 * 不需要改变顺序表，不需要传指针参数
 */
Status ListEmpty(SqList L);

/*
 * 计算顺序表的长度
 *
 */
int ListLength(SqList L);

/*
 * 取值
 *
 * 获取顺序表中第i个元素，将其存储到e中
 * 找到返回OK，否则返回ERROR
 *
 * 备注：
 * 教材中的含义是元素位置，从1开始计数，但这不符合编码的通用约定
 * 通常，i的含义应该索引，即从0开始计数
 */
Status GetElem(SqList L, int i, ElemType *e);

/*
 * 查找
 *
 * 返回顺序表中首个与e满足Compare关系的元素位序
 * 如果不存在这样的元素，则返回0
 */
int LocateElem(SqList L, ElemType e, Status(Compare)(ElemType, ElemType));

/*
 * 前驱
 *
 * 获取元素cur_e的前驱，
 * 如果存在，将其存储到pre_e中，返回OK，
 * 如果不存在，则返回ERROR
 */
Status PriorElem(SqList L, ElemType cur_e, ElemType *pre_e);

/*
 * 后继
 *
 * 获取元素cur_e的后继，
 * 如果存在，将其存储到next_e中，返回OK，
 * 如果不存在，则返回ERROR
 */
Status NextElem(SqList L, ElemType cur_e, ElemType *next_e);

/*
 * 插入
 *
 * 向顺序表第i个位置插入e,插入成功则返回OK，否则返回ERROR
 *
 * 备注：
 * 教材中i的含义是元素位置，从1开始计数
 */
Status ListInsert(SqList *L, int i, ElemType e);

/*
 * 删除
 *
 * 删除顺序表第i个位置上的元素，并将被删除元素存储到e中
 * 删除成功则返回OK，否则返回ERROR
 *
 * 备注：
 * 教材中i的含义是元素位置，从1开始计数
 */
Status ListDelete(SqList *L, int i, ElemType *e);

/*
 * 遍历
 *
 * 用visit函数访问顺序表L
 */
void ListTraverse(SqList L, void (*Visit)(ElemType));

#endif
