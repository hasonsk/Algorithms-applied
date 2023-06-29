#include <bits/stdc++.h>
using namespace std;
#define MAX 1000
int const MOD = 1e9 +7;
int k, n;
int C[MAX][MAX];

int solve(int k, int n) {
    if(n==0 || k==0) return 1;
    for(int i = 1; i<=n; i++) {
        C[0][i] = 1;
        C[1][i] = i;
    }
    for(int i = 2; i<=k; i++) {
        for(int j= i; j<=n; j++){
            C[i][j] = ((C[i-1][j-1])%MOD + (C[i][j-1])%MOD);
        }
    }
    return C[k][n];
}

int main() {
    cin >> k >> n;
    cout << solve(k, n);
    return 0;
}
