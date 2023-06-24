# include <bits/stdc++.h>
using namespace std;
#define MAX 100
int n, m; // n: so phan tu; m: trong so tu do
/// m = A1*X1 + A2*X2 + ... + An*Xn
int A[MAX];   
int X[MAX];
int T[MAX]; // Sum of A[1-->i]
int f = 0; // So keo da chia
int res = 0;

// void Ghinhan() {
//     cout <<"#" << dem<< ":\n"; dem++;
//     for(int i = 1; i<=n; i++) cout << X[i] << " ";
//     cout <<endl;
// }

void solution() {
    if(f == m) res++;
}

void Try(int k) {
    for(int i = 1; i <= (m-f-(T[n]-T[k]))/A[k]; i++) {
        X[k] = i;
        f += X[k]*A[k];
        if(k == n) solution();
        else  Try(k+1);
        f -= X[k]*A[k];
    }
}


int main() {
    cin >> n >> m;
    T[0] = 0;
    for(int i = 1; i <= n; i++) {
        cin >> A[i];
        T[i]= T[i-1] + A[i];
    }
    Try(1);
    cout << res;
    return 0;
}

// 3 5
// 1 1 1
