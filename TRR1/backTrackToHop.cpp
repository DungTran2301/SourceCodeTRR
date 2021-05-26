#include <iostream>

using namespace std;
int a[100]={}, n, k;
int count = 1;
void print(){
    cout << "\n" << count++ << ": ";
    for (int i=1; i<=k; i++) cout << a[i] << " ";
}
void Try(int i){
    for (int j=a[i-1] + 1; j<=n-k+i; j++){
        a[i] = j;
        if (i==k) print();
        else
        Try(i+1);
    }

}
int main(){
    cin >> n >> k;
    Try(1);
    return 0;
}