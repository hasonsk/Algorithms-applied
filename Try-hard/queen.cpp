# include <bits/stdc++.h>
using namespace std;
#define MAX 100
int  n;
int  iRes[MAX];
bool bCol[MAX];
int  dem = 0;

void Ghinhan() {
    dem ++;
    cout << "#" << dem << ":\n";
    for(int i = 1; i<=n; i++){
        for(int j = 1; j <= n; j++){
            if(iRes[i] == j) cout << "1 ";
            else cout <<"0 ";
        }
        cout <<"\n";
    }
}

int check(int v, int k) {
    if(bCol[v]) return 0;
    for(int i = 1; i < k; i++) {
            if(abs(v-iRes[i]) == k-i) return 0;
    }
    return 1;
}

void Try(int k) {
    for(int i = 1; i <= n; i++) {
        if(check(i, k)){
            iRes[k] = i;
            bCol[i] = true;
            if(k == n)  Ghinhan();
            else Try(k+1);
            bCol[i] = false;
            iRes[k] = 0;
        }
    }
}

int main() {
    cin >> n;
    Try(1);
    return 0;
}