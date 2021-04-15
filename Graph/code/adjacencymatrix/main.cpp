#include "adjacency_matrix.h"

int main()
{
  AMGraph G;
  //CreateUDN(G); // 创建无向网
  CreateDN(G);
  Print(G); // 打印
  ShortestPath_Dijkstra(G, 'A');
  //MiniSpanTree_Kruskal(G); // 克鲁斯卡尔算法求最小生成树
  return 0;
}
