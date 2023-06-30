#include <bits/stdc++.h>
using namespace std;
int n;
int coin[] = {500, 200, 100, 50, 20, 10, 5, 2, 1};
int res;

void solve(int n){
    res = 0;
    int i = 0; 
    while(n != 0) {
        if(coin[i] > n) { i++;}
        else {
            res+=n/coin[i]; n%=coin[i++]; }
    }
    cout << res;
}

int main() {
    cin >> n;
    solve(n);
}
