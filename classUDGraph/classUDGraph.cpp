#include <bits/stdc++.h>
using namespace std;

#define MAX_VEX_NUM 20
#define INFINITY 2147483647

class UDGraph {
    private:
        int vexNum;
        int edgeNum;
        char vexs[MAX_VEX_NUM];
        int adjMatrix[MAX_VEX_NUM][MAX_VEX_NUM];
    
    public:
        bool createUDG(UDGraph &G);
        int locateVex(UDGraph &G, char v);
        void BFS();
        void DFS();    

};

bool UDGraph::createUDG(UDGraph &G) {
    char v1,v2;
    cin >> G.vexNum >> G.edgeNum;
    for (int i = 0; i < G.vexNum; i++) {
        cin >> G.vexs[i];
    }
    //初始化邻接矩阵为正无穷
    for (int i = 0; i < G.vexNum; i++) {
        for (int j = 0; j < G.vexNum; j++) {
            G.adjMatrix[i][j] = INFINITY;
        }
    }
    //构造邻接矩阵
    for (int k = 0; k < G.edgeNum; k++) {
        cin >> v1 >> v2;
        int i = G.locateVex(G,v1);
        int j = G.locateVex(G,v2);
        G.adjMatrix[i][j] = 1;
        G.adjMatrix[j][i] = G.adjMatrix[i][j];    //设置对称弧
    }
    return true;
}

int UDGraph::locateVex(UDGraph &G, char v) {
    for (int i = 0; i < G.vexNum; i++) {
        if (G.vexs[i] == v) return i;
    }
    cerr << "Vex doesn't exist!";
    return -1;    
}

void UDGraph::BFS() {

}

void UDGraph::DFS() {
    
} 