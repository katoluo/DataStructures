#include "adjacency_matrix.h"
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

