#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int MAX = 1e5+1;
int n, m;
int s, t;
vector<pair<int, int>> adj[MAX];
const int oo = 1e9;


void input() {  // do thi co huong
    cin >> n >> m;
    for(int i = 0; i< m; i++) {
        int x, y, w; cin >> x >> y >>w;
        adj[x].push_back({y, w});
    }
    cin >> s >> t;
}


void dijkstra(int s, int t) {
    vector<ll> d(n+1, oo);
    d[s] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> Q;
    // {Khoang cach, dinh}
    Q.push({0, s});
    while(!Q.empty()) {
        // chon ra dinh co khoang cach tu s nho nhat
        pair<int, int> top = Q.top(); Q.pop();
        int u = top.second;
        int kc = top.first;
        if(kc > d[u]) continue;
        // Relaxation : cap nhap khoang cach tu s dem moi dinh ke voi u
        for(auto it: adj[u]) {
            int v = it.first;
            int w = it.second;
            if(d[v] > d[u] + w) {
                d[v] = d[u]+w;
                Q.push({d[v], v});
            }
        }
        // for(int i= 1; i<=n; i++) {
        //     cout << d[i] << " ";
        // }
    }
    cout << "\n"<< d[t];
}


int main() {
    input();
    dijkstra(s, t);
}
