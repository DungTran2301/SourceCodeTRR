#include <iostream>

using namespace std;
int n, X[100], check[100], count = 1;
void print(){
    cout << "\n" << count++ << ": ";
    for (int i=1; i<=n; i++) cout << X[i] << " ";

}

void backTrack(int i){
    for (int j=1; j<=n; j++){
        if (check[j]==0){
            X[i]=j;
            check[j]=1;
            if (i==n) print();
            else backTrack(i+1);
            check[j] = 0;
        }
    }
}
int main(){
    cin >> n;
    backTrack(1);
}