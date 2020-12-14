#include "adjacency_multilist.h"
#include <iostream>
int
LocateVertex(AMLGraph G, VertexType v)
{
  for (int i = 0; i != G.vertex_num; ++i)
    if (v == G.adjmulist[i].data) return i;
  return -1;
}

void
CreateUDG(AMLGraph &G)
{
  // 1. 确定无向图的总顶点数和总边数
  std::cout << "输入总顶点数和总边数：";
  std::cin >> G.vertex_num >> G.edgenum;

  // 2. 输入并初始化顶点向量
  for (int i = 0; i != G.vertex_num; ++i)
    std::cin >> G.adjmulist[i].data;

  // 3. 
}
