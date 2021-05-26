/**
    Name: Duyệt các đỉnh trụ
    Author: DungTD
    Date: 3/17/2021
 */
#include <iostream>
#define Max 100
using namespace std;

class Dothi {
    int n;
    int A[Max][Max];
    public:
    bool chuaXet[Max];
    void readData();
    void init();
    void recursiveDFS(int u);
    void duyetCau();
};

void Dothi::readData() {
    cout << "\nNhap so dinh = "; cin >> n;
    cout << "Nhap ma tran ke:\n";
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) cin >> A[i][j];
    }
}
void Dothi::init() {
    for (int i=1; i<=n; i++) chuaXet[i] = true;
}

void Dothi::recursiveDFS(int u) {
    chuaXet[u] = false;
    for (int v=1; v<=n; v++)
        if (A[u][v] == 1 && chuaXet[v] == true) recursiveDFS(v);
}

void Dothi::duyetCau() {
    init();
    for (int i=1; i<=n; i++) {
        chuaXet[i] = false;
        if (i==1) recursiveDFS(2);
        else recursiveDFS(1);
        for (int j=1;j<=n; j++) {
            if (chuaXet[j] == true) {
                cout << i << " ";
                break;
            }
        }
        init();
    }
}
int main() {
    Dothi G;
    G.readData();
    G.duyetCau();
}