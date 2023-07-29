#include <bits/stdc++.h>
using namespace std;

int const MAX = 100;
int N, M;
vector<int> Adj[MAX];
vector<int> bVisited(MAX, false);
vector<int> mark[MAX];
int tplt; // thanh phan lien thong

void input(){
    cin >> N >> M;
    for(int i = 1; i <= M; i++) {
        int a, b;
        cin >> a >> b;
        Adj[a].push_back(b);
        Adj[b].push_back(a);
    }
}

void dfs(int u) {
    if(bVisited[u]){
        return ;
    }
    bVisited[u] = true;
    mark[tplt].push_back(u);
    for(int i = 0; i < Adj[u].size(); i++) {
        int v = Adj[u][i];
        dfs(v);
    }
}


int main() {
    input();
    tplt = 0;
    for(int i = 1; i<=N; i++) {
        if(!bVisited[i]){
            tplt++;
            dfs(i);
        }
    }
    // tim so thanh phan lien thong
    for(int i = 1; i<=tplt; i++) {
        cout << "tplt #" << i << " : ";
        for (int j = 0; j<mark[i].size(); j++)
            cout << mark[i][j] << " ";
        cout << endl;
    }
}
