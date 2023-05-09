#include <bits/stdc++.h>
using namespace std;
#define MAX 10

int N;              // SIZE N*N
int row[MAX];       // row 
int visited[MAX];   // check col is exist

void Ghinhan() {   
    int static count = 1;
    cout<<" #"<<count<<": "<<endl;
    for(int i = 1; i<= N; i++) {
        for(int j = 1; j <= N; j++) if(row[i] == j) cout<<"Q "; else cout<< "* ";
        cout<<endl;
    }
    cout<< endl;
    count++;
}

bool check(int i, int k) {
    for(int j = 1; j < k; j++) {
        if(row[j] == i || abs(i-row[j]) == abs(k-j)) {
            return false;
        }
    }
    return true;
}

void Try(int k) {
    for(int i = 1; i <= N; i++) {
        if(check(i, k)) {
            row[k] = i;
            visited[i] = 1;
            if(k == N) Ghinhan();
            else Try(k+1);
            visited[i] = 0;
        }
    }
}

int main() {
    for(int i = 1; i <= N; i++) visited[i] = 0;
    cin >> N;
    Try(1);
}
