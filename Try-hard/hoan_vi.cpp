#include <bits/stdc++.h>
using namespace std;
#define MAX 10000
int n, m;
int A[MAX];
bool bVisited[MAX]; // danh dau la da duyet qua

void Ghinhan() {
    for(int i = 1; i<=m; i++) cout << A[i] << " ";
    cout << endl;
}

void Try(int k) {
    for(int i = 1; i<=n; i++) {
        if(!bVisited[i] && i > A[k-1]) {
            A[k] = i;
            bVisited[i] = true;
            if(k == m) Ghinhan();
            else Try(k+1);
            bVisited[i] = false; 
        }
    }
}


int main() {
    cin >> n >> m;
    A[0] = -1;
    Try(1);
    return 0;
}
