#ifndef ORTHOGONAL_LIST
#define ORTHOGONAL_LIST

#define MAX_VERTEX_NUM 10
typedef char VertexType;
typedef struct ArcBox
{
  int arc_tail_vertex; // 该弧尾的顶点的位置
  int arc_head_vertex; // 该弧头的顶点的位置
  struct ArcBox *point_to_next_same_arc_tail; // 指向弧尾相同的下一条弧的指针
  struct ArcBox *point_to_next_same_arc_head; // 指向弧头相同的下一条弧的指针
  //InfoType *info // 该弧相关信息的指针
} ArcBox;

typedef struct VertexNode
{
  VertexType data;
  ArcBox *firstin, *firstout; // 分别指向该顶点第一条入弧和出弧
} VertexNode;

typedef struct
{
  VertexNode VertexList[MAX_VERTEX_NUM]; // 表头向量
  int vertex_num; // 有向图的当前顶点数和弧数
  int arc_num;
} OLGraph;

int LocateVertex(OLGraph G, VertexType v);
void CreateDG(OLGraph &G);
void PrintDG(OLGraph G);

#endif
