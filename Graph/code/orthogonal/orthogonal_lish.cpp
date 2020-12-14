#include "orthogonal_lish.h"
#include <iostream>

int
LocateVertex(OLGraph G, VertexType v)
{
  for (int i = 0; i != G.vertex_num; ++i)
    if (v == G.VertexList[i].data)
      return i;
  return -1;
}


void
CreateDG(OLGraph &G)
{
  /* 1. 输入总顶点数和总边数
   * 2. 初始化顶点表
   * 3. 创建十字链表
   */
  std::cout << "输入总顶点数和总边数：";
  std::cin >> G.vertex_num >> G.arc_num;

  std::cout << "输入顶点序列：";
  for (int i = 0; i != G.vertex_num; ++i) {
    std::cin >> G.VertexList[i].data;
    G.VertexList[i].firstin = nullptr;
    G.VertexList[i].firstout = nullptr;
  }

  for (int k = 0; k != G.arc_num; ++k) {
    std::cout << "输入第" << k + 1 << "条边依附的两个顶点：";
    VertexType v1, v2;
    std::cin >> v1 >> v2;
    int i = LocateVertex(G, v1);
    int j = LocateVertex(G, v2);

    ArcBox *p1 = new ArcBox;
    p1->arc_tail_vertex = i;
    p1->point_to_next_same_arc_tail = G.VertexList[i].firstout;
    G.VertexList[i].firstout = p1;
    p1->arc_head_vertex = j;
    p1->point_to_next_same_arc_head = G.VertexList[j].firstin;
    G.VertexList[j].firstin = p1;
  }
}


void
PrintDG(OLGraph G)
{
  std::cout << "出弧：" << std::endl;
  for (int i = 0; i != G.vertex_num; ++i)
  {
    std::cout << i << " | " << G.VertexList[i].data;
    for (auto p = G.VertexList[i].firstout;
        p != nullptr; p = p->point_to_next_same_arc_tail)
    {
      std::cout << "--> |" << p->arc_tail_vertex
        << "|" << p->arc_head_vertex << "|";
    }
    std::cout << std::endl;
  }
  std::cout << "入弧：" << std::endl;
  for (int i = 0; i != G.vertex_num; ++i)
  {
    std::cout << i << " | " << G.VertexList[i].data;
    for (auto p = G.VertexList[i].firstin;
        p != nullptr; p = p->point_to_next_same_arc_head)
    {
      std::cout << "--> |" << p->arc_tail_vertex
        << "|" << p->arc_head_vertex << "|";
    }
    std::cout << std::endl;
  }
}
