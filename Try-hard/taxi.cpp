#include <bits/stdc++.h>
using namespace std;
#define MAX 30

int n;
int c[2*MAX+1][2*MAX+1];
int x[2*MAX+1];
int bVisited[MAX];
int load = 0;
int f = 0;
int res = 1e9;

int check(int i) {
    if(bVisited[i]) return 0;
    if(i > n){
        if(!bVisited[i-n]) return 0;
    }
    else if(load == 1) return 0;
    return 1;
}

void solution() {
    if(f + c[2*n][0] < res) {
        res = f+c[2*n][0];
    }
}

void Try(int k) {
    for(int i= 1; i<=2*n; i++) {
        if(check(i)){
            bVisited[i] = 1;
            x[k] = i;
            f += c[x[k-1]][x[k]];
            if(i <= n) load+=1; else load -=1;
            if(k == 2*n) solution();
            else Try(k+1);
            if(i <= n) load-=1; else load +=1;
            bVisited[i] = 0;
            f -= c[x[k-1]][x[k]];
        }
    }
}


int main() {
    cin >> n;
    for(int i = 0 ; i<=2*n; i++)  for(int j = 0; j <=2*n; j++) 
        cin >> c[i][j];
    x[0] = 0;
    Try(1);
    cout << res;
    return 0;
} 

// 2
// 0 8 5 1 10
// 5 0 9 3 5
// 6 6 0 8 2
// 2 6 3 0 7
// 2 5 3 4 0
