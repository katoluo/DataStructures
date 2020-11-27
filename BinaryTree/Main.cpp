#include "Binary_tree.h"
#include <cstdio>
#include <cstdlib>
#include <iostream>


void pause()
{
  std::cout << "按任意键继续..." << std::endl;
  std::system("read -s -n1");
}

void Menu();


int
main(void)
{
  int choice = 0;
  BinaryTree T = nullptr;
  bool flag = true;
  while (flag) {

    Menu();
    std::cin >> choice;
    switch (choice) {
      case 1:
        std::system("clear");
        std::cout << "先序遍历的顺序建立二叉树(use Recursive)" << std::endl;
        std::cout << "序列：";
        CreateBinaryTree_PreOrder_Recursive(T);
        pause();
        std::system("clear");
        break;
      case 2:
        std::system("clear");
        std::cout << "先序遍历的顺序建立二叉树(use Stack)" << std::endl;
        std::cout << "序列：";
        CreateBinaryTree_PreOrder_NonRecursive(T);
        pause();
        std::system("clear");
        break;

      case 3:
        std::system("clear");
        std::cout << "先序遍历的顺序(use Recursive)：";
        PreOrderTraversal_Recursive(T);
        std::cout << std::endl;
        pause();
        std::system("clear");
        break;

      case 4:
        std::system("clear");
        std::cout << "先序遍历的顺序(非递归)：";
        PreOrderTraversal_NonRecursive(T);
        pause();
        std::system("clear");
        break;

      case 5:
        break;

      case 06:
        std::system("clear");
        std::cout << "中序遍历的顺序(递归)：";
        InOrderTraversal_Recursive(T);
        std::cout << std::endl;
        pause();
        std::system("clear");
        break;

      case 07:
        std::system("clear");
        std::cout << "中序遍历的顺序(非递归)：";
        InOrderTraversal_NonRecursive(T);
        pause();
        std::system("clear");
        break;

      case 8:
        std::system("clear");
        std::cout << "中序遍历的顺序(Morris遍历)：";
        InOrderTraversal_Morris(T);
        pause();
        std::system("clear");
        break;

      case 9:
        std::system("clear");
        std::cout << "后序遍历的顺序(递归)：";
        PostOrderTraversal_Recursive(T);
        std::cout << std::endl;
        pause();
        std::system("clear");
        break;

      case 10:
        std::system("clear");
        std::cout << "后序遍历的顺序(非递归)：";
        PostOrderTraversal_NonRecursive(T);
        pause();
        std::system("clear");
        break;

      case 11:
        //std::system("clear");
        //std::cout << "后序遍历的顺序(Morris遍历)：";
        //PostOrderTraversal_Morris(T);
        //std::cout << std::endl;
        //pause();
        //std::system("clear");
        break;


      case 12:
        std::system("clear");
        if (T != nullptr) {
          Free(T);
          std::cout << "销毁成功..." << std::endl;
        }
        else
          std::cout << "销毁失败，为空树..." << std::endl;
        pause();
        break;
      case 13:
        std::system("clear");
        if (T != nullptr) {
          std::cout << "二叉树T还未销毁，销毁之后才能退出。\n是否销毁？\n"
                    << "1. 是\n"
                    << "0. 否" << std::endl;
          int choice = 0;
          std::cin >> choice;
          pause();
          if (!choice){
            std::system("clear");
            break;
          }
        }
        flag = false;
        std::system("clear");
        std::cout << "欢迎下次使用..." << std::endl;
        pause();
        std::system("clear");
        break;
      case 14:
        std::system("clear");
        std::cout << "层次遍历：";
        LevelOrderTraversal(T);
        pause();
        std::system("clear");
        break;
      case 15:
        std::system("clear");
        CreateBinaryTree_LevelOrder(T);
        pause();
        std::system("clear");
        break;
      default:
        std::system("clear");
        std::cout << "请重新输入正确的选择！" << std::endl;
        pause();
        std::system("clear");
    }
  }


  return 0;
}



void Menu()
{
  std::system("clear");
  std::cout << "二叉树的操作集：\n"
            << "**********************************************\n"
            << "01. 先序遍历的顺序建立二叉树(Recursive)\n"
            << "02. 先序遍历的顺序建立二叉树(use Stack)\n"
            << "15. 层次遍历的顺序建立二叉树\n"
            << "**********************************************\n"
            << "03. 先序遍历二叉树(use Recursive)\n"
            << "04. 先序遍历二叉树(use Stack)\n"
            << "05. 先序遍历二叉树(use Morris)\n"
            << "06. 中序遍历二叉树(use Recursive)\n"
            << "07. 中序遍历二叉树(use Stack)\n"
            << "08. 中序遍历二叉树(use Morris)\n"
            << "09. 后序遍历二叉树(use Recursive)\n"
            << "10. 后序遍历二叉树(use Stack)\n"
            << "11. 后序遍历二叉树(use Morris)\n"
            << "14. 层次遍历\n"
            << "**********************************************\n"
            << "12. 销毁二叉树\n"
            << "13. 退出\n"
            <<
  std::endl;
}
