#include <bits/stdc++.h>
using namespace std;
#define MAX 100

int N;
int A[MAX];      
int iMem[MAX];    // the largest subsequence for the range A[1] to A[i]

void MaxSum() {    // Find the sum of the largest subsequence for the range A[1] to A[i]
    iMem[1] = A[1];
    for(int i = 2; i <= N; i++) iMem[i] = max(iMem[i-1] + A[i], A[i]);
}

int Trace(int i) {
    if(i != 1 && (iMem[i] == iMem[i-1] + A[i])) Trace(i-1);
    cout << A[i] << " ";
}


int main() {
    cin >> N;
    for(int i = 1; i <= N; i++) cin >> A[i];
    MaxSum();
    int max = INT16_MIN;
    int index = 0;
    for(int i = 1; i <= N; i++) 
        if(iMem[i] > max) {
            max = iMem[i];
            index = i;
        }
    cout << max <<"\n";
    Trace(index);
}
