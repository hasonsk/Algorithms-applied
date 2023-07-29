#include <bits/stdc++.h>
using namespace std;

int const MAX = 100;
int N, M;
vector<int> Adj[MAX];
vector<int> bVisited(MAX, false);

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
    // cout << u << " ";
    for(int i = 0; i < Adj[u].size(); i++) {
        int v = Adj[u][i];
        dfs(v);
    }
}

int main() {
    input();
    for(int i = 1; i<=N; i++) {
        if(!bVisited[i]) dfs(i);
    }
}
