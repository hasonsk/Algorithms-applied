#include <bits/stdc++.h>
using namespace std;

int const MAX = 1e5+1;
int n, m;
vector<int> adj[MAX];
int color[MAX];


void input(){
    cin >> n >> m;
    for(int i = 1; i <= m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    memset(color, -1, sizeof(color));
}

bool bfs(int u) {
    queue<int> q;
    q.push(u);
    color[u] = 0; //0 : RED
    while(!q.empty()) {
        int x = q.front(); q.pop();
        for(int i: adj[x]) {
            if(color[i] == -1) {
                color[i] = 1 - color[x];
                q.push(i);
            }
            else if(color[i] == color[x]) return false;
        }
    }
    return true;
}


bool dfs(int u, int par) {
    color[u] = 1-color[par];
    for(int i: adj[u]) {
        if(color[i] == -1) {
            if(!dfs(i, u)) return false;
        }
        else if(color[i] == color[u]) return false;
    }
    return true;
}

int main() {
    input();
    color[0] = 0;
    cout << dfs(1,0);
}
