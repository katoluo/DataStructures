#ifndef ADJACENCY_LISH
#define ADJACENCY_LISH

// 图的邻接表存储表示
#define MVNum 100 // 最大顶点数
typedef char VertexType; // 顶点的类型
typedef struct ArcNode // 边结点
{
  int adjvex; // 该边所指向的顶点的位置，即在顶点数组中的下标
  struct ArcNode *nextarc; // 指向下一条边的指针
  //OtherInfo info; // 和边相关的信息
} ArcNode;

typedef struct VNode // 顶点信息
{
  VertexType data;
  ArcNode *firstarc; // 指向第一条依附该顶点的边的指针
} VNode, AdjList[MVNum]; // AdjList表示邻接表类型

typedef struct
{
  AdjList vertices;
  int vexnum, arcnum; // 图的当前顶点数和边数
} ALGraph;

int LocateVex(ALGraph G, VertexType v);
void CreateUDG(ALGraph &G);
void PrintAdjList(ALGraph G);

#endif
