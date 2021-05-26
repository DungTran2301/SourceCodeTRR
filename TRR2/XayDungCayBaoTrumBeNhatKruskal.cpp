/**
    Name: Xây dựng cây bao trùm bé nhất theo Kruskal
    Author: DungTD
    Date: 
 */
#include <iostream>
#define Max 100
using namespace std;

struct edg {
    int h, id, n1, n2;
};

class Dothi{
    int n, a[Max][Max], ne, atree[Max][Max];
    edg edglist[Max], edgtree[Max];
    int dh;
    public:
    bool chuaxet[Max];
    void read();
    void init();
    void dfs(int u);
    void bubblesort();
    void kruskal();
};

void Dothi::read() {
    cin >> n; ne = 0;
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            cin >> a[i][j];
            if (a[i][j] > 0 && i < j) {
                ne++;
                edglist[ne].h = a[i][j];
                edglist[ne].id = ne;
                edglist[ne].n1 = i;
                edglist[ne].n2 = j;
            }
        }
    }
}

void Dothi::init() {
    for (int i=1; i<=n; i++) chuaxet[i] = true;
}

void Dothi::dfs(int u) {
    chuaxet[u] = false;
    for (int i=1; i<=n; i++) {
        if (atree[u][i] == 1 && chuaxet[i] == true) dfs(i);
    }
}
void Dothi::bubblesort() {
    for (int i=1; i<=ne; i++) {
        for (int j=ne; j>=i+1; j--) {
            if (edglist[j].h < edglist[j-1].h) {
                edg tmp = edglist[j];
                edglist[j] = edglist[j-1];
                edglist[j-1] = tmp;
            }
        }
    }   
}

void Dothi::kruskal() {
    int net = 0;
    for (int i=1; i<=n; i++)
        for (int j=1; j<=n; j++) atree[i][j] = 0;
    dh = 0;
    bubblesort();
    for(int i=1; i<=ne; i++) {
        int n1 = edglist[i].n1; int n2 = edglist[i].n2;
        init(); dfs(n1);
        if (chuaxet[n2] == true) {
            dh += edglist[i].h; net++;
            edgtree[net].n1 = n1;
            edgtree[net].n2 = n2;
            atree[n1][n2] = 1; atree[n2][n1] = 1;
        }
    }
    if (net == n-1) {
        cout << " dH = " << dh << endl;
        for (int i=1; i<=net; i++) cout << edgtree[i].n1 << " " << edgtree[i].n2 << endl;
        
    }
}

int main() {
    Dothi g;
    g.read();
    g.kruskal();
}