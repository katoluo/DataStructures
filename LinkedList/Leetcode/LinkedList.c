#include "LinkedList.h"

/***************************************************************
 * 初始化
 *
 * 知识初始化一个头结点
 * 初始化成功则返回OK，否则返回ERROR
 ***************************************************************/
Status InitList(LinkedList *L)
{
  (*L) = (Node*)malloc(sizeof(Node));
  if (*L == NULL)
    exit(OVERFLOW);

  (*L)->next = NULL;

  return OK;
}


/***************************************************************
 * 销毁(结构)
 *
 * 释放链表所占内存，头结点也会被清理
 * 成功时返回OK，失败时返回ERROR
 */
Status DestoryList(LinkedList *L)
{
  // 确保链表结构存在
  if (L == NULL || *L == NULL)
    return ERROR;

  Node *p = *L;

  while (p != NULL)
  {
    p = (*L)->next;
    free(*L);
    (*L) = p;
  }

  *L = NULL;

  return OK;
}



/***************************************************************
 * 置空(内容)
 *
 * 这里需要释放链表中非头结点处的空间
 ***************************************************************/ 
Status CleanList(LinkedList L)
{
  // 确保链表结构存在
  if (L == NULL)
    return ERROR;

  Node *p = L->next; // p指向首元结点
  Node *pre;

  // 释放链表上所有结点所占内存(除头结点)
  while (p != NULL) {
    pre = p;
    p = p->next;
    free(pre);
  }

  L->next = NULL;

  return OK;
}



/***************************************************************
 * 判断是否为空链表
 *
 * 若空返回TRUE
 * 否则返回FALSE
 ***************************************************************/ 
Status ListEmpty(LinkedList L)
{
  // 链表只有头结点时，认为该链表为空
  if (L != NULL && L->next == NULL)
    return TRUE;
  else
    return FALSE;
}



/***************************************************************
 * 链表长度
 *
 * 返回链表包含的有效元素的数量
 ***************************************************************/
int ListLength(LinkedList L)
{
  if (ListEmpty(L))
    return 0;

  Node *p = L->next; // p指向首元结点
  int count = 0;

  // 遍历所有结点
  while (p != NULL) {
    ++count;
    p = p->next;
  }

  return count;
}



/***************************************************************
 * 取值
 *
 * 获取链表中第i个元素，将其保存到e中
 * 找到返回OK
 * 否则返回ERROR
 *
 * 注：i为位置，从1开始
 ***************************************************************/
Status GetElem(LinkedList L, int i, ElemType *e)
{
  if (ListEmpty(L))
    return ERROR;

  Node *p = L->next; // p指向首元结点
  int count = 1;     // 计数器初值赋值为1

  // 顺链域向后扫描，知道p为空或p指向第i个元素
  while (p != NULL && count < i) {
    ++count;
    p = p->next;
  }

  if (p == NULL || count > i)
    return ERROR;

  *e = p->data;

  return OK;
}



/***************************************************************
 * 查找
 *
 * 返回链表中首个与e满足Compare关系的元素位序(位序从1开始)
 * 如果不存在这样的元素，则返回0
 *
 * 注：元素e是Compare函数的第二个形参
 ***************************************************************/ 
int LocateElem(LinkedList L, ElemType e, Status (*Compare)(ElemType, ElemType))
{
  if (ListEmpty(L))
    return 0;

  int i = 1;           // i的初值为第一个元素的位序
  Node *p = L->next;   // p指向首元结点

  while (p != NULL && !Compare(p->data, e)) {
    ++i;
    p = p->next;
  }

  if (p != NULL)
    return i;
  else
    return 0; // 没有找到
}



/***************************************************************
 * 前驱
 *
 * 获取元素cur_e的前驱
 * 如果存在，将其保存到pre_e中，返回OK
 * 否则，返回ERROR
 ***************************************************************/
Status PriorElem(LinkedList L, ElemType cur_e, ElemType *pre_e)
{
  if (ListEmpty(L))
    return ERROR;

  Node *pre = L->next;   // 指向第1个结点
  
  // 第1个结点没有前驱
  if (pre->data == cur_e)
    return ERROR;

  Node *next = pre->next; // 指向第2个结点

  // 从第2个结点开始，查找cur_e的位置
  while (next != NULL && next->data != cur_e) {
    pre = next;
    next = next->next;
  }

  // 不存在cur_e，查找失败，返回ERROR
  if (next == NULL)
    return ERROR;

  *pre_e = pre->data;

  return OK;
}



/***************************************************************
 * 后继
 *
 * 获取元素cur_e的后继
 * 如果存在，将其保存到next_e中，返回OK
 * 否则，返回ERROR
 ***************************************************************/
Status NextElem(LinkedList L, ElemType cur_e, ElemType *next_e)
{
  if (ListEmpty(L))
    return ERROR;

  Node *pre = L->next;     // 指向首元结点

  // 从第1个元素开始，查找cur_e的within，且保证该结点的后继不为NULL
  while (pre->next != NULL && pre->data != cur_e)
    pre = pre->next;

  // 没找到cur_e，或者找到了，但是没有后继，返回ERROR
  if (pre->next == NULL)
    return ERROR;

  *next_e = pre->next->data;

  return OK;
}



/***************************************************************
 * 插入
 *
 * 想链表第i个位置上插入e
 * 插入成功则返回OK
 * 否则返回ERROR
 *
 * 备注：
 * 教材中i的含义是元素的位置，从1开始计数
 ***************************************************************/
Status ListInsert(LinkedList L, int i, ElemType e)
{
  // 确保链表存在，但不要求是否为空表
  if (L == NULL)
    return ERROR;

  Node *p = L;    // p指向头结点
  int j = 0;      // 计数器从0开始

  // 寻找第i-1个结点，且保证该结点本身不为NULL
  while (p != NULL && (j < i - 1)) {
    p = p->next;
    ++j;
  }

  // 这里j不能等于i-1，不然当i=1时能插入
  if (p == NULL || j > i - 1)
    return ERROR;

  // 生成新结点
  Node *q = (Node*)malloc(sizeof(Node));
  if (q == NULL)
    exit(OVERFLOW);
  q->data = e;
  q->next = p->next;
  p->next = q;

  return OK;
}



/***************************************************************
 * 删除
 *
 * 删除链表第i个位置上的元素，并将被删除元素存储到e中
 * 成功时返回OK，失败时返回ERROR
 *
 * 备注：
 * 教材中i的含义是元素的位置，从1开始计数
 ****************************************************************/
Status ListDelete(LinkedList L, int i, ElemType *e)
{
  // 确保链表存在且不为空链表
  if (L == NULL || L->next == NULL)
    return ERROR;

  Node *p;     // 最终指向第i-1个结点(如果成功的话)
  Node *q;
  int count;     // 计数器

  p = L; 
  count = 0;     // 计数器从0开始

  // 寻找第i-1个结点，且保证该结点的后继不为NULL
  while (p->next != NULL && count < i - 1) {
    ++count;
    p = p->next;
  }

  if (p->next == NULL || count > i - 1)
    return ERROR;

 q = p->next;       // 指向第i个结点
 *e = q->data;

 p->next = q->next;
 free(q);

 return OK;
}



/***************************************************************
 * 遍历
 *
 * 用Visit函数访问链表L
 ***************************************************************/
void ListTraverse(LinkedList L, void (*Visit)(ElemType))
{
  Node *p;

  if (ListEmpty(L))   // 若链表不存在或为空链表
    return;

  p = L->next;        // p指向首元结点

  while (p != NULL) {
    Visit(p->data);
    p = p->next;
  }

  printf("\n");
}




/***************************************************************
 * 头插法创建链表
 *
 * 备注：
 * 教材中默认从控制台读取数据
 ***************************************************************/
Status CreateList_Head(LinkedList *L, int n)
{
  // 建立头结点
  *L = (Node*)malloc(sizeof(Node));
  if (*L == NULL)
    exit(OVERFLOW);
  (*L)->next = NULL;

  printf("请输入%d个降序元素: ", n);

  for (int i = 0; i != n; ++i) {
    // 生成新结点
    Node *p = (Node*)malloc(sizeof(Node));
    if (p == NULL)
      exit(OVERFLOW);
    
    // 从标准输入获取数据
    scanf("%d", &(p->data));
    
    // 插入链表中
    p->next = (*L)->next;
    (*L)->next = p;
  }

  return OK;
}



/***************************************************************
 * 尾插法创建链表
 *
 * 备注：
 * 教材中默认从控制台读取数据
 ***************************************************************/
Status CreateList_Tail(LinkedList *L, int n)
{
  // 创建头结点
  *L = (Node*)malloc(sizeof(Node));
  if (*L == NULL)
    exit(OVERFLOW);
  (*L)->next = NULL;

  printf("请输入%d个升序元素: ", n);

  Node *p, *q;
  int i;
  for (i = 0, q = *L; i != n; ++i) {
    // 生成新结点
    p = (Node*)malloc(sizeof(Node));
    if (p == NULL)
      exit(OVERFLOW);
    
    // 从标准输入获取数据
    scanf("%d", &(p->data));

    q->next = p;
    q = q->next;
  }

  q->next = NULL;

  return OK;
}
















