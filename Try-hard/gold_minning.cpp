#include <bits/stdc++.h>
using namespace std;
#define MAX 100
int n, L1, L2;
int A[MAX];
int res[MAX];

int solve() {
    int i = 1;
    while(i <= L1) {res[i] = A[i]; i++;}
    for(int i = L1+1; i<=n; i++){
        int int_max = -1e9;
        for(int j = i-L2; j<=i-L1; j++){ if(res[j]>int_max)  int_max = res[j];}
        res[i] = int_max+A[i]; 
    }
    int int_max = -1e9;
    for(int i = 1; i <= n; i++) if(res[i]>int_max) int_max = res[i];
    return int_max;
}

int main() {
    cin >> n >> L1 >> L2;
    for(int i=1; i<=n; i++) cin >> A[i];
    cout << solve();
}

// 6 2 3
// 3 5 9 6 7 4
