#include "Binary_tree.h"
#include <stack>
#include <vector>
#include <string>
#include <queue>

/*----------------------------------------------------------建立二叉树-------------------------------------------------------*/

// 根据先序和中序遍历的序列构造二叉链表
void
Construct_BinaryTree_From_Preorder_Inorder_Traversal(BinaryTree &T)
{
  std::string preorder; // 先序序列
  std::string inorder; // 中序序列
  std::cout << "先序序列："; std::cin >> preorder;
  std::cout << "中序序列："; std::cin >> inorder;

  std::cout << "输入是否正确?\n1.是\n2.否" << std::endl;
  int choice = 0;
  std::cin >> choice;
  if (!choice) return;

  std::stack<TreeNode*> stk;
  T = new TreeNode(preorder[0]);
  TreeNode *root = T;
  stk.push(root);

  int inorderIndex = 0;
  for (int i = 1; i != preorder.size(); ++i) { 
    // 判断preorder中每个元素preorderVal是否是栈顶元素的左孩子or某栈中节点的右孩子
    ElemType preorderVal = preorder[i];
    TreeNode *node = stk.top();
    if (node->data != inorder[inorderIndex]) {
      node->lchild = new TreeNode(preorderVal);
      stk.push(node->lchild);
    }
    else {
      while (!stk.empty() && stk.top()->data == inorder[inorderIndex]) {
        node = stk.top();
        stk.pop();
        ++inorderIndex;
      }
      node->rchild = new TreeNode(preorderVal);
      stk.push(node->rchild);
    }
  }
}




// 先序遍历的顺序递归建立二叉链表
void
CreateBinaryTree_PreOrder_Recursive(BinaryTree &T)
{
  ElemType ch;
  std::cin >> ch;
  if (ch == '#')
    T = nullptr;
  else
  {
    T = new TreeNode(ch);
    CreateBinaryTree_PreOrder_Recursive(T->lchild);
    CreateBinaryTree_PreOrder_Recursive(T->rchild);
  }
}

// 先序遍历的顺序非递归建立二叉链表
void
CreateBinaryTree_PreOrder_NonRecursive(BinaryTree &T)
{
  std::stack<TreeNode*> stk;
  std::string s;
  std::cout << "先序遍历的顺序非递归建立二叉链表：" << std::endl;
  std::cout << "序列(#表示空)：";
  std::cin >> s;

  if (s[0] == '#') return; // 因为是先序的，第一个char就是空，那只能是空树了

  TreeNode *p1, *p2; // 作为交换的媒介

  // 运行到这，表明不是空树，根据s[0]确定根节点
  p1 = new TreeNode(s[0]);
  p1->lchild = p1; // 指向自身表示该节点需要根据输入序列确定是否有孩子
  p1->rchild = p1;
  T = p1; // Root
  stk.push(T); // 进栈

  // 根节点确定之后，准备根据之后的序列确定二叉树的结构。
  int sz = s.size();
  int i = 0;
  while (!stk.empty() && i != sz - 1)
  {
    if (s[++i] != '#') {
      p2 = new TreeNode(s[i]);
      p2->lchild = p2;
      p2->rchild = p2;
    }
    else
      p2 = nullptr;

    p1 = stk.top();
    while (p1->lchild != p1 && p1->rchild != p1) { // 从栈顶开始找，把不需要孩子的节点都弹出来->以便寻找需要孩子的
      stk.pop();
      p1 = stk.top();
    }

    if (p1->lchild == p1) {  // 表明需要左孩子，将指向新创的节点
      p1->lchild = p2;
    }
    else {  // 否则需要右孩子
      p1->rchild = p2;
    }

    if (p2)
      stk.push(p2);
  }

}


// 根据层次遍历的顺序建立二叉链表
void CreateBinaryTree_LevelOrder(BinaryTree &T)
{
  std::string s; // 层次遍历的序列
  std::cout << "请输入层次遍历的序列(#表示空)：";
  std::cin >> s;

  if (s[0] == '#') return; // 以#开头视为空树

  T = new TreeNode(s[0]);
  auto root = T;

  std::queue<TreeNode*> q;
  q.push(root);
  
  int i = s.size();
  int k = 0;
  while (!q.empty() && k != i - 1) {
    root = q.front(); q.pop();
    if (s[++k] != '#') {
      root->lchild = new TreeNode(s[k]);
      q.push(root->lchild);
    }
    if (s[++k] != '#') {
      root->rchild = new TreeNode(s[k]);
      q.push(root->rchild);
    }
  }
}


/*-------------------------------------------------------递归的遍历二叉树----------------------------------------------------*/

// 先序遍历的递归算法
void
PreOrderTraversal_Recursive(const BinaryTree &T)
{
  if (!T) return; // 空树
  std::cout << T->data << " ";
  PreOrderTraversal_Recursive(T->lchild);
  PreOrderTraversal_Recursive(T->rchild);
}

// 中序遍历的递归算法
void
InOrderTraversal_Recursive(const BinaryTree &T)
{
  if (!T) return;
  InOrderTraversal_Recursive(T->lchild);
  std::cout << T->data << " ";
  InOrderTraversal_Recursive(T->rchild);
}

// 后序遍历的递归算法
void
PostOrderTraversal_Recursive(const BinaryTree &T)
{
  if(!T) return;
  PostOrderTraversal_Recursive(T->lchild);
  PostOrderTraversal_Recursive(T->rchild);
  std::cout << T->data << " ";
}

/*-----------------------------------------------------非递归的遍历二叉树----------------------------------------------------*/

// 非递归的先序遍历
void
PreOrderTraversal_NonRecursive(const BinaryTree &T)
{

  if (T == nullptr) // 空树
    return;

  std::stack<TreeNode*> s;
  TreeNode *root = T;

  while (!s.empty() || root != nullptr) {
    while (root) {
      std::cout << root->data << " ";
      s.push(root);
      root = root->lchild;
    }
    root = s.top();
    s.pop();
    root = root->rchild;
  }
  std::cout << std::endl;
}

// 非递归的中序遍历
void
InOrderTraversal_NonRecursive(const BinaryTree &T)
{
  std::stack<TreeNode*> s;
  auto p = T;
  TreeNode *q;
  while (p || !s.empty())
  {
    if (p) {   // 不为空，进栈，指向左孩子
      s.push(p);
      p = p->lchild;
    }
    else {
      q = s.top();  // 返回栈顶元素
      s.pop();      // 栈顶元素出栈
      std::cout << q->data << " ";  // 访问元素
      p = q->rchild;  // 指向右孩子
    }
  }
  std::cout << std::endl;
}

// 非递归的后序遍历
void 
PostOrderTraversal_NonRecursive(const BinaryTree &T)
{
  std::stack<TreeNode*> s;

  TreeNode *predecessor; // 前驱节点

  if (T == nullptr) return; // 空树

  TreeNode *root = T;
  while (root != nullptr || !s.empty()) {
    while (root != nullptr) {
      s.push(root);
      root = root->lchild;
    }
    root = s.top();
    s.pop();
    
    if (root->rchild == nullptr || root->rchild == predecessor) {
      std::cout << root->data << " ";
      predecessor = root;
      root = nullptr;
    }
    else {
      s.push(root);
      root = root->rchild;
    }
  }
  std::cout << std::endl;
}


// Morris 中序遍历
void
InOrderTraversal_Morris(const BinaryTree &T)
{
  TreeNode *predecessor; // root的前驱节点
  auto root = T;

  while (root != nullptr) { // 二叉树或左右二叉子树不为空
    if (root->lchild != nullptr) {
      /* 左二叉子树不为空，则说明root存在前驱节点，在访问root之前需要遍历完它的左二叉子树，
       * 然后再访问root，那么问题是如何指回root呢？左二叉子树最后一个访问的节点便为root的前驱节点，
       * 那么它必为左二叉子树中最右的节点，那么它的rchild == nullptr; 我们将它指向root节点，以便回到root，
       * 遍历它的右二叉子树. 我们设定：predecessor 为 root 的前驱节点
      */

      /* 在这个if块中，第一步：使用while找到root的前驱节点，predecessor指向前驱节点
       * 第二步：通过小if 初始化前驱节点，即前驱节点的右孩子指向root，
       * 因为这个时候还没有遍历完左二叉子树，所以继续遍历左二叉子树root = root->lchild
       * 第三步：通过小else 得知root的左二叉子树已经遍历完了，然后将前驱节点的右孩子置空，恢复到原来的二叉树结构
       * 然后访问root节点，之后遍历root的右二叉子树
       */
      predecessor = root->lchild; // 先让predecessor指向root的左二叉子树的根节点
      while (predecessor->rchild != nullptr && predecessor->rchild != root) // 然后通过while循环找到左二叉子树的最右的节点
        predecessor = predecessor->rchild; // 找到root的前驱节点了

      if (predecessor->rchild == nullptr) {
        predecessor->rchild = root; // 前驱节点的rchild指向root
        root = root->lchild;  // 继续遍历左子树
      }
      else { // 进入这个代码块表示root的前驱节点已经访问过了，接下来就访问根节点了，然后访问右子树
             // 还有很妙的一点是，它在这里顺便把链接置空，回复到原来的结构。
        std::cout << root->data << " "; // 访问
        predecessor->rchild = nullptr;
        root = root->rchild;
      }
    }
    else { // 没有左孩子，那直接访问就可以，然后访问右孩子。这便是中序遍历啦。
      std::cout << root->data << " ";
      root = root->rchild;
    }
  }

  std::cout << std::endl;
}


// 层次遍历
void LevelOrderTraversal(const BinaryTree &T)
{
  std::queue<TreeNode*> q;

  if (T == nullptr) return;

  TreeNode *root = T;

  q.push(root);
  while (!q.empty()) {
    root = q.front(); q.pop();
    std::cout << root->data << " ";
    if (root->lchild != nullptr) q.push(root->lchild);
    if (root->rchild != nullptr) q.push(root->rchild);
  }
  std::cout << std::endl;
}




// 销毁二叉树
void
Free(BinaryTree &T)
{
  if (T)
  {
    Free(T->lchild);
    Free(T->rchild);
    delete T;
    T = nullptr;
  }
}
