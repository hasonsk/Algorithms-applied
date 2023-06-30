#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 2;
int n, f[N][102], T, D, a[N], t[N], res;

void inp() {
    ios_base :: sync_with_stdio(0); 
    cin.tie(NULL);
    cin >> n >> T >> D;
    for(int i = 1 ; i <= n; i ++) cin >> a[i];
    for(int i = 1 ; i <= n; i ++) cin >> t[i];
}

void proc(){
    for(int i = 1 ; i <= n; i ++) {
        for(int k = t[i]; k <= T; k++) {
            for(int j = max(0, i - D); j <= i - 1; j ++) {
                // if(f[j][k-t[i]] + a[i] > f[i][k]) f[i][k] = f[j][k-t[i]] + a[i];
                f[i][k] = max(f[i][k], f[j][k - t[i]] + a[i]);
            }
            res = max(res, f[i][k]);
        }
    }
    cout << res << "\n";
}

void solve(){
    for(int i= 1; i<=n; i++) {
        for(int j=t[i]; j<=T;j++){
            for(int k = max(0, i-D); k<=i-1; k++) {
                f[i][j] = max(f[i][j], f[k][j-t[i]]+a[i]);
            }
            if(f[i][j] > res) res = f[i][j]; 
        }
    }
    cout << res;
}
int main()
{
    inp();
    solve();
}
