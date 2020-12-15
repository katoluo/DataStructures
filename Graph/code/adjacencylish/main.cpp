#include "adjacency_lish.cpp"

int main()
{
  ALGraph G;
  CreateUDG(G);
  PrintAdjList(G);
  BFS(G, 'A');

  DestroyGraph(G);
  return 0;
}
