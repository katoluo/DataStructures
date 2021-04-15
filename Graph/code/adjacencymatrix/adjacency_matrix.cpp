#include "adjacency_matrix.h"
#include <vector>
#include <algorithm>
#include <iostream>

/*--------------------------------------------------图的相关操作------------------------------------------------------------*/

int
LocateVex(const AMGraph &G, VertexType v) 
{
  for (int i = 0; i != G.vexnum; ++i)
    if (v == G.vexs[i]) return i;
  return -1;
}


void
Print(const AMGraph &G)
{
  for (int i = 0; i != G.vexnum; ++i) {
    for (int j = 0; j != G.vexnum; ++j)
      std::cout << "|" << G.arcs[i][j] << "\t";
    std::cout << std::endl;
  }
}


bool
InsertVex(AMGraph &G, VertexType v)
{
  // 判断当前顶点数是否小于最大顶点数
  if (G.vexnum >= MAX_VERTEX_NUM) return false;
  // 判断顶点v是否已经存在
  if (LocateVex(G, v) >= 0) return false;
  // 将顶点v保存到顶点表中，并将vexnum加1
  G.vexs[G.vexnum++] = v;
  return true;
}


bool
DeleteVex(AMGraph &G, VertexType v)
{
  // 判断顶点v是否存在
  int n = G.vexnum;
  int m = LocateVex(G, v);
  if (m < 0) return false;
  // 将最后的顶点覆盖待删除的顶点
  for (int i = 0; i != n; ++i) {
    // 将待删除的顶点列用最后一个顶点列覆盖，重置最后顶点列 
    int tmp = G.arcs[i][n-1];
    G.arcs[i][n-1] = INT_MAX;
    G.arcs[i][m-1] = tmp;
  }
  for (int i = 0; i != n; ++i) {
    int tmp = G.arcs[n-1][i];
    G.arcs[n-1][i] = INT_MAX;
    G.arcs[m-1][i] = tmp;
  }
  // 顶点表中交换位置
  VertexType w = G.vexs[n-1];
  G.vexs[n-1] = G.vexs[m-1];
  G.vexs[m-1] = w;
  // 更改顶点数
  --G.vexnum;
  
  return true;
}


/*---------------------------------------------------创建相关图或网-----------------------------------------------------*/

// 创建无向网
void
CreateUDN(AMGraph &G) 
{
  // 输入总顶点数和总边数
  std::cout << "输入总顶点数和总边数：";
  std::cin >> G.vexnum >> G.arcnum;
  // 依次输入点的信息存入顶点表中
  std::cout << "输入顶点序列：";
  for (int i = 0; i != G.vexnum; ++i)
    std::cin >> G.vexs[i];
  // 初始化邻接矩阵，是每个权值初始化为极大值
  for (int i = 0; i != G.vexnum; ++i)
    for (int j = 0; j != G.vexnum; ++j)
      G.arcs[i][j] = INT_MAX;
  /* 构造邻接矩阵。依次输入每条边依附的顶点和其权值，
   * 确定两个顶点在图中的位置之后，使相应边赋予相应的
   * 权值，同时使其对称边赋予相同的权值。
   */
  for (int k = 0; k != G.arcnum; ++k)
  {
    std::cout << "依次输入第" << k + 1 << "条边依附的顶点和权值(eg: v1 v2 10)：";
    VertexType v1, v2; ArcType w;
    std::cin >> v1 >> v2 >> w;
    int i = LocateVex(G, v1), j = LocateVex(G, v2);
    G.arcs[i][j] = w; G.arcs[j][i] = G.arcs[i][j];
  }
}


// 创建有向网
void
CreateDN(AMGraph &G)
{
  // 1. 先确定有向网的顶点数和边数
  std::cout << "输入总顶点数和总边数：";
  std::cin >> G.vexnum >> G.arcnum;
  // 2. 输入顶点标识字符 如：A B 
  std::cout << "输入顶点序列：";
  for (int i = 0; i != G.vexnum; ++i)
    std::cin >> G.vexs[i];
  // 3. 初始化邻接矩阵
  for (int i = 0; i != G.vexnum; ++i)
    for (int j = 0; j != G.vexnum; ++j)
      G.arcs[i][j] = INT_MAX;
  // 4. 输入各条边的具体信息，如：A B 10；表示弧尾为A，弧头为B，权值为10
  for (int i = 0; i != G.arcnum; ++i)
  {
    // 边的两个顶点
    VertexType v1, v2; 
    // 边的权值
    ArcType w; 
    // 输入边的信息
    std::cout << "输入第" << i+1 << "边的信息：";
    std::cin >> v1 >> v2 >> w;
    // 求v1 v2的对应的下标
    int j = LocateVex(G, v1);
    int k = LocateVex(G, v2);
    G.arcs[j][k] = w;
  } // for
}

/*------------------------------------------------最小生成树-------------------------------------------------*/

/*------------------普里姆算法-----------------*/
typedef struct
{
  VertexType adjvex; // 以closedge[]下标为目标顶点，在这次要连接到MST已连接的顶点所需最小权值的那个顶点
  ArcType lowcost; // 权值
}closedge[MAX_VERTEX_NUM];
closedge close;
int
Min(const AMGraph &G, closedge close)
{
  int min = INT_MAX;
  int min_i = -1;
  for (int i = 0; i != G.vexnum; ++i)
  {
    if (close[i].lowcost > 0 && close[i].lowcost < min)
    {
      min = close[i].lowcost;
      min_i = i;
    }
  }
  return min_i;
}
void
MiniSpanTree_Prim(const AMGraph &G, VertexType u)
{ // 无向网G以邻接矩阵存储形式存储，从顶点u出发构造G的最小生成树T，输出T的各条边
  int k = LocateVex(G, u); // k 为顶点u的下标
  for (int j = 0; j != G.vexnum; ++j) // 初始close数组
    if (j != k) close[j] = { G.vexs[k], G.arcs[k][j] }; // { adjvex, lowcost }
  close[k].lowcost = 0; // 初始，表示顶点u已经连接到T
  for (int i = 1; i != G.vexnum; ++i)
  { // 选择其余n-1个顶点，生成n-1条边
    k = Min(G, close); // 求出T的下一个结点：第k个顶点，close[k]中存在当前最小边
    VertexType u0 = close[k].adjvex; // u0为最小边的一个顶点，u0属于U，即u0已经连接到T了
    VertexType v0 = G.vexs[k]; // v0为最小边的另一个顶点，v0属于V-U，即将连接到T。
    std::cout << "(" << u0 << ", " << v0 << ")";
    std::cout <<"----权值为：" << close[k].lowcost << std::endl;
    close[k].lowcost = 0; // 将第k个顶点并入U集，即连接到T
    for (int j = 0; j != G.vexnum; ++j) // 新顶点并入U后重新选择最小边
      if (G.arcs[k][j] < close[j].lowcost) 
        // 因为每次大for循环，只连接一个新顶点到T，给其余未连接到T的顶点提供一个新的途径，
        // 就是第k个顶点到未连接的顶点的权值是否会小于当前close数组中的最小边的值
        close[j] = { G.vexs[k], G.arcs[k][j] };
  }
}


/*---------------------------------克鲁斯卡尔算法----------------------------------------*/

// 无向网G以邻接矩阵存储形式存储，构造G的最小生成树T，输出T的各条边
// 辅助数组
typedef struct Edge
{
  VertexType head; // 边的始点
  VertexType tail; // 边的终点
  ArcType lowcost; // 边的权值
} Edge;
void
MiniSpanTree_Kruskal(const AMGraph &G)
{
  std::vector<Edge> edges; // 辅助向量
  edges.reserve(G.arcnum); // 设置容量
  for (int i = 0; i != G.vexnum; ++i)
    for (int j = i + 1; j != G.vexnum; ++j)
    {
      if (G.arcs[i][j] != INT_MAX)
      {
        Edge edge = {
          .head = G.vexs[i],
          .tail = G.vexs[j],
          .lowcost = G.arcs[i][j]
        };
        edges.push_back(edge);
      }
    }
  std::sort(edges.begin(), edges.end(), 
      [](const Edge &a, const Edge &b)
      { return a.lowcost < b.lowcost; });

  // 标识各个顶点所属的连通分量
  int Vexset[G.vexnum];
  for (int i = 0; i != G.vexnum; ++i)
    Vexset[i] = i; // 表示一开始各个顶点自成一个连通分量

  for (int i = 0; i != G.arcnum; ++i) // 依次查看辅助向量中的边
  {
    int v1 = LocateVex(G, edges[i].head); // v1为边的始点的下标
    int v2 = LocateVex(G, edges[i].tail); // v2为边的终点的下标
    int vs1 = Vexset[v1]; // 获取该始点的连通分量
    int vs2 = Vexset[v2]; 
    if (vs1 != vs2)
    {
      // 输出此边
      std::cout << "(" << edges[i].head << "," << edges[i].tail << ")" << "----权值：" << edges[i].lowcost << std::endl;
      for (int j = 0; j != G.vexnum; ++j) // 合并vs1和vs2两个分量
        if (Vexset[j] == vs2) Vexset[j] = vs1; // 集合编号为vs2的都改为vs1
    } // if
  } // for
}



/*--------------------------------------------------最短路径-----------------------------------------------------*/

// 迪杰斯特拉算法求有向网G的顶点到其余顶点的最短路径
void ShortestPath_Dijkstra(const AMGraph &G, VertexType v0)
{
  // 算法的实现要引入以下辅助的数据结构

  // 记录从源点到各个顶点是否已经被确定最短路径长度
  bool S[G.vexnum]; 
  // 记录源点v0到终点的vi的当前最短路径上vi的直接前驱顶点序号
  int Path[G.vexnum];
  // 记录从源点v0到终点vi的当前最短路径长度
  int D[G.vexnum];
  // 初始化
  int v;
  for (v = 0; v != G.vexnum; ++v)
  {
    // S 初始为空集
    S[v] = false; 
    // 将v0到各个终点的最短路径长度初始化为弧上的权值
    int n = LocateVex(G, v0);
    D[v] = G.arcs[n][v];
    // 如果v0和v之间有弧，则将v的前驱置为v0；否则为-1
    Path[v] = D[v] < INT_MAX ? n : -1;
  } // for
  // 将v0加入S
  S[LocateVex(G, v0)] = true;
  // 源点到源点的距离为0
  D[LocateVex(G, v0)] = 0;

  // 初始化结束，开始主循环，每次求得v0到某个顶点v的最短路径，将v加到S集
  for (int i = 1; i != G.vexnum; ++i)
  {
    int min = INT_MAX;
    for (int w = 0; w != G.vexnum; ++w)
      if (!S[w] && D[w] < min)
        // 选择一条当前的最短路径，终点为v
        { v = w; min = D[w]; } 
    S[v] = true; // 将v加入S
    for (int w = 0; w != G.vexnum; ++w)
      // 更新从v0出发到集合V-S上所有顶点的最短路径长度
      if (!S[w] && (D[v] + G.arcs[v][w] < D[w]))
      {
        D[w] = D[v] + G.arcs[v][w]; // 更新D[w]
        Path[w] = v; // 更改w的前驱为v
      } // if
  } // for

  // 打印日志
  for (int i = 0; i != G.vexnum; ++i)
  {
    std::cout << "源点" << v0 << "到顶点" << G.vexs[i]
      << "的最短路径长度为：" << D[i] << std::endl;
  }
  for (auto i : Path)
    std::cout << i << " ";
  std::cout << std::endl;
}


// 用Floyd算法求有向网G中各对顶点i和j之间的最短路径
void ShortestPath_Floyd(const AMGraph &G)
{
  /* 算法的实现要引入以下辅助的数据结构 */

  // 最短路径上顶点vj的迁移顶点的序号
  int Path[G.vexnum][G.vexnum];
  // 记录顶点vi和vj之间的最短路径长度
  int D[G.vexnum][G.vexnum];

  // 各对结点之间初始已知路径及距离
  for (int i = 0; i != G.vexnum; ++i)
    for (int j = 0; j != G.vexnum; ++j)
    {
      D[i][j] = G.arcs[i][j];
      // 如果i和j之间有弧，则将j的前驱置为i
      // 否则，置为-1
      Path[i][j] = D[i][j] < INT_MAX ? i : -1;
    }

  for (int k = 0; k != G.vexnum; ++k)
    for (int i = 0; i != G.vexnum; ++i)
      for (int j = 0; j != G.vexnum; ++j)
        if (D[i][k] + D[k][j] < D[i][j]) // 从i经k到j的一条路径更短
        {
          D[i][j] = D[i][k] + D[k][j]; // 更新
          Path[i][j] = Path[k][j]; // 更改j的前驱为k
        } // if
}
