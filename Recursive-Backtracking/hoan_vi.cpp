#include <iostream>
using namespace std;
#define MAX  100

int N;
int a[MAX];
int bTrack[MAX] = {false}; // bTrack[v] = true indicates that v has appeared

void solution () {
    for(int i = 1; i<= N; i++) cout<<a[i]<<" ";
    cout<<endl;
}

bool check(int v, int k){
    if(bTrack[v] == false & a[k-1] != v-1 & k>0)  // There are no 2 consecutive numbers next to
        return 1;
    else return 0;
}

void Try(int k) {
    for(int i = 1; i <= N; i++){
        if(check(i, k)) {
            a[k] = i;
            bTrack[a[k]] = true;
            if(k == N) solution();
            else Try(k+1);
            bTrack[a[k]] = false;
        }
    }
}


int main() {
    N = 5;
    Try(1);
}
