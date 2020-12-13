#include "adjacency_lish.h"
#include <cstdio>
#include <iostream>

// 若图G中存在顶点v，则返回v在图中的位置信息，否则返回其他信息
int LocateVex(ALGraph G, VertexType v)
{
  for (int i = 0; i != G.vexnum; ++i)
    if (G.vertices[i].data == v) return i;
  return -1;
}

void Clear()
{
  while (std::getchar() != '\n');
}

// 采用邻接表表示法创建无向图
void CreateUDG(ALGraph &G)
{
  std::cout << "接表表示法创建无向图。\n依次输入总顶点数和总边数：";
  std::cin >> G.vexnum >> G.arcnum;
  Clear();
  // 创建表头节点表
  std::cout << "请输入顶点值的序列：";
  for (int i = 0; i != G.vexnum; ++i) {
    std::cin >> G.vertices[i].data;
    G.vertices[i].firstarc = nullptr;
  }
  Clear();
  // 创建边表
  VertexType v1, v2; // 两个顶点确定一条边
  for (int k = 0; k != G.arcnum; ++k) {
    std::cout << "请输入第" << k + 1 << "条边依附的两个顶点：";
    std::cin >> v1 >> v2;
    Clear();
    // 确定v1和v2在G中位置，即顶点在G.vertices中的序号
    int i = LocateVex(G, v1);
    int j = LocateVex(G, v2);
    // 头插法创建边链表
    ArcNode *p1 = new ArcNode; // 生成一个新的边结点*p1
    p1->adjvex = j; // 邻接点序号为j
    p1->nextarc = G.vertices[i].firstarc;
    G.vertices[i].firstarc = p1;

    ArcNode *p2 = new ArcNode;
    p2->adjvex = i;
    p2->nextarc = G.vertices[j].firstarc;
    G.vertices[j].firstarc = p2;
  }
}


void PrintAdjList(ALGraph G)
{
  for (int i = 0; i != G.vexnum; ++i) {
    std::cout << i << " | " << G.vertices[i].data << " |";
    for (auto p = G.vertices[i].firstarc; p != nullptr; p = p->nextarc)
      std::cout << "-->| " << p->adjvex << " |";
    std::cout << std::endl;
  }
}


