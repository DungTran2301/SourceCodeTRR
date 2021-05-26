/**
    Name: Shortest path using Dijkstra algorithm
    Author: DungTD
    Date: 5/26/2021
 */
#include <bits/stdc++.h>
#define Max 100
#define INF 100000000
using namespace std;

class Dothi {
    int n, s;
    int a[Max][Max];
    bool chuaXet[Max];
    int trace[Max];
    int dist[Max];
    public:
    void readData();
    void init();
    void Dijkstra();
    int minDis();
    void print();
};

void Dothi::readData() {
    cin >> n >> s;
    for (int i=1; i<=n; i++) 
        for (int j=1; j<=n; j++) cin >> a[i][j];
}

void Dothi::init() {
    for (int i=1; i<=n; i++) {
        chuaXet[i] = true;
        dist[i] = INF;
    }
}

int Dothi::minDis() {
    int Min = INF, min_i;
    for (int i=1; i<=n; i++) {
        if (chuaXet[i] == true && dist[i] <= Min) {
            Min = dist[i];
            min_i = i;
        }
    }
    return min_i;
}

void Dothi::print() {
    for (int i=1; i<=n; i++) {
        if (dist[i] != INF) {
            
            cout << "K/c " << s << " -> " << i << " = " << dist[i] << ";        ";
            int tmp = i;
            cout << tmp;
            do {
                cout << " <- " << trace[tmp];
                tmp = trace[tmp];
            } while (trace[tmp] != tmp);
            cout << endl;
        }
        else {
            cout << "K/c " << s << " -> " << i << " = INF;" << endl;
        }
    }
}
void Dothi::Dijkstra() {
    dist[s] = 0;
    trace[s] = s;
    for (int i=1; i<n; i++) {
        int u = minDis();
        chuaXet[u] = false;
        for (int v=1; v<=n; v++) {
            if (chuaXet[v] && a[u][v] && dist[u] != INF && dist[u] + a[u][v] < dist[v]) {
                dist[v] = dist[u] + a[u][v];
                trace[v] = u;
            }
        }
    }
}
int main() {
    Dothi g;
    g.readData(); g.init();
    g.Dijkstra();
    g.print();
    return 0;
}