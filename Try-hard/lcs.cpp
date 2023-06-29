#include <bits/stdc++.h>
using namespace std;
#define MAX 100
int n, m;
int A[MAX];
int B[MAX];
int Res[MAX][MAX];

int LCS(int m, int n) {
    if(n*m==0) return 0;
    if(A[m] == B[n]) return LCS(m-1, n-1)+1;
    else return max(LCS(m-1, n), LCS(m,n-1));
}

int main() {
    int n, m;
    cin >> m >> n;
    for(int i=1; i<=m; i++) cin >> A[i];
    for(int i = 1; i<=n;i++) cin >> B[i];
    cout << LCS(m, n);
}
