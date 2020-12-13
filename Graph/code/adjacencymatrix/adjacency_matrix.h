#ifndef ADJACENCY_MATRIX
#define ADJACENCY_MATRIX

#define MAX_INT 32767 // 表示极大值，无穷
#define MAX_VERTEX_NUM 100 // 最大顶点数
typedef char VertexType; // 假设顶点的数据类型为字符型
typedef int ArcType; // 假设边的权值类型为整型
typedef struct
{
  VertexType vexs[MAX_VERTEX_NUM]; // 顶点表
  ArcType arcs[MAX_VERTEX_NUM][MAX_VERTEX_NUM]; // 邻接矩阵
  int vexnum, arcnum; // 图的当前顶点数和边数
} AMGraph;

int LocateVex(AMGraph G, VertexType v);
void CreateUDN(AMGraph &G);
void PrintUDN(AMGraph G);

#endif
