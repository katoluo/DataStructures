#include "adjacency_matrix.cpp"

int main()
{
  AMGraph G;
  CreateUDN(G);
  PrintUDN(G);
  MiniSpanTree_Prim(G, 'A');
  return 0;
}
