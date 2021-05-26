#include <iostream>

using namespace std;
int X[1000], n, count = 1;
int check[100]={};
bool cauhinhcuoi = false;
void print(){
    for (int i = 1; i<=n; i++) cout << X[i] << " ";
    cout << endl;
    return;
}
void sinh(){
    int i=n-1;
    while(i > 0 && X[i] > X[i+1]) i--;
    if (i==0) cauhinhcuoi = true;
    else{
        int k = n;
		while(X[k] < X[i])	k--;	

		int tmp = X[i];
        X[i]=X[k];	
        X[k]=tmp;	

		int l=i+1, r=n;
		while(l<=r){
			int tmp=X[l];	X[l]=X[r];	X[r]=tmp;
			l++;	r--;
		}
    }
    
}
int main(){
    cin >> n;
    // khoi tao
    for (int i=1; i<=n; i++) X[i] = i;
    // lap
    while (!cauhinhcuoi){
        print();
        sinh();
    }
}