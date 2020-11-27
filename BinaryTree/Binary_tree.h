#ifndef __BINARY_TREE__
#define __BINARY_TREE__

#include <iostream>

using ElemType = char;
//typedef struct TreeNode *BinaryTree;
using BinaryTree = struct TreeNode*;
struct TreeNode {
  ElemType data;
  TreeNode *lchild;
  TreeNode *rchild;
  TreeNode() : data(0), lchild(nullptr), rchild(nullptr) {  }
  TreeNode(ElemType value) : data(value), lchild(nullptr), rchild(nullptr) {  }
};

/*-----------------------------------------------------------简单二叉树------------------------------------------------------*/

// 根据先序、中序、后序遍历的顺序建立二叉链表
void CreateBinaryTree_PreOrder_Recursive(BinaryTree &T);  // 先序->递归->建立
void CreateBinaryTree_InOrder_Recursive(BinaryTree &T);   // 中序->建立
void CreateBinaryTree_PostOrder_Recursive(BinaryTree &T); // 后序->建立

void CreateBinaryTree_PreOrder_NonRecursive(BinaryTree &T);  // 先序->非递归->建立
void CreateBinaryTree_InOrder_NonRecursive(BinaryTree &T);   // 中序->建立
void CreateBinaryTree_PostOrder_NonRecursive(BinaryTree &T); // 后序->建立

void CreateBinaryTree_LevelOrder(BinaryTree &T); // 层次遍历->建立

void Construct_BinaryTree_From_Preorder_Inorder_Traversal(BinaryTree &T); // 根据先序和中序遍历的序列构造二叉链表
void Construct_BinaryTree_From_Postorder_Inorder_Traversal(BinaryTree &T); // 根据后序和中序遍历的序列构造二叉链表

// 遍历二叉链表
void PreOrderTraversal_Recursive(const BinaryTree &T); // 递归的先序遍历
void InOrderTraversal_Recursive(const BinaryTree &T);
void PostOrderTraversal_Recursive(const BinaryTree &T);

void PreOrderTraversal_NonRecursive(const BinaryTree &T); // 显式使用栈的先序遍历
void InOrderTraversal_NonRecursive(const BinaryTree &T);
void PostOrderTraversal_NonRecursive(const BinaryTree &T);

void PreOrderTraversal_Morris(const BinaryTree &T); // Morris的先序遍历
void InOrderTraversal_Morris(const BinaryTree &T);
void PostOrderTraversal_Morris(const BinaryTree &T);

void LevelOrderTraversal(const BinaryTree &T); // 层次遍历

// 销毁二叉树  释放动态分配的内存
void Free(BinaryTree &T);


#endif
