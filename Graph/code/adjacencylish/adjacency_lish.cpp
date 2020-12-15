#include "adjacency_lish.h"
#include <cstdio>
#include <iostream>
#include <queue>

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

void DestroyGraph(ALGraph &G)
{
  for (int i = 0; i != G.vexnum; ++i) {
    for (ArcNode *p = G.vertices[i].firstarc; p != nullptr;
        p = G.vertices[i].firstarc) {
      G.vertices[i].firstarc = p->nextarc;
      delete p;
      p = nullptr;
    }
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

int FirstAdjVex(ALGraph G, VertexType v)
{
  if (LocateVex(G, v) == -1) return -1;
  return G.vertices[LocateVex(G, v)].firstarc->adjvex;
}

int NextAdjVex(ALGraph G, VertexType v, VertexType w)
{
  if (LocateVex(G, v) == -1) return -1;
  for (ArcNode *p = G.vertices[LocateVex(G, v)].firstarc;
      p != nullptr; p = p->nextarc)
  {
    if (p->adjvex == LocateVex(G, w))
    {
      if (p->nextarc == nullptr) return -1;
      else return p->nextarc->adjvex;
    }
  }
  return -1;
}

bool visited[MVNum];
void BFS(ALGraph G, VertexType v)
{
  // 从顶点v出发，访问v并置true
  std::cout << v << " ";
  visited[LocateVex(G, v)] = true;
  // 初始化队列，顶点v进队
  std::queue<VertexType> Queue;
  Queue.push(v);
  // 只要队列不空
  while (!Queue.empty())
  {
    VertexType u = Queue.front(); // 取得队头元素
    Queue.pop(); // 队头元素出队

    for (int w = FirstAdjVex(G, u); w >= 0;
        w = NextAdjVex(G, u, G.vertices[w].data))
    {
      if (!visited[w])
      {
        std::cout << G.vertices[w].data << " ";
        visited[w] = true;
        Queue.push(G.vertices[w].data);
      }
    }
  }
}

void BFSTravese(ALGraph G)
{
  for (int i = 0; i != G.vexnum; ++i)
    visited[i] = false;
  for (int i = 0; i != G.vexnum; ++i)
    if (!visited[i]) BFS(G, G.vertices[i].data);
}
