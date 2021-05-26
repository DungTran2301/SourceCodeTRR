/**
    Name: DuyetDFSNganXep
    Author: DungTD
    Date: 3/17/2021
 */
// Chuong trinh duyet do thi su dung DFS ngan xep
#include <iostream>
#include <stack>
#define MAX 100

using namespace std;

class Dothi {
    int     n; // so dinh
    int     A[MAX][MAX]; // ma tran ke
    
    public:
    bool    chuaXet[MAX]; // kiem tra duyet dinh
    void    readData();
    void    init();
    void    loopDFS(int u);
};

void    Dothi::readData() {
    cout << "\nNhap so dinh cua do thi: n = "; cin >> n;
    cout << "\nNhap ma tran ke cua do thi:\n";
    for (int i=1; i<=n; i++)
        for (int j=1; j<=n; j++) cin >> A[i][j];
} // Nhap ma tran ke

void    Dothi::init() {
    for (int i=1; i<=n; i++) chuaXet[i] = true;
} // Khoi tao mang kiem tra viec xet dinh i

void    Dothi::loopDFS(int u) {
    // Khoi tao
    stack <int> nganXep;
    cout << " " << u;
    chuaXet[u] = false;
    nganXep.push(u);
    // Lap
    while (!nganXep.empty()) {
        int s = nganXep.top();
        nganXep.pop();
        for (int t=1; t<=n; t++) {
            if ((A[s][t] == 1) && (chuaXet[t] == true)) {
                cout << " " << t;
                chuaXet[t] = false;
                nganXep.push(s);
                nganXep.push(t);
                break;
            }
        }
    }
    // Tra lai ket qua
}

int main() {
    Dothi   G;
    G.readData();
    G.init();
    cout << "\nKet qua duyet DFS ngan xep: ";
    G.loopDFS(1);
}