/**
    Name: Đếm số thành phần liên thông
    Author: DungTD
    Date: 3/17/2021
 */
#include <bits/stdc++.h>
#define Max 100

using namespace std;

class Dothi {
    int n;
    int dem = 0;
    int A[Max][Max];
    public:
    bool chuaXet[Max];
    void readData();
    void init();
    void DFS(int u);
    void solve();
};

void Dothi::readData() {
    cin >> n;
    for (int i=1; i<=n ; i++) 
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
        if (chuaXet[i] == true) {
            dem++;
            DFS(i);
        }
    }
    cout << dem << endl;
}

int main(){
    Dothi g;
    g.readData();
    g.init();
    g.solve();
}