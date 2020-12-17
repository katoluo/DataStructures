#include "adjacency_matrix.h"
#include <vector>
#include <algorithm>
#include <iostream>

int
LocateVex(AMGraph G, VertexType v) {
  for (int i = 0; i != G.vexnum; ++i)
    if (v == G.vexs[i]) return i;
  return -1;
}

void
CreateUDN(AMGraph &G) {
  // 输入总顶点数和总边数
  std::cout << "输入总顶点数和总边数：";
  std::cin >> G.vexnum >> G.arcnum;
  // 依次输入点的信息存入顶点表中
  std::cout << "输入顶点序列：";
  for (int i = 0; i != G.vexnum; ++i)
    std::cin >> G.vexs[i];
  // 初始化邻接矩阵，是每个权值初始化为极大值
  for (int i = 0; i != G.vexnum; ++i)
    for (int j = 0; j != G.vexnum; ++j)
      G.arcs[i][j] = MAX_INT;
  /* 构造邻接矩阵。依次输入每条边依附的顶点和其权值，
   * 确定两个顶点在图中的位置之后，使相应边赋予相应的
   * 权值，同时使其对称边赋予相同的权值。
   */
  for (int k = 0; k != G.arcnum; ++k)
  {
    std::cout << "依次输入第" << k + 1 << "条边依附的顶点和权值(eg: v1 v2 10)：";
    VertexType v1, v2; ArcType w;
    std::cin >> v1 >> v2 >> w;
    int i = LocateVex(G, v1), j = LocateVex(G, v2);
    G.arcs[i][j] = w; G.arcs[j][i] = G.arcs[i][j];
  }
}

void
PrintUDN(AMGraph G)
{
  for (int i = 0; i != G.vexnum; ++i) {
    for (int j = 0; j != G.vexnum; ++j)
      std::cout << "|" << G.arcs[i][j] << "\t";
    std::cout << std::endl;
  }
}

typedef struct
{
  VertexType adjvex; // 以closedge[]下标为目标顶点，在这次要连接到MST已连接的顶点所需最小权值的那个顶点
  ArcType lowcost; // 权值
}closedge[MAX_VERTEX_NUM];
closedge close;
int
Min(AMGraph G, closedge close)
{
  int min = MAX_INT;
  int min_i = -1;
  for (int i = 0; i != G.vexnum; ++i)
  {
    if (close[i].lowcost > 0 && close[i].lowcost < min)
    {
      min = close[i].lowcost;
      min_i = i;
    }
  }
  return min_i;
}
void
MiniSpanTree_Prim(AMGraph G, VertexType u)
{ // 无向网G以邻接矩阵存储形式存储，从顶点u出发构造G的最小生成树T，输出T的各条边
  int k = LocateVex(G, u); // k 为顶点u的下标
  for (int j = 0; j != G.vexnum; ++j) // 初始close数组
    if (j != k) close[j] = { G.vexs[k], G.arcs[k][j] }; // { adjvex, lowcost }
  close[k].lowcost = 0; // 初始，表示顶点u已经连接到T
  for (int i = 1; i != G.vexnum; ++i)
  { // 选择其余n-1个顶点，生成n-1条边
    k = Min(G, close); // 求出T的下一个结点：第k个顶点，close[k]中存在当前最小边
    VertexType u0 = close[k].adjvex; // u0为最小边的一个顶点，u0属于U，即u0已经连接到T了
    VertexType v0 = G.vexs[k]; // v0为最小边的另一个顶点，v0属于V-U，即将连接到T。
    std::cout << "(" << u0 << ", " << v0 << ")";
    std::cout <<"----权值为：" << close[k].lowcost << std::endl;
    close[k].lowcost = 0; // 将第k个顶点并入U集，即连接到T
    for (int j = 0; j != G.vexnum; ++j) // 新顶点并入U后重新选择最小边
      if (G.arcs[k][j] < close[j].lowcost) 
        // 因为每次大for循环，只连接一个新顶点到T，给其余未连接到T的顶点提供一个新的途径，
        // 就是第k个顶点到未连接的顶点的权值是否会小于当前close数组中的最小边的值
        close[j] = { G.vexs[k], G.arcs[k][j] };
  }
}

// 无向网G以邻接矩阵存储形式存储，构造G的最小生成树T，输出T的各条边
// 辅助数组
typedef struct Edge
{
  VertexType head; // 边的始点
  VertexType tail; // 边的终点
  ArcType lowcost; // 边的权值
} Edge;
void
MiniSpanTree_Kruskal(AMGraph G)
{
  std::vector<Edge> edges; // 辅助向量
  edges.reserve(G.arcnum); // 设置容量
  for (int i = 0; i != G.vexnum; ++i)
    for (int j = i + 1; j != G.vexnum; ++j)
    {
      if (G.arcs[i][j] != MAX_INT)
      {
        Edge edge = {
          .head = G.vexs[i],
          .tail = G.vexs[j],
          .lowcost = G.arcs[i][j]
        };
        edges.push_back(edge);
      }
    }
  std::sort(edges.begin(), edges.end(), 
      [](const Edge &a, const Edge &b)
      { return a.lowcost < b.lowcost; });

  // 标识各个顶点所属的连通分量
  int Vexset[G.vexnum];
  for (int i = 0; i != G.vexnum; ++i)
    Vexset[i] = i; // 表示一开始各个顶点自成一个连通分量

  for (int i = 0; i != G.arcnum; ++i) // 依次查看辅助向量中的边
  {
    int v1 = LocateVex(G, edges[i].head); // v1为边的始点的下标
    int v2 = LocateVex(G, edges[i].tail); // v2为边的终点的下标
    int vs1 = Vexset[v1]; // 获取该始点的连通分量
    int vs2 = Vexset[v2]; 
    if (vs1 != vs2)
    {
      // 输出此边
      std::cout << "(" << edges[i].head << "," << edges[i].tail << ")" << "----权值：" << edges[i].lowcost << std::endl;
      for (int j = 0; j != G.vexnum; ++j) // 合并vs1和vs2两个分量
        if (Vexset[j] == vs2) Vexset[j] = vs1; // 集合编号为vs2的都改为vs1
    } // if
  } // for
}
