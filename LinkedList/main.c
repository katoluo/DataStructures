#include "LinkedList.h"
#include "../Status/Status.h"

// 判断data>e是否成立
Status ComGreater(ElemType data, ElemType e)
{
  return data > e ? TRUE : FALSE;
}


// 测试函数，打印元素
void PrintElem(ElemType e)
{
  printf("%d ", e);
}


int main(int argc, char *argv[])
{
  LinkedList L;
  int i;
  ElemType e;

  /************************************************************/
  printf("InitList: \n");
  {
    printf("初始化单链表 L ...\n");
    InitList(&L);
  }
  PressEnterToContinue(debug);



  /************************************************************/
  printf("ListEmpty: \n");
  {
    ListEmpty(L) ? printf("L为空!!\n") : printf("L不为空!!\n");
  }
  PressEnterToContinue(debug);


  /************************************************************/
  printf("LinstInsert: \n");
  {
    for (int i = 1; i <= 8; ++i) {
      printf("在L第%d个位置插入 \"%d\" ...\n", i, i * 2);
      ListInsert(L, i, i * 2);
    }
  }
  PressEnterToContinue(debug);


  /************************************************************/
  printf("ListTraverse: \n");
  {
    printf("L中的元素为: ");
    ListTraverse(L, PrintElem);
  }
  PressEnterToContinue(debug);


  /************************************************************/
  printf("ListLength: \n");
  {
    printf("L的长度为%d\n", ListLength(L));
  }
  PressEnterToContinue(debug);


  /************************************************************/
  printf("ListDelete: \n");
  {
    printf("删除前L的元素: ");
    ListTraverse(L, PrintElem);

    printf("尝试删除L中第6个元素...\n");

    if (ListDelete(L, 6, &e) == OK)
      printf("删除成功，被删除的元素是: %d\n", e);
    else
      printf("删除失败，第6个元素不存在!\n");

    printf("删除后L的元素: ");
    ListTraverse(L, PrintElem);
  }
  PressEnterToContinue(debug);


  /************************************************************/
  printf("GetElem: \n");
  {
    GetElem(L, 4, &e);
    printf("L中第4个位置的元素为: %d\n", e);
  }
  PressEnterToContinue(debug);


  /************************************************************/
  printf("LocateElem: \n");
  {
    i = LocateElem(L, 7, ComGreater);
    GetElem(L, i, &e);
    printf("L中第一个大于 7 的元素是: %d\n", e);
  }
  PressEnterToContinue(debug);



  /************************************************************/
  printf("PriorElem: \n");
  {
    ElemType cur_e = 6;

    if (PriorElem(L, cur_e, &e) == OK)
      printf("元素 %d 的前驱为: %d\n", cur_e, e);
    else
      printf("元素 %d 的前驱不存在!\n", cur_e);
  }
  PressEnterToContinue(debug);


  /************************************************************/
  printf("NextElem: \n");
  {
    ElemType cur_e = 6;

    if (NextElem(L, cur_e, &e) == OK)
      printf("元素 %d 的后继为: %d\n", cur_e, e);
    else
      printf("元素 %d 的后继不存在!\n", cur_e);
  }
  PressEnterToContinue(debug);



  /************************************************************/
  printf("CleanList: \n");
  {
    printf("清空L前: ");
    ListEmpty(L) ? printf("L为空!!\n") : printf("L不为空!!\n");

    CleanList(L);

    printf("清空L后: ");
    ListEmpty(L) ? printf("L为空!!\n") : printf("L不为空!!\n");
  }
  PressEnterToContinue(debug);


  /************************************************************/
  printf("DestoryList: \n");
  {
    printf("销毁L前: ");
    L ? printf("L存在!!\n") : printf("L不存在!!\n");

    DestoryList(&L);

    printf("销毁L后: ");
    L ? printf("L存在!!\n") : printf("L不存在!!\n");
  }
  PressEnterToContinue(debug);


  /************************************************************/
  printf("\nCreateList_Head: \n");
  {
    LinkedList L;
    CreateList_Head(&L, 5);
    printf("头插法创建单链表L = ");
    ListTraverse(L, PrintElem);
    DestoryList(&L);
  }
  PressEnterToContinue(debug);


  /************************************************************/
  printf("\nCreateList_Tail: \n");
  {
    LinkedList L;
    CreateList_Tail(&L, 5);
    printf("尾插法创建单链表L = ");
    ListTraverse(L, PrintElem);
    DestoryList(&L);
  }
  PressEnterToContinue(debug);
  printf("\n");

  return 0;
}
