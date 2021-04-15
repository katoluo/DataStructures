#include "BinarySearchTree.h"

int main(void)
{
  BinarySearchTree T;
  SortedArrayToBinarySearchTree(T);
  LevelOrderTraversal(T);
  BinarySearchTree root = Insert_Leetcode(T, 4);
  LevelOrderTraversal(root);

  MakeEmpty(T);
  return 0;
}
