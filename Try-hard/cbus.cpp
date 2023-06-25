#include <bits/stdc++.h>
using namespace std;
#define MAX 30
int n, m;
int load=0;
int C[MAX+1][MAX+1];
int A[2*MAX];     // hanh trinh di 
int bVisited[2*MAX];  // da tham
int f = 0;
int f_best = 999999;
int x_best[2*MAX];
int dem =0;

void Ghinhan() {
    dem ++;
    cout << "#" << dem<< ": ";
    for(int i = 1; i <= 2*n; i++) 
        cout << A[i] <<" ";
    cout << endl;
}

void solution() {
    if(f < f_best) {
        f_best = f;
        for(int i = 1; i<=2*n; i++){
            x_best[i] = A[i];
            cout << x_best[i] <<" ";
        }
        cout << "\n";
        Ghinhan();
    }
}

bool check(int i){
    if(bVisited[i]) return 0;
    if(i<=n){
        if(load==m) return 0;
    }
    else if(!bVisited[i-n] ) return 0;
    return 1;
}

void Try(int k) {
    if(k > n*2){
        f += C[A[k-1]][0] ;
        return solution();;
    }
    for(int i = 1; i <= n*2; i++) {
        if(check(i)) {
            bVisited[i] = true;
            A[k] = i;
            f += C[A[k-1]][i];
            if(i <= n) load++;
            else load--;
            Try(k+1);
            bVisited[i] = false;
            f -= C[A[k-1]][i];
            if(i <= n) load--;   else load++;
        }
    }
}

int main() {
    cin >> n >> m;
    for(int i = 0; i <=n*2; i++)  for(int j = 0; j <=n*2; j++) 
        cin >> C[i][j];
    for(int i = 0; i <= n*2; i++) bVisited[i] = 0;
    A[0] = 0;
    Try(1);
    cout << f_best;
    return 0;
}

// 3  2
// 0  8  5  1  10  5  9
// 9  0  5  6  6  2  8
// 2  2  0  3  8  7  2
// 5  3  4  0  3  2  7
// 9  6  8  7  0  9  10
// 3  8  10  6  5  0  2
// 3  4  4  5  2  2  0
