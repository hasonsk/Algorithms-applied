#include <bits/stdc++.h>
using namespace std;
#define MAX 100
int n;
int A[MAX];

int BinSearch(int b, int e, int key) {
    if(b>e)   return -1;
    int mid = (b+e)/2;
    if(key == A[mid]) return mid;
    else if(key > A[mid]) return BinSearch(mid+1, e, key);
    else return BinSearch(b, mid, key);
}

int main() {
    cin >> n;
    for(int i= 0; i<n; i++) cin >> A[i];
    sort(A, A+n);
    cout << BinSearch(0, n-1, 5);
}
