#include <bits/stdc++.h>
using namespace std;
#define MAX 20
int n;
int x[MAX];        // luu hanh trinh da qua
int c[MAX][MAX];   // khoang cach giua 2 diem i va j
int bVisited[MAX]; // danh dau da tham
int f= 0;          // loi giai bo phan
int res = 1e9;     // loi giai bai toan
int cmin = 1e9;   

void CapNhap() {
    if(f + c[x[n]][1]< res) {
        res = f + c[x[n]][1];
    }
}

void Try(int k) {
    for(int i = 2; i <= n; i++) {
        if(!bVisited[i]) {
            x[k] = i;
            bVisited[i] = 1;
            f+=c[x[k-1]][x[k]];
            if(k==n) CapNhap();
            else {
                if(f + (n-k)*cmin < res) Try(k+1);
            }
            bVisited[i] = 0;
            f-=c[x[k-1]][x[k]];
        }
    }
}

int main () {
    cin >> n;
    for(int i= 1; i<=n; i++) 
    for(int j = 1; j<=n; j++) {
        cin >> c[i][j];
        if(c[i][j] < cmin) cmin = c[i][j];
    }

    x[1]= 1;
    Try(2);
    cout << res << endl;
    return 0;
}
// 4
// 0 1 1 9
// 1 0 9 3
// 1 9 0 2
// 9 3 2 0
