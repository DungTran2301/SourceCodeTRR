/**
    Name: Tìm đường đi từ đỉnh s đến đỉnh t theo DFS và BFS
    Author: DungTD
    Date: 3/17/2021
 */
#include <bits/stdc++.h>
#include <vector>
#include <queue>
#define MAX  100

using namespace std;

class Dothi {
    int n;
    int be, en;
    int A[MAX][MAX];
    public:
    
    bool haveWay;
    bool chuaXet[MAX];
    void readData();
    void init();
    void DFS(int u);
    void BFS(int u);
    int truoc[MAX];
    void trace();
    void findWay();
};
void Dothi:: readData() {
    cin >> n;
    cin >> be;
    cin >> en;
    for (int i=1; i<=n; i++) 
        for (int j=1; j<=n; j++) cin >> A[i][j];
}

void Dothi::init() {
    for (int i=1; i<=n; i++) chuaXet[i] = true;
}

void Dothi::DFS(int u) {
    chuaXet[u] = false;
    for (int v=1; v<=n; v++) {
        if (A[u][v] == 1 && chuaXet[v] == true) {
            truoc[v] = u;
            if (v == en) {
                haveWay = true;
                return;
            }
            DFS(v);
            if (haveWay) return;
        }
    }
}
void Dothi::BFS(int u) {
    queue <int> q;
    q.push(u);
    chuaXet[u] = false;
    while(q.size()) {
        u = q.front(); q.pop();
        for (int i=1; i<=n; i++) {
            if (A[u][i] == 1 && chuaXet[i] == true) {
                truoc[i] = u;
                chuaXet[i] = false;
                q.push(i);
            }
        }
    }
}

void Dothi::trace() {
    vector <int> res;
    int t = en;
    while(t != be) {
        res.push_back(t);
        t = truoc[t];
    }
    res.push_back(be);
    for (int i=0; i<res.size(); i++) {
        cout << res[i] << " ";
    }
    cout << endl;
}

void Dothi::findWay() {
    haveWay = false;
    init();
    DFS(be);
    if (!haveWay) cout << "no path";
    else {
        cout << "DFS path: ";
        trace();
        init();
        BFS(be);
        cout << "BFS path: ";
        trace();
    }
}
int main() {
    Dothi G;
    G.readData();
    G.findWay();
}