/*
 * 线性表的链式存储结构
 *
 */ 

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../Status/Status.h"

typedef int ElemType;

/*
 * 单链表结构
 *
 * 注：规定单链表存在头节点
 */ 
typedef struct Node
{
  ElemType data;     // 结点的数据域
  struct Node *next; // 结点的指针域
} Node, *LinkedList; // LinkedList 为指向结构体Node的指针类型

 
Status InitList(LinkedList *L);
Status DestoryList(LinkedList *L);
Status CleanList(LinkedList L);
Status ListEmpty(LinkedList L);
int ListLength(LinkedList L);
Status GetElem(LinkedList L, int i, ElemType *e);
int LocateElem(LinkedList L, ElemType e, Status (*Compare)(ElemType, ElemType));
Status PriorElem(LinkedList L, ElemType cur_e, ElemType *pre_e);
Status NextElem(LinkedList L, ElemType cur_e, ElemType *next_e);
Status ListInsert(LinkedList L, int i, ElemType e);
Status ListDelete(LinkedList L, int i, ElemType *e);
void ListTraverse(LinkedList L, void (*Visit)(ElemType));
Status CreateList_Head(LinkedList *L, int n);
Status CreateList_Tail(LinkedList *L, int n);


#endif
