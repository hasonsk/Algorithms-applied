#include <bits/stdc++.h>
using namespace std;
#define MAX 1000

int M, N, r, c;
int a[MAX][MAX];
int d[MAX][MAX];
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
typedef pair<int, int> ii;

int Maze () {
    queue<ii> qe;
    qe.push(ii(r,c));
    int x, y;
    a[r][c] = 1;    d[r][c] = 0;
    while(!qe.empty()) {
        ii index = qe.front() ;
        qe.pop();
        for(int i = 0; i < 4; i++) {
            x = index.first + dx[i];
            y = index.second + dy[i];
            if(x < 1 || x > M || y < 1 || y > N) return d[index.first][index.second] +1;
            if(!a[x][y]) {
                d[x][y] = 1 + d[index.first][index.second] ;
                qe.push(ii(x, y));
                a[x][y] = 1;
            }
        }
    }
    return -1;
}


int main() {
    cin >> M >> N >> r >> c;
    for(int i = 1; i <= M; i++) 
        for(int j = 1; j <= N; j++) cin >> a[i][j];
    cout << Maze();
    return 0;
}
