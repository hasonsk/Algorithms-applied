#include <bits/stdc++.h>
#include <string>
using namespace std;
int  A[10001];
int  B[10001];
int  RES[10001][10001];

void LCS(int n, int m) {
    if(n == 0 || m == 0) return;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if(A[i] == B[j]) RES[i][j] = RES[i-1][j-1]+1;
            else RES[i][j] = max(RES[i-1][j], RES[i][j-1]);
        }
    }
}


int main(){
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++) cin >> A[i];
    for(int i = 1; i <= m; i++) cin >> B[i];
    LCS(n, m);
    cout << RES[n][m];
}
