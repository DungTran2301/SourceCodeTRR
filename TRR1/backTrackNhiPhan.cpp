#include <iostream>

using namespace std;
int a[100], n;
int count=1;
void incauhinh(){
    cout << endl << count++ << ": ";
    for (int i=1; i<=n; i++) cout << a[i] << " ";
    cout << endl;
    return;
}
void backTrack(int i){
    for (int j=0; j<2; j++){
        a[i]=j;
        if (i==n) incauhinh();
        else backTrack(i+1);
    }
    return;
}
int main(){
    cin >> n;
    backTrack(1);
    return 0;
}