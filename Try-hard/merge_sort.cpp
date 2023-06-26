#include <bits/stdc++.h>
using namespace std;
#define MAX 100
int n;
int A[MAX];
int ta[MAX];

void merge(int l, int m, int r) {
    int i = l;
    int j = m+1;
    for(int k=l; k<=r; k++) {
        if(i > m) { ta[k] = A[j]; j++;}
        else if(j > r) { ta[k] = A[i]; i++;}
        else {
            if(A[i] > A[j]) {
                ta[k] = A[j]; j++;
            }
            else {
                ta[k] = A[i]; i++;
            }
        }
    }
    for(int i = l; i<=r; i++) A[i]= ta[i];
}

void MergeSort(int l, int r) {
    if(l == r) return;
    int m = (l+r)/2;
    MergeSort(l,m);
    MergeSort(m+1,r);
    merge(l, m, r);
}
int main () {
    cin >>  n; 
    for(int i=0; i<n; i++) cin >> A[i];
    MergeSort(0, n-1);
    for(int i = 0; i<n; i++) cout << A[i] <<" ";
    return 0;
}
