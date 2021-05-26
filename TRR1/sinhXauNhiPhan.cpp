#include <iostream>

using namespace std;
int X[100]={0};
int n;
bool cauhinhcuoi = false;
void sinh(){
    int i = n;
    while (i>0 && X[i] == 1) {
        X[i] = 0;
        i--;
    }
    if (i==0) cauhinhcuoi = true;
    else {
        X[i] = 1;
    }
}
void incauhinh(){
    for (int i=1; i<=n; i++) {
        cout << X[i] << " ";
    }
    cout << endl;
}
int main(){
    cin >> n;
    // Khoiw tao
    for (int i=1; i<=n; i++) X[i]=0;
    // lap
    while (!cauhinhcuoi){
        incauhinh();
        sinh();
    }
}