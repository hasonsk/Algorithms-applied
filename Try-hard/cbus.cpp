#include <bits/stdc++.h>
using namespace std;
#define MAX 30
int A[2*MAX+1][2*MAX+1]; 
int bVisited[2*MAX+1];
int x[2*MAX+1];
int x_best[2*MAX+1];
int n, m;   // n la so tuyen, m so hanh khach toi da
int load=0; //so hanh khach hien tai
int f=0;    // chi phi hien tai
int f_best = 1e9;  
int cmin=1e9;


void solution() {
    if(f + A[x[n<<1]][0] < f_best) {
        f_best = f + A[x[n<<1]][0];
        for(int i = 1; i<=n<<1; i++) x_best[i] = x[i];
    }
}

int check(int i) {
    if(bVisited[i]) return 0;
    if(i>n){
        if(!bVisited[i-n]) return 0;
    } else{
        if(load==m) return 0;
    }
    return 1;
}

void Try(int k) {
    for(int i= 1; i<=2*n; i++) {
        if(check(i)) {
            x[k] = i;
            f+=A[x[k-1]][x[k]];
            bVisited[i] = 1;
            if(i>n) load -= 1; else load += 1;
            if(k==2*n) {
                solution();
            }
            else {
                if(f+(2*n-k)*cmin < f_best) Try(k+1);
            }
            f -= A[x[k-1]][x[k]];
            bVisited[i] = 0;
            if(i>n) load += 1; else load -= 1;
        }
    }
}


void input() {
    cin >> n >> m;
    for(int i=0; i<=2*n; i++)
    for(int j=0; j<=2*n; j++) {
        cin >> A[i][j];
        if(A[i][j] < cmin) cmin = A[i][j];
    }
    for(int i = 0; i<=2*n; i++) bVisited[i] = 0;
    x[0] = 0;
}

void print() {
    cout <<"Res: " << f_best<<endl;
    for(int i= 1; i<=n<<1; i++) cout << x_best[i]<< " ";
    cout <<"\n";
}

int main() {
    input();
    Try(1);
    print();
    return 0;
}

// input:
// 3  2
// 0  8  5  1  10  5  9
// 9  0  5  6  6  2  8
// 2  2  0  3  8  7  2
// 5  3  4  0  3  2  7
// 9  6  8  7  0  9  10
// 3  8  10  6  5  0  2
// 3  4  4  5  2  2  0
