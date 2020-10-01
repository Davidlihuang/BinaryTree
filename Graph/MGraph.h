#ifndef MGRAPH_H_
#define MGRAPH_H_
#include <iostream>
using VertexType = char;
using EdgeType = int;
const int MaxVetex = 100;
const int INFINITY = 65535;

//无向图
VertexType v[] = {'A', 'B', 'C', 'D'};
EdgeType E[][4] = {
    {INFINITY,1,1,INFINITY},
    {1, INFINITY, 1, 1},
    {1,1,INFINITY,1},
    {INFINITY, 1, 1, INFINITY}
};

struct MGraph{
    VertexType vexs[MaxVetex];
    EdgeType arc[MaxVetex][MaxVetex];
    int numVertexs;
    int numEdges;
    MGraph():numVertexs(0),numEdges(0){}
};


void CreateMGraph(MGraph* G) {
    G->numVertexs = sizeof(v)/sizeof(VertexType);
    for (int i = 0; i < G->numVertexs; i++) {
        G->vexs[i] = v[i];
        for(int j =0; j < G->numVertexs; j++) {
            G->arc[i][j] = E[i][j];
            if(E[i][j] == 1) G->numEdges++;
        }
    }
    G->numEdges /= 2;
}

void BFS(MGraph* G, VertexType vex); //对于连通的部分广度优先
void DFS(MGraph* G, VertexType vex); //对于连通的部分深度优先

void BFSTraverse(MGraph* G, VertexType vex); //广度遍历整个图的所有分量；
void DFSTraverse(MGraph* G, VertexType vex); //深度遍历整个图的所有分量；


#endif
