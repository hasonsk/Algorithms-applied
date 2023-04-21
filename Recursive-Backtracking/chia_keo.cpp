#include <iostream>
using namespace std;
#define MAX 100
// Bai toan chia keo

int a[MAX];
int n, m;
int sum;

void Ghinhan() {
    for(int i = 1; i<= m;i++) cout<<a[i]<< " ";
    cout<<endl;
}

void Try(int k) {
    if(k == m) {
        a[k] = n - sum;
        Ghinhan();
    }
    else 
        for(int v = 1; v <= n - sum - (m-k); v++){
            a[k] = v;
            sum += a[k];
            Try(k+1);
            sum -= a[k];
        }
}


int main() {
    n = 10, m = 5;
    sum = 0;
    Try(1);
}
