#include "adjacency_lish.h"
#include <cstdio>
#include <iostream>
#include <queue>
#include <stack>
#include <algorithm>

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

/*----------------------------------------------以邻接表储方式创建相关图或网------------------------------------------------*/
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

// 创建有向图
void CreateDG(ALGraph &G)
{
  // 获取有向图的总顶点数和总边数
  std::cout << "输入有向图的总顶点数和总边数：";
  std::cin >> G.vexnum >> G.arcnum;
  // 获取顶点序列
  std::cout << "输入顶点序列：";
  for (int i = 0; i != G.vexnum; ++i) {
    std::cin >> G.vertices[i].data;
    G.vertices[i].firstarc = nullptr;
  }
  // 输入各条边的信息
  VertexType v1, v2;
  for (int k = 0; k != G.arcnum; ++k) {
    std::cout << "输入第" << k+1 << "条有向边依附的两个顶点：";
    std::cin >> v1 >> v2;
    int i = LocateVex(G, v1);
    int j = LocateVex(G, v2);
    ArcNode *p = new ArcNode;
    p->adjvex = j;
    p->nextarc = G.vertices[i].firstarc;
    G.vertices[i].firstarc = p;
  }
}

// 创建有向网
void CreateDN(ALGraph &G)
{
  // 输入有向网的总顶点数和总边数
  std::cout << "输入有向网的总顶点数和总边数：";
  std::cin >> G.vexnum >> G.arcnum;
  // 输入有向网的顶点序列
  std::cout << "输入有向网的顶点序列：";
  for (int i = 0; i != G.vexnum; ++i) {
    std::cin >> G.vertices[i].data;
    G.vertices[i].firstarc = nullptr;
  }
  // 输入各条边的信息 v1 v2 weight
  VertexType v1, v2;
  int weight = 0;
  for (int k = 0; k != G.arcnum; ++k) {
    std::cout << "输入第" << k+1 << "条弧依附的顶点和权值：";
    std::cin >> v1 >> v2 >> weight;
    int i = LocateVex(G, v1);
    int j = LocateVex(G, v2);
    ArcNode *p = new ArcNode;
    p->weight = weight;
    p->adjvex = j;
    p->nextarc = G.vertices[i].firstarc;
    G.vertices[i].firstarc = p;
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

void DFS(ALGraph G, VertexType v)
{
  // 初始化栈，顶点v进栈
  std::stack<VertexType> stk;
  stk.push(v);
  // 当栈不为空
  while (!stk.empty())
  {
    VertexType u = stk.top();
    int i = LocateVex(G, u);
    if (!visited[i]) // 没有被访问
    {
      std::cout << G.vertices[i].data << " ";
      visited[i] = true;      
    }
    for (ArcNode *p = G.vertices[i].firstarc;
          p != nullptr; p = p->nextarc)
    {
      if (!visited[p->adjvex])
      {
        stk.push(G.vertices[p->adjvex].data);
        break;
      }
      if (p->nextarc == nullptr) stk.pop();
    }
  }
  std::cout << std::endl;
}

void DFSTraverse(ALGraph G)
{
  for (int i = 0; i != G.vexnum; ++i)
    visited[i] = false;
  for (int i = 0; i != G.vexnum; ++i)
  {
    if (!visited[i]) DFS(G, G.vertices[i].data);
  }
}



/*-----------------------------------------------------最短路径问题----------------------------------------------------*/

// 求顶点u到其他顶点的最短路径
void BFS_Min_Distance(ALGraph G, VertexType u)
{
  // 辅助队列
  std::queue<VertexType> q; 
  // 辅助数组，对应顶点是否已经访问，初始化为false
  bool visited[G.vexnum]; 
  std::fill(visited, visited + G.vexnum, false);
  // 顶点u到各个顶点的路径长度数组，初始化为INT_MAX
  int distance[G.vexnum];
  std::fill(distance, distance + G.vexnum, INT_MAX);
  // 顶点u到自身的距离为0
  distance[LocateVex(G, u)] = 0;
  // 顶点u入队，并标为已访问
  q.push(u); 
  visited[LocateVex(G, u)] = true;
  // BFS算法主过程
  while (!q.empty())
  {
    // 得队头元素，并出队
    VertexType v = q.front(); q.pop();
    for (int w = FirstAdjVex(G, v); w >= 0;
        w = NextAdjVex(G, v, G.vertices[w].data))
      if (!visited[w])
      {
        distance[w] = distance[LocateVex(G, v)] + 1;
        visited[w] = true;
        q.push(G.vertices[w].data);
      } // if
  } // while
  // 打印日志
  for (int i = 0; i != G.vexnum; ++i)
  {
    std::cout << "顶点" << u << "到顶点" << G.vertices[i].data 
      << "的路径长度为：" << distance[i] << std::endl;
  }
}


/*--------------------------------------------------------拓扑排序----------------------------------------------------------*/
// 算法实现要引入以下辅助的数据结构
int indegree[MVNum] = {0}; // 存放各顶点的入度
std::stack<VertexType> s; // 暂存所有入度为0的顶点
VertexType topo[MVNum]; // 记录拓扑序列的顶点
// 求出各顶点的入度存入数组indegree中
void FindIndegree(const ALGraph &G, int indegree[])
{
  for (int i = 0; i != G.vexnum; ++i) {
    for (ArcNode *p = G.vertices[i].firstarc; p != nullptr;
        p = p->nextarc)
      indegree[p->adjvex] = indegree[p->adjvex] + 1;
  }
}

bool TopologicalSort(const ALGraph &G)
{ // 有向图G采用邻接表存储结构
  // 若G无回路，则生成G的一个拓扑序列并返回true，否则false
  FindIndegree(G, indegree);
  // 遍历indegree组，入度为零的顶点进栈
  for (int i = 0; i != G.vexnum; ++i)
    if (indegree[i] == 0) 
      s.push(G.vertices[i].data); 
  // 输出顶点的计数器初始为0
  int count = 0;
  // 栈不为空时
  while (!s.empty()) {
    // 取得栈顶元素并出栈
    VertexType v = s.top(); s.pop();
    // 将v保存在拓扑序列数组中
    topo[count++] = v;
    ArcNode *p = G.vertices[LocateVex(G, v)].firstarc;
    while (p != nullptr) {
      if (--indegree[p->adjvex] == 0)
        s.push(G.vertices[p->adjvex].data);
      p = p->nextarc;
    } // while
  } // while
  if (count != G.vexnum) return false;
  else return true;
}

/*-------------------------------------------------------关键路径-----------------------------------------------------------*/
// 算法的实现要引入辅助的数据结构
// 一维数组ve[i]:事件vi的最早发生时间
int ve[MVNum];
// 一维数组vl[i]:事件vi的最迟发生时间
int vl[MVNum];

bool CriticalPath(const ALGraph &G)
{ // G为邻接表存储的有向网，输出G的各项关键活动
  // 调用拓扑排序算法，使拓扑序列保存在topo中，若调用失败，则存在有向环，返回false
  if (!TopologicalSort(G)) return false;
  // 给每个事件的最早发生时间置初值0
  for (int i = 0; i != G.vexnum; ++i) ve[i] = 0;
/*-----------------------按拓扑次序求每个时间的最早发生时间-----------------------------*/
  for (int i = 0; i != G.vexnum; ++i) {
    // 取得拓扑序列中的顶点序号k
    int k = LocateVex(G, topo[i]);
    // p 指向k的第一个邻接顶点
    ArcNode *p = G.vertices[k].firstarc;
    while (p != nullptr) {
      // 依次更新k的所有邻接顶点的最早发生时间
      // j为邻接顶点的序号
      int j = p->adjvex;
      if (ve[j] < ve[k]+p->weight) ve[j]=ve[k]+p->weight;
      p = p->nextarc; // p指向k的下一个邻接顶点
    } // while
  } // for
  // 给每个事件的最迟发生时间置初值ve[G.vexnum-1]
  for (int i = 0; i != G.vexnum; ++i)
    vl[i] = ve[G.vexnum-1];
/*-------------按逆拓扑次序求每个事件的最迟发生时间--------------------------------------------*/
  for (int i = G.vexnum-1; i >= 0; --i) {
    // 取得拓扑序列中的顶点序号k
    int k = LocateVex(G, topo[i]);
    ArcNode *p = G.vertices[k].firstarc;
    while (p != nullptr) {
      // 根据k的邻接点，更新k的最迟发生时间
      // j为邻接顶点的序号
      int j = p->adjvex;
      // 更新顶点k的最迟发生时间vl[k]
      if (vl[k] > vl[j] - p->weight)
        vl[k] = vl[j] - p->weight;
      // p指向k的下一个邻接顶点
      p = p->nextarc;
    } // while
  } // for
/*--------------判断每一活动是否为关键活动---------------------------------------*/
  // 每次循环针对vi为活动开始点的所有活动
  for (int i = 0; i != G.vexnum; ++i) {
    // p指向i的第一个邻接顶点
    ArcNode *p = G.vertices[i].firstarc;
    while (p != nullptr) {
      // j 为i的邻接顶点的序号
      int j = p->adjvex;
      // 计算活动<vi,vj>的最早开始时间
      int e = ve[i]; 
      // 计算活动<vi,vj>的最迟开始时间
      int l = vl[j] - p->weight;
      // 若为关键活动，则输出<vi,vj>
      if (e == l) 
        std::cout << G.vertices[i].data << "->"
          << G.vertices[j].data << " 为关键活动" << std::endl;
      p = p->nextarc;
    } // while
  } // for
  return true;
}
