#include <bits/stdc++.h>
using namespace std;
#define MAX 100
int n, m;
int A[MAX];
int B[MAX];
int Res[MAX][MAX];

int LCS(int m, int n) {
    if(n*m==0) return 0;
    for(int i= 1; i<=m; i++) Res[0][i] = 0;
    for(int i = 1; i<=n; i++) Res[i][0] = 0;
    for(int i = 1; i<=m; i++){
        for(int j = 1; j<=n; j++) {
            if(A[i] == B[j]) Res[i][j] = Res[i-1][j-1] +1;
            else Res[i][j] = max(Res[i-1][j], Res[i][j-1]);
        }
    }
    return Res[m][n];
}

int main() {
    int n, m;
    cin >> m >> n;
    for(int i=1; i<=m; i++) cin >> A[i];
    for(int i = 1; i<=n;i++) cin >> B[i];
    cout << LCS(m, n);
}
