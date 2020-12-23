#include "adjacency_lish.h"

int main()
{
  ALGraph G;
  CreateUDG(G);
  PrintAdjList(G);
  BFS_Min_Distance(G, 'A');


  DestroyGraph(G);
  return 0;
}
