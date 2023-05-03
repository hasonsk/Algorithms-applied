#include <bits/stdc++.h>
using namespace std;
#define MAX 50

int di[8] = {1, 1, 2, 2, -1, -1, -2, -2};
int dj[8] = {2, -2, 1, -1, 2, -2, 1, -1};

bool marked[MAX][MAX];   // Check to see if it's available
int xi[MAX*MAX];         // ith row
int xj[MAX*MAX];         // jth column

int N;                   // matrix size
int I, J;                // starting position

bool check(int i, int j){
    if(i<1||i>N) return false;
    if(j<1||j>N) return false;

    return !marked[i][j];

}

void solution() {
    static int count = 1;
    cout<<"#"<< count<<": ";
    for(int i = 1; i <= N*N; i++) cout<<" ("<<xi[i]<<","<<xj[i]<<") ";
    count++;
    cout<<endl;
}

void Try(int k) {
    for(int v = 0; v < 8; v++){
        if(check(xi[k-1] + di[v], xj[k-1] + dj[v])){
            xi[k] = xi[k-1] + di[v];
            xj[k] = xj[k-1] + dj[v];
            marked[xi[k]][xj[k]] = true;

            if(k == N*N) solution();
            else Try(k+1);
            marked[xi[k]][xj[k]] = false;
        }
    }
}

int main() {
    for(int i = 1; i <= N; i++)
    for(int j = 1; j <= N; j++)
    marked[i][j] = false;

    cin>> N >> I >> J;
    xi[1] = I;
    xj[1] = J;
    marked[I][J] = true;
    Try(2);
}
