#include <iostream>
#include "MGraph.h"

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


//对于连通的部分广度优先
void BFS(MGraph* G, int i) {
    std::queue<int> vexQueue;
    if(visited[i] != true) {
        vexQueue.push(i);
        visited[i] = true;
        while (!vexQueue.empty())
        {
            int headElement = vexQueue.front();
            //process node
            std::cout << G->vexs[headElement] << " ";
            vexQueue.pop();
            for (int j=0; j< G->numVertexs; j++) {
                if(G->arc[headElement][j] == 1 && !visited[j]) {
                    vexQueue.push(j);
                    visited[j] = true;
                }
            }
        }
        
    }
}
 //对于连通的部分深度优先
void DFS(MGraph* G, int i) {
    visited[i] = true;
    //process node
    std::cout<< G->vexs[i] <<" ";
    for(int j = 0; j < G->numVertexs; j++) {
        if (G->arc[i][j] == 1 && visited[j] != true) {
            DFS(G, j);
        }
    }
}
//深度遍历整个图的所有分量；
void DFSTraverse(MGraph* G) {
    int ConnectedComponent = 0; //连通分量个数
    for(int i =0; i< G->numVertexs; i++) {
        visited[i] = false;
    }
    for(int i=0; i < G->numVertexs; i++) {
        if(!visited[i]) {
            ConnectedComponent++;
             std::cout << std::endl;
            DFS(G, i);
           
        }
    }
    std::cout <<"\nconnection component : " << ConnectedComponent<<std::endl;
}
//广度遍历整个图的所有分量
void BFSTraverse(MGraph* G) {
    int ConnectedComponent = 0;
    //初始化visited
    for(int j=0; j< G->numVertexs; j++) {
        visited[j] =false;
    }
    for(int i =0; i< G->numVertexs; i++) {
        if (!visited[i]) {
            ConnectedComponent++;
            std::cout << std::endl;
        }
        BFS(G,i);
    }
    std::cout <<"\nconnection component : " << ConnectedComponent<<std::endl;
}
//获取任意结点的入度
int OutDegree(MGraph* G, int i) {
    int degree = 0;
    if (!G) return degree;
    for(int j = 0; j < G->numVertexs; j++) {
        if (G->arc[i][j] == 1) {
            degree++;
        }
    }
    return degree;
}
//获取任意结点的出度
int InDegree(MGraph* G, int i) {
    int degree=0;
    if(!G) return degree;
    for(int j = 0; j < G->numVertexs; j++) {
        if(G->arc[j][i] == 1) {
            degree++;
        }
    }
    return degree;
} 
int main() {
    MGraph G;
    CreateMGraph(&G);
    std::cout << "\nDFS from any vextex: ";
    DFS(&G,3);
    std::cout << "\nDFS Traver: ";
    DFSTraverse(&G);
    std::cout << "\nBFS: ";
    for( int i=0; i< G.numVertexs; i++) {
        visited[i] = false;
    }
    BFS(&G, 6);
    std::cout<< "\nBFS Traverse: ";
    BFSTraverse(&G);

    std::cout<< "\nDegree of Graph" << std::endl;
    std::cout << "in degree: " << InDegree(&G, 1) <<std::endl;
    std::cout << "out degree: " << OutDegree(&G, 1) << std::endl;
    return 0;
}