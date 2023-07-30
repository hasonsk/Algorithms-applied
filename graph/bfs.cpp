#include <bits/stdc++.h>
using namespace std;

int const MAX = 200001;
int n, m;
vector<int> adj[MAX];
int parent[MAX];
vector<int> path;

void input() {
    cin >> n >> m;
    for(int i=1; i<=m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
        parent[i] = 0;
    }
}

void dfs(int u) {
    for(int i: adj[u]) {
        if(!parent[i]){
            parent[i] = u;
            dfs(i);
        }
    }
} 

void bfs(int u) {
    queue<int> q;
    q.push(u);
    parent[u] = u;
    while (!q.empty())  {
        int x = q.front(); q.pop();
        for(int i: adj[x]){
            if(!parent[i]){
                parent[i] = x;
                q.push(i);
            }
        }
    }
    
}

int main() {
    input();
    bfs(1);
    if(parent[n]){
        int t = n;
        int dem = 1;
        while(t!=1) {
            ++ dem;
            path.push_back(t);
            t = parent[t];
        }
        path.push_back(1);
        reverse(path.begin(), path.end());
        cout << dem<< endl;
        for(int i: path) cout << i << " ";
    }
    else cout << "IMPOSSIBLE";
}
