#include "BinarySearchTree.h"
#include <climits>


void
MakeEmpty(BinarySearchTree &T)
{
  if (T != nullptr) {
    MakeEmpty(T->lchild);
    MakeEmpty(T->rchild);
    free(T);
    T = nullptr;
  }
  return;
}

/*----------------------------------------------将有序数组转换为二叉排序树-------------------------------------------------*/
TreeNode* helper(const std::vector<ElemType>& nums, int left, int right) {
  if (left > right)
    return nullptr;
  int mid = (left + right) / 2;
  
  TreeNode* root = new TreeNode(nums[mid]);
  root->lchild = helper(nums, left, mid-1);
  root->rchild = helper(nums, mid+1, right);
  return root;
}

void SortedArrayToBinarySearchTree(BinarySearchTree &T)
{
  // 初始化有序数组
  std::vector<ElemType> v;
  ElemType val = 0;
  std::cout << "有序数组(end for q)：";
  while (std::cin >> val) {
    v.push_back(val);
  }
  T = helper(v, 0, v.size() - 1);
}


/*----------------------------------------------二叉排序树的查找-------------------------------------------------*/
// 递归查找
Position
Find_Recursive(BinarySearchTree T, ElemType value)
{
  if (T == nullptr) return nullptr;
  if (T->data == value) return T;
  else if (T->data < value) return Find_Recursive(T->lchild, value);
  else return Find_Recursive(T->rchild, value);
}


// 非递归查找
Position
Find_NonRecursive(BinarySearchTree T, ElemType value)
{
  TreeNode* root = T;
  while (root != nullptr) {
    if (root->data == value) return root;
    else if (root->data < value) root = root->lchild;
    else root = root->rchild;
  }
  return root;
}


Position
FindMin_Recursive(BinarySearchTree T)
{
  if (T == nullptr) return nullptr;
  if (T->lchild == nullptr) return T;
  else return FindMin_Recursive(T->lchild);
}

Position
FindMin_NonRecursive(BinarySearchTree T)
{
  if (T == nullptr) return nullptr;
  while (T->lchild != nullptr) {
    T = T->lchild;
  }
  return T;
}

Position
FindMax_Recursive(BinarySearchTree T)
{
  if (T == nullptr) return nullptr;
  if (T->rchild == nullptr) return T;
  else return FindMax_Recursive(T->rchild);
}

Position
FindMax_NonRecursive(BinarySearchTree T)
{
  if (T == nullptr) return nullptr;
  while (T->rchild != nullptr) {
    T = T->rchild;
  }
  return T;
}

/*------------------------------------------------------------插入------------------------------------------------------*/
bool
Insert(BinarySearchTree &T, ElemType value)
{
  if (T == nullptr) {
    T = new TreeNode(value);
    return true;
  }
  else if (T->data == value) return false;
  else if (T->data > value) return Insert(T->lchild, value);
  else return Insert(T->rchild, value);
}

// Leetcode: 701. 二叉搜索树中的插入操作
BinarySearchTree
Insert_Leetcode(BinarySearchTree T, ElemType value)
{

  if (T == nullptr) return new TreeNode(value);

  TreeNode *node = T;
  while (node != nullptr) {
    if (node->data > value) {
      if (node->lchild == nullptr) {
        node->lchild = new TreeNode(value);
        break;
      }
      else
        node = node->lchild;
    }
    else if (node->data < value) {
      if (node->rchild == nullptr) {
        node->rchild = new TreeNode(value);
        break;
      }
      else
        node = node->rchild;
    }
  }
  return T;
}


/*---------------------------------------------------------遍历------------------------------------------------------------*/
void
LevelOrderTraversal(BinarySearchTree T)
{
  std::queue<TreeNode*> q;
  if (T == nullptr) return;
  q.push(T);
  while (!q.empty()) {
    auto root = q.front(); q.pop();
    std ::cout << root->data << " ";
    if (root->lchild != nullptr) q.push(root->lchild);
    if (root->rchild != nullptr) q.push(root->rchild);
  }
  std::cout << std::endl;
}
