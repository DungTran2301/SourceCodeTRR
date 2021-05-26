#include <iostream>
using namespace std;

int n, k, a[100];
int count = 1;
bool cauhinhcuoi = false;
void sinh(){
    int i=k;
    while (i>0 && a[i] == n-k+i) i--;
    if (i==0)
        cauhinhcuoi = true;
    else
    {
        a[i]++;
        for (int j=i+1; j<=k; j++){
            a[j] = a[j-1] + 1;
        }
    }
}
void printf(){
    for (int i=1; i<=k; i++) cout << a[i] << " ";
    cout << endl;
    return;
}
int main(){
    cin >> n >> k;
    // Khoi tao
    for (int i=1; i<=k; i++) a[i] = i;
    // Lap
    while (!cauhinhcuoi){
        printf();
        sinh();
    }
}


/*
    * thuật toán sinh được dùng để giải quyết các bài toán thỏa mãn 2 điều kiện:
    - Chúng ta có thể xác định được 1 thứ tự các cấu hình của bài toán
        + biết được cấu hình đầu tiên, cấu hình cuối cùng
    - Từ một cấu hình chúng ta có thể sinh ra một cấu hình tiếp theo

    Bước 1: <khởi tạo> Thiết lập cấu hình đầu tiên
    Bước 2: <Bước lặp>
        while (<chưa phải là cấu hinh cuối>) {
            <in cấu hình hiện tại>
            <sinh cấu hình tiếp theo>
        }
n=5, k=3
1 2 3        
2 3 4
2 3 5 */

3 1 4 5 8 6 2 9 10 7
3 1 4 5 8 6 2 10 7 9
3 1 4 5 8 6 2 10 9 7
3 1 4 5 8 6 7 2 9 10
3 1 4 5 8 6 7 2 10 9
3 1 4 5 8 6 7 9 2 10


