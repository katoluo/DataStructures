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
