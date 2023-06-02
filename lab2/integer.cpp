#include <bits/stdc++.h>
#define MAX 100
using namespace std;
int N, M;
int X[MAX];
int A[MAX];
int sum[MAX];   // sum of A[0] --> A[i]
int f=0;        // f = sum of A[i]*X[i]  0<=i<=k
int res = 0;    // result

void ghinhan() {
    if(f == M) res++;  //update res
    return;
}

void Try(int k) {
    for(int i = 1; i <= (M-f-(sum[N]-sum[k]))/A[k]; i++) {
        X[k] = i;
        f+= X[k]*A[k];
        if(k == N) ghinhan();
        else Try(k+1);
        f-=X[k]*A[k];
    }
}

int main() {
    cin >> N >> M;
    sum[0] = 0;
    for(int i = 1; i <= N; i++) {
        cin >> A[i];
        sum[i] = sum[i-1] + A[i];
    }
    Try(1);
    cout << res<< endl;
    return 0;
}
