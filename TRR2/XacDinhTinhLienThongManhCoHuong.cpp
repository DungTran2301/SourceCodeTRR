/**
    Name: Xác định tính liên thông mạnh của đồ thị có hướng
    Author: DungTD
    Date: 3/17/2021
 */
#include <bits/stdc++.h>
#define Max 100

using namespace std;

class Dothi {
    int n;
    int A[Max][Max];
    bool check = true;
    public:
    bool chuaXet[Max];
    void read();
    void init();
    void DFS(int u);
    void solve();
};

void Dothi::read() {
    cin >> n;
    for (int i=1; i<=n; i++)
        for (int j=1; j<=n; j++) cin >> A[i][j];
}

void Dothi::init() {
    for (int i=1; i<=n; i++) chuaXet[i] = true;
}

void Dothi::DFS(int u) {
    chuaXet[u] = false;
    for (int v=1; v<=n; v++) {
        if (chuaXet[v] && A[u][v] == 1) {
            DFS(v);
        }
    }
}

void Dothi::solve() {
    for (int i=1; i<=n; i++) {
        init();
        DFS(i);
        for (int j=1; j<=n; j++) {
            if (chuaXet[j] == true) {
                check = false;
            }
        }
    }
    if (check == true) cout << "strongly connected";
    else cout << "not strongly connected";
}

int main() {
    Dothi g;
    g.read();
    g.solve();
}