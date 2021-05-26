/**
    Name: Xây dựng cây bao trùm bé nhất theo Prim
    Author: DungTD
    Date: 
 */
#include <iostream>
#define Max 100
using namespace std;

struct edg {
    int u, v, w;
};

class Dothi {
    int n, be, dH, ne;
    int a[Max][Max];
    bool Vtree[Max], V[Max];
    edg edglist[Max], edgTree[Max];
    public: 
    void readData();
    void init();
    void Sort();
    void Prim();
};

void Dothi::readData() {
    cin >> n >> be;
    ne = 0;
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            cin >> a[i][j];
            if (a[i][j] > 0 && i < j) {
                ne++;
                edglist[ne].u = i;
                edglist[ne].v = j;
                edglist[ne].w = a[i][j];
            }
        }
     }
}

void Dothi::init() {
    for (int i=0; i<=n; i++) {
        V[i] = 1;
        Vtree[i] = 0;
    }
}

void Dothi::Sort() {
    for (int i=1; i<=n; i++) {
        for (int j=ne; j>=i+1; j--) {
            if (edglist[j-1].w > edglist[j].w) {
                swap(edglist[j-1], edglist[j]);
            }
        }
    }
}

void Dothi::Prim() {
    init();
    Vtree[be] = 1;
    V[be] = 0;
    dH = 0;
    int net = 0;
    Sort();
    while (net < n-1) {
        int u, v, w;
        for (int i=1; i<=ne; i++) {
            u = edglist[i].u;
            v = edglist[i].v;
            w = edglist[i].w;
            if (V[u] == 1 && Vtree[v] == 1) {
                net++;
                edgTree[net].u = u;
                edgTree[net].v = v;
                dH += w;
                Vtree[u] = 1;
                V[u] = 0;
                break;
            }
            else if (V[v] == 1 && Vtree[u] == 1) {
                net++;
                edgTree[net].u = u;
                edgTree[net].v = v;
                dH += w;
                Vtree[v] = 1;
                V[v] = 0;
                break;
            }
        }
    }
    if (net == n-1) {
        cout << "dH = " << dH << endl;
        for (int i=1; i<=net; i++) {
            cout << edgTree[i].u << " " << edgTree[i].v << endl;
        }
    }
}

int main() {
    Dothi g;
    g.readData();
    g.Prim();
    return 0;
}