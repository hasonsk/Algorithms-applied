#include <bits/stdc++.h>
using namespace std;
#define MAX 10
int N;    // the number of Passengers
int Q;    // Maximum number of Passengers
int q;    // Number of Passengers on the current car
int a[MAX]; //Order of pick up and drop off  
int bvisited[MAX] = {0};  // visited places

int Check(int v, int k) {
    if(bvisited[v] == 1) return 0;
    if(v <= N){
        if(q == Q) return 0;
    }
    else 
        if(bvisited[v - N] == 0) return 0;
    return 1;
}

void ghinhan() {
    static int count = 1;
    cout<< "#"<< count<<": ";
    for(int i = 1; i <= 2*N; i++) cout<<a[i]<<" ";
    cout<<"\n";
    ++count;
}

void Try(int k) {
    for(int v = 1; v <=2*N; v++) {
        if(Check(v, k)) {
            a[k] = v;
            bvisited[a[k]] = 1;
            if(a[k] > N)  q--;
            else q++;
            if( k == N*2) ghinhan();
            else Try(k+1);
            
            if(a[k] > N)  q++;
            else q--;
            bvisited[a[k]] = 0;
        }
    }
}

int main() {
    N = 3;
    Q = 2;
    Try(1);
}
