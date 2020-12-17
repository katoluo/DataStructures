#include "adjacency_matrix.cpp"

int main()
{
  AMGraph G;
  CreateUDN(G);
  PrintUDN(G);
  MiniSpanTree_Kruskal(G);
  return 0;
}
