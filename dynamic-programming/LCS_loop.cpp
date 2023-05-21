#include <bits/stdc++.h>
using namespace std;
string A;
string B;

int LCS(int n, int m) {
    int i = n, j = m;
    int trace = m;
    int count = 0;
    for(; i>=0;i--) {
        j = trace;
        for(; j >=0; j--) {
            if(A[i] == B[j]) {
                ++count;
                i--; j--;
                trace = j;
            }
        }
    }
    return count;
}


int main(){
    A = "ace";
    B = "abcde";
    cout << LCS(A.length()-1, B.length()-1);
}
