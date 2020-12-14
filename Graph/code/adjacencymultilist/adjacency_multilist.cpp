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

  // 3. 依次输入每条边依附的两个顶点，进行构建邻接多重表
  VertexType v1, v2;
  for (int k = 0; k != G.edgenum; ++k)
  {
    std::cout << "输入第" << k + 1 << "条边依附的两个顶点：";
    std::cin >> v1 >> v2;
    // 确定顶点v1 v2 在点向量中的位置
    int i = LocateVertex(G, v1);
    int j = LocateVertex(G, v2);

    EdgeBox *p = new EdgeBox;
    p->ivex = i;
    p->ilink = G.adjmulist[i].firstedge;
    G.adjmulist[i].firstedge = p;
    p->jvex = j;
    p->jlink = G.adjmulist[j].firstedge;
    G.adjmulist[j].firstedge = p;
  }
}
