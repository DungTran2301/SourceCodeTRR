 /**
    Name: Tim chu trinh hoac duong di Euler xuat phat tu mot dinh cho truoc tren do thi
    Author: DungTD
    Date: 5/26/2021
    input=
    6
    1
    0  0  0  1  1  0  
    0  0  1  1  1  1  
    0  1  0  1  1  1  
    1  1  1  0  1  0  
    1  1  1  1  0  0  
    0  1  1  0  0  0  
    output=     1  4  2  3  4  5  2  6  3  5  1
 */
#include <iostream>
#include <stack>
#include <vector>
using namespace std;
#define Max 100

class Dothi {
    int n;
    int A[Max][Max];
    public:
    int u;
    void read();
    void init();
    void euler(int u);
};

void Dothi::read() {
    cin >> n >> u;
    for (int i=1; i<=n; i++)
        for (int j=1; j<=n; j++)
            cin >> A[i][j];
}

void Dothi::init(){
    
}

void Dothi::euler(int u) {
    stack<int> st;
    vector<int> CE;
    st.push(u);
    while (st.size()) {
        u = st.top();
        int  v = 0;
        for (int i=1; i<=n; i++) {
            if (A[u][i] == 1 && A[i][u] == 1) {
                v = i;
                break;
            }
        }
        if (v) {
            st.push(v);
            A[u][v] = 0;
            A[v][u] = 0;
        }
        else {
            CE.push_back(u);
            st.pop();
        }
    }
    for (int i=CE.size()-1; i>=0; i--) cout << CE[i] << " ";
    cout << endl;
}

int main() {
    Dothi g;
    g.read();
    g.euler(g.u);
    return 0;
}