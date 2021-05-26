/**
    Name: Tim chu trinh Hamilton
    Author: DungTD
    Date: 5/26/2021
    input=
    5
    1
    0  1  0  1  0  
    1  0  1  0  1  
    0  1  0  1  1  
    1  0  1  0  1  
    0  1  1  1  0  
    output=
    1 2 3 5 4 1
    1 2 5 3 4 1
    1 4 3 5 2 1
    1 4 5 3 2 1
 */
#include <bits/stdc++.h>
#define Max 100
using namespace std;

class Dothi{
    int n;
    int A[Max][Max];
    public:
    int X[Max];
    bool chuaXet[Max];
    void read();
    void init();
    void hmt(int k);
    
};

void Dothi::read() {
    cin >> n;
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) cin >> A[i][j];
    }
}

void Dothi::init() {
    for (int i=1; i<=n; i++) chuaXet[i] = true;
    X[1] = 1;
    chuaXet[X[1]] = false;
}
void Dothi::hmt(int k) {
    for (int y=1; y<=n; y++) {
        if(A[X[k-1]][y] == 1) {
            if (k==n+1 && y==X[1]) {
                cout << endl;
                for (int i=1; i<=n; i++) cout << " " << X[i];
                cout << " "<<X[1];
            }
            else {
                if (chuaXet[y]==true) {
                    X[k] = y;
                    chuaXet[y] = false; hmt(k+1);
                    chuaXet[y] = true;
                }
            }
        }
    }
}
int main() {
    Dothi g;
    g.read();
    g.init();
    g.hmt(2);
}