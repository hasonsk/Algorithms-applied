#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e6 + 1;
int n;
int A[MAX];
int ta[MAX];
int res = 0;
int const MOD = 1e9 + 7;

int merge(int b, int m, int e) {
    int i = b;
    int j = m+1;
    int res = 0;
    for(int k = b; k<=e; k++) {
        if(i>m) {ta[k] = A[j]; j++;}
        else if(j>e) {ta[k] = A[i]; i++;}
        else{
            if(A[i] > A[j]) {ta[k] = A[j]; res = (res + (m - i + 1)) % MOD;; j++;}
            else {ta[k] = A[i]; i++;}
        }
    }
    for(int i = b; i<=e; i++) A[i] = ta[i];
    return res;
}

int mergeSort(int b, int e) {
    if(b >= e) return 0;
    int m = (b+e)/2;
    int int_count  = 0;
    int_count = (int_count + mergeSort(b, m))%MOD;
    int_count = (int_count + mergeSort(m+1, e))%MOD;
    int_count = (int_count + merge(b, m, e))%MOD;
    return int_count;
}


int main() {
    cin >> n;
    for(int i= 0; i<n; i++) cin >> A[i];
    cout << mergeSort(0, n-1)<<endl;
}
