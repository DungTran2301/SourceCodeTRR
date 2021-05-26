/**
    Name: Duyệt các cạnh cầu
    Author: DungTD
    Date: 3/17/2021
 */
#include <iostream>
#define Max 100
using namespace std;

class Dothi{
    int     n;
    int     A[Max][Max];
    public:
    bool    chuaXet[Max];
    void    readData();
    void    init();
    void    recursiveDFS(int u);
    void    duyetCau();
};

void Dothi::readData() {
    cout << "\nNhap so dinh = "; cin >> n;
    cout << "\nNhap ma tran ke:\n";
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) cin >> A[i][j];
    }
}

void Dothi::init() {
    for (int i=1; i<=n; i++) chuaXet[i] = true;
}

void Dothi::recursiveDFS(int u) {
    chuaXet[u] = false;
    for (int v=1; v<=n; v++) {
        if (A[u][v] == 1 && chuaXet[v] == true) recursiveDFS(v);
    }
}

void Dothi::duyetCau() {
    // Khoi tao
    init();
    // Duyet tat ca cac canh
    for (int i=1; i<=n; i++) {
        for (int j= i+1; j<=n; j++) {
            // Neu (i, j) la canh
            if (A[i][j] == 1) {
                A[i][j] = 0; A[j][i] = 0;
                recursiveDFS(1);
                // DFS(1) == V
                for (int k=1; k<=n; k++) {
                    if (chuaXet[k] == true){    //DFS(1) khong duyet het => (i, j) la canh cau
                        cout << i << " " << j << "\n";
                        break;
                    }
                }
                A[i][j] = A[j][i] = 1;  // tra lai canh (i, j);
                init();
            }
        }
    }
}
int main() {
    Dothi G;
    G.readData();
    G.duyetCau();
}