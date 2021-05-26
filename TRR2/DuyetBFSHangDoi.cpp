/**
    Name: BFS hàng đợi
    Author: DungTD
    Date: 3/17/2021
 */
#include <iostream>
#include <queue>
#define MAX 100

using namespace std;

class Dothi {
    int     n;
    int     A[MAX][MAX];
    public:
    bool    chuaXet[MAX];
    void    readData();
    void    init();
    void    queueBFS(int u);
};

void    Dothi::readData() {
    cout << "\nNhap so dinh cua do thi: n = "; cin >> n;
    cout << "\nNhap ma tranj ke:\n";
    for (int i=1; i<=n; i++)
        for (int j=1; j<=n; j++) cin >> A[i][j];
}

void    Dothi::init() {
    for (int i=1; i<=n; i++) chuaXet[i] = true;
}

void    Dothi::queueBFS(int u) {
    // Khoi tao
    queue<int> hangdoi;
    cout << " " << u;
    chuaXet[u] = false;
    hangdoi.push(u);
    //Lap
    while(!hangdoi.empty()) {
        int s = hangdoi.front();
        hangdoi.pop();
        for (int t=1; t<=n; t++)
            if ((A[s][t] == 1) && (chuaXet[t] == true)) {
                cout << " " << t;
                chuaXet[t] = false;
                hangdoi.push(t);
            }
    }
    // Ket thuc
}

int main() {
    Dothi   G;
    G.readData();
    G.init();
    G.queueBFS(1);
}