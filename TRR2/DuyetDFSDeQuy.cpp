/**
    Name: DeQuyDFS
    Author: DungTD
    Date: 3/17/2021
 */
#include <iostream>
#define MAX 100

using namespace std;

class Dothi {
    int         n; // So dinh
    int         A[MAX][MAX]; // ma tran ke
    public:
    bool        chuaXet[MAX];
    void        readdata();
    void        init();
    void        recursiveDFS(int u);
};

void    Dothi::readdata() {
    cout << "\nNhap so dinh cua do thi n = "; cin >> n;
    cout << "\nNhap ma tran ke:\n";
    for (int i=1; i<=n; i++)
        for (int j=1; j<=n; j++) cin >> A[i][j];
}

void Dothi::init() {
    for (int i=1; i<=n; i++) chuaXet[i] = true;
}

void Dothi::recursiveDFS(int u) {
    cout << " " << u;
    chuaXet[u] = false;
    for (int v=1; v<=n; v++)
        if ((A[u][v]==1) && (chuaXet[v]==true))     recursiveDFS(v);
}

int main() {
    Dothi       G;
    G.readdata();
    G.init();
    cout << "\nKet qua duyet DFS de quy: ";
    G.recursiveDFS(1);
}