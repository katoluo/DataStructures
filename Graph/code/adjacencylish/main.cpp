#include "adjacency_lish.cpp"
#include "adjacency_lish.h"

int main()
{
  ALGraph G;
  CreateUDG(G);
  PrintAdjList(G);
  DFS(G, 'A');

  DestroyGraph(G);
  return 0;
}
