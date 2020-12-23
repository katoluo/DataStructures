#ifndef ADJACENCY_LISH
#define ADJACENCY_LISH

// 图的邻接表存储表示
#define MVNum 10 // 最大顶点数
#ifndef INT_MAX
#define INT_MAX 32767
#endif
typedef char VertexType; // 顶点的类型
typedef struct ArcNode // 边结点
{
  int adjvex; // 该边所指向的顶点的位置，即在顶点数组中的下标
  int weight; // 边的权值
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

void CreateUDG(ALGraph &G);
void CreateDG(ALGraph &G);
void CreateDN(ALGraph &G);
void DestroyGraph(ALGraph &G);

int LocateVex(ALGraph G, VertexType v);
void PrintAdjList(ALGraph G);

// 求图中顶点v的第一个邻接点，若有则返回顶点号；若v没有邻接点或图中不存在v，则返回-1
int FirstAdjVex(ALGraph G, VertexType v);
// 假设图G中顶点w是顶点v的一个邻接点，返回除w之外顶点v的下一个邻接点的顶点号，若w是v的最后一个邻接点，则返回-1
int NextAdjVex(ALGraph G, VertexType v, VertexType w);
// 广度优先搜索遍历连通图
void BFS(ALGraph G, VertexType v);
void BFSTravese(ALGraph G); // 非连通图

// 深度优先搜索遍历连通图
void DFS(ALGraph G, VertexType v);
void DFSTraverse(ALGraph G); // 非连通图

/* --------------------------------------------------最短路径------------------------------------------------------*/
// 利用BFS广度优先搜索算法求顶点u到其他顶点的最短路径
void BFS_Min_Distance(ALGraph G, VertexType u);

/*---------------------------------------------------拓扑排序-------------------------------------------------------*/
bool TopologicalSort(const ALGraph &G);

// 关键路径
bool CriticalPath(const ALGraph &G);

#endif
