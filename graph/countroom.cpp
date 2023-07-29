#include <bits/stdc++.h>
using namespace std;


int const MAX = 1001;
int N, M;
char A[MAX][MAX];
int bmark[MAX][MAX];
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

void input() {
    cin >> N >> M;
    for(int i= 1; i<=N; i++) 
        for(int j= 1; j<=M; j++){
            cin >> A[i][j];
            if(A[i][j] == '#') bmark[i][j] = 1;
        }
}
// dem so thanh phan lien thong
void dfs(int x, int y) {
    int ix, iy;
    for(int i= 0; i<4; i++) {
        ix = x + dx[i];
        iy = y + dy[i];
        if(ix < 1 || iy<1 || ix> N|| iy> M|| bmark[ix][iy]) continue;
        else{
            bmark[ix][iy] = true; 
            dfs(ix, iy);
        }
    }
}

void solve1(){
    input();
    int dem = 0;
    for(int i=1 ;i<=N; i++) 
        for(int j= 1; j <=M; j++)
            if(!bmark[i][j]) {
                dfs(i, j);
                ++dem;
            }
    cout << dem << endl;
}


int main() {
    solve1();
}

10 10
// ####.###..
// #.######.#
// ##.######.
// ###.###..#
// ##.####..#
// #####..###
// #.########
// #.####.#.#
// #####..##.
// ######.###
