#ifndef __BINARY_SEARCH_TREE__
#define __BINARY_SEARCH_TREE__
#include <iostream>
#include <vector>
#include <queue>

using ElemType = int;
using BinarySearchTree = struct TreeNode*;
using Position = struct TreeNode*;
struct TreeNode {
  ElemType data;
  struct TreeNode *lchild;
  struct TreeNode *rchild;
  TreeNode() : data(0), lchild(nullptr), rchild(nullptr) {  }
  TreeNode(ElemType value) : data(value), lchild(nullptr), rchild(nullptr) {  }
};

void MakeEmpty(BinarySearchTree &T);

void SortedArrayToBinarySearchTree(BinarySearchTree &T); // 将有序数组转换为二叉排序树(二叉搜索树)

Position Find_Recursive(BinarySearchTree T, ElemType value); // 
Position Find_NonRecursive(BinarySearchTree T, ElemType value); // 

Position FindMin_Recursive(BinarySearchTree T);
Position FindMin_NonRecursive(BinarySearchTree T);

Position FindMax_Recursive(BinarySearchTree T);
Position FindMax_NonRecursive(BinarySearchTree T);

bool Insert(BinarySearchTree &T, ElemType value);
BinarySearchTree Insert_Leetcode(BinarySearchTree T, ElemType value);

void LevelOrderTraversal(BinarySearchTree T); // 层次遍历

#endif
