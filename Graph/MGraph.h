#ifndef MGRAPH_H_
#define MGRAPH_H_
#include <iostream>
#include <queue>
using VertexType = char;
using EdgeType = int;
const int MaxVetex = 100;
const int INFINITY = 65535;

//无向图
VertexType v[] = {'A', 'B', 'C', 'D', 'E','F','G'};
EdgeType E[][7] = {
    {0, 1, 1, 0, 0, 0, 0},
    {1, 0, 1, 1, 0, 0, 0},
    {1, 1, 0, 1, 0, 0, 0},
    {0, 1, 1, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 1, 1},
    {0, 0, 0, 0, 1, 0, 1},
    {0, 0, 0, 0, 1, 1, 0},
};
bool visited[MaxVetex]{};

struct MGraph{
    VertexType vexs[MaxVetex];
    EdgeType arc[MaxVetex][MaxVetex];
    int numVertexs;
    int numEdges;
    MGraph():numVertexs(0),numEdges(0){}
};


void CreateMGraph(MGraph* G);  
void BFS(MGraph* G, int i);    //对于连通的部分广度优先
void BFSTraverse(MGraph* G);   //广度优先遍历所有连通分量
void DFS(MGraph* G, int i);    //深度优先遍历单一连通分量；
void DFSTraverse(MGraph* G);   //深度优先遍历整个图的所有分量
int InDegree(MGraph* G, int i); //获取任意结点的入度
int OutDegree(MGraph* G, int i); //获取任意结点的出度




#endif
