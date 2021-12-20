#include <bits/stdc++.h>
#include <queue>
using namespace std;

#define MAX_VEX_NUM 20
#define INFINITY_NUM 2147483647
#define UNREACH 0
#define VertexType int

class UDGraph {
    private:
        int vexNum;    //顶点数量
        int edgeNum;    //边数量
        VertexType vexs[MAX_VEX_NUM];   //存储顶点的数组
        int adjMatrix[MAX_VEX_NUM][MAX_VEX_NUM];    //存储邻接矩阵的数组
        bool visited[MAX_VEX_NUM];    //访问
    
    public:
        bool createUDG();    //创建无向图
        int locateVex(VertexType v);    //定位顶点v的邻接表位置
        VertexType firstAdjVex(VertexType v);    //寻找顶点v的第一个邻接顶点（有弧相连的顶点）
        VertexType nextAdjVex(VertexType v, VertexType w);    //寻找顶点v的w后的其它邻接顶点
        void BFSTraverse();    //广度优先遍历
        void DFSTraverse();    //深度优先遍历
        void DFS(VertexType v);    
        void visit(VertexType v){cout << v << endl;};

};

bool UDGraph::createUDG() {
    VertexType v1,v2;
    cout << "G.vexNum   G.edgeNum:\n";
    cin >> vexNum >> edgeNum;
    for (int i = 0; i < vexNum; i++) {
        cout << "input vexs[i]:\n";
        cin >> vexs[i];
    }
    //初始化邻接矩阵为0
    for (int i = 0; i < vexNum; i++) {
        for (int j = 0; j < vexNum; j++) {
            adjMatrix[i][j] = UNREACH;
        }
    }
    //构造邻接矩阵
    for (int k = 0; k < edgeNum; k++) {
        cout << "vex vex(the two vexs edge linked)\n";
        cin >> v1 >> v2;
        int i = locateVex(v1);
        int j = locateVex(v2);
        adjMatrix[i][j] = 1;
        adjMatrix[j][i] = adjMatrix[i][j];    //设置对称弧
    }
    return true;
}

int UDGraph::locateVex(VertexType v) {
    for (int i = 0; i < vexNum; i++) {
        if (vexs[i] == v) return i;
    }
    cerr << "Vex doesn't exist!";
    return -1;    
}

VertexType UDGraph::firstAdjVex(VertexType v) {
    int i = locateVex(v);
    if (i != -1) {
        for (int j = 0; j < vexNum; j++) {    //在邻接矩阵中寻找邻接顶点
            if (adjMatrix[i][j] ==  1 && !visited[j]) return vexs[j];
        }        
    }
    return -1;    
}

VertexType UDGraph::nextAdjVex(VertexType v, VertexType w) {
    int i = locateVex(v);
    if (i != -1) {
        for (int j = 0; j < vexNum; j++) {    //在邻接矩阵中寻找邻接顶点
            if (adjMatrix[i][j] == 1 && !visited[j]) return vexs[j];
        }
    }
    return -1;
}

void UDGraph::BFSTraverse() {
    cout << "BFSTraverse:\n";
    for (int i = 0; i <vexNum; i++) visited[i] = false;    //visited归false
    queue<VertexType> Q;
    for (int i = 0; i < vexNum; i++) {
        if (!visited[i]) {
            visited[i] = true;
            visit(vexs[i]);
            Q.push(vexs[i]);    //访问后入队
            while (!Q.empty()) {
                VertexType u = Q.front(); Q.pop();    //非空则出队
                for (VertexType w = firstAdjVex(u); w != -1; w = nextAdjVex(u, w)) {
                    if (!visited[locateVex(w)]) {
                        visited[locateVex(w)] = true;
                        visit(w);
                        Q.push(w);
                    }
                } 
            }
        }
    }
}

void UDGraph::DFSTraverse() {
    cout << "DFSTraverse:\n";
    for (int i = 0; i < vexNum; i++) visited[i] = false;
    for (int i = 0; i < vexNum; i++) {
        if (!visited[i]) DFS(vexs[i]);
    }
    
}

void UDGraph::DFS(VertexType v) {
    int i = locateVex(v);
    visited[i] = true;
    visit(v);
    for (VertexType w = firstAdjVex(v); w != -1; w = nextAdjVex(v, w)) {
        if (!visited[locateVex(w)]) DFS(w);    
    }
} 

int main (void) {
    UDGraph graph;
    graph.createUDG();
    graph.DFSTraverse();    
    graph.BFSTraverse();
    return 0;
}