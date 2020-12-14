#ifndef ADJACENCY_MULTILIST
#define ADJACENCY_MULTILIST

#define MAX_VERTEX_NUM 10
//typedef enum{unvisited, visited} VisitIf;
typedef char VertexType;
typedef struct EdgeBox
{
  //VisitIf mark; // 访问标记
  int ivex, jvex; // 该边依附的两个顶点的位置
  struct EdgeBox *ilink, *jlink; // 分别指向依附这两个顶点的下一条边
  //InfoType *info; // 该边信息指针
} EdgeBox;

typedef struct VertexBox
{
  VertexType data;
  EdgeBox *firstedge; // 指向第一条依附该顶点的边
} VertexBox;

typedef struct
{
  VertexBox adjmulist[MAX_VERTEX_NUM];
  int vertex_num, edgenum; // 无向图当前顶点数和边数
} AMLGraph;

int LocateVertex(AMLGraph G, VertexType v);
void CreateUDG(AMLGraph &G);
void PrintUDG(AMLGraph G);

#endif
