#include  <iostream>
using namespace std;

#define MAX 100

int a[MAX];
int n, M;
int T;  //sum of X1, X2,... Xk-1

void solution() {
    for(int i = 1; i <= n; i++) cout<<a[i]<<" ";
    cout<<endl;
}

bool check(int v, int k){
    if(k < n) return 1;
    return T + v == M;
}

void Try(int k) {
    for(int i = 1; i <= M-T-(n-k); i++){
        if(check(i, k)){
            a[k] = i;
            T = T + a[k];  // update incrmentally
            if(k ==  n) solution();
            else Try(k+1);
            T -= a[k];  //recover when backtracking
        }
    }
}

int main() {
    n = 4;
    M = 10;
    T = 0;
    Try(1);
}
