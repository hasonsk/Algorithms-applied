// dieu kien khong co m so 0 dung canh nhau
#include <bits/stdc++.h>
using namespace std;
#define MAX 1000
int n, m;
int A[MAX]; 

void Ghinhan() {
    for(int i = 1; i<=n; i++) cout << A[i] << " ";
    cout << endl;
}

bool Check(int i, int k) {
    if(i == 1 || k < m) return 1;
    for(int j = k-1; j > k-m; j--) {
        if(A[j] == 1) return 1;
    } 
    return 0;
}

void Try(int k) {
    for(int i = 0; i <= 1; i++) {
        if(Check(i, k)){
            A[k] = i;
            if(k == n) Ghinhan();
            else Try(k+1);
        }
    }
}


int main () {
    cin >> n >> m;
    Try(1);
}
