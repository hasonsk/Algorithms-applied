# include <bits/stdc++.h>
using namespace std;
#define MAX 100
int n, m;
int A[MAX];
int f = 0; // So keo da chia

void Ghinhan() {
    for(int i = 1; i<=m; i++) cout << A[i] << " ";
    cout <<endl;
}

void Try(int k) {
    if(k == m) {
        A[k] = n - f;
        return Ghinhan();
    }
    for(int i = 1; i <= n - f - (m-k); i++) {
        A[k] = i;
        f += A[k];
        Try(k+1);
        f -= A[k];
    }
}


int main() {
    cin >> n >> m;
    Try(1);
    return 0;
}