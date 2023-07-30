#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int INF = 1e9;

vector<int> dijkstra(int start, int n, vector<vector<pair<int, int>>>& adj) {
    vector<int> dist(n + 1, INF);
    dist[start] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, start});

    while (!pq.empty()) {
        int u = pq.top().second;
        int d = pq.top().first;
        pq.pop();

        if (d > dist[u]) {
            continue;
        }

        for (const auto& edge : adj[u]) {
            int v = edge.first;
            int w = edge.second;

            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }

    return dist;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<pair<int, int>>> adj(n + 1);

    for (int i = 0; i < m; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].emplace_back(b, c);
    }

    vector<int> shortestRoutes = dijkstra(1, n, adj);

    for (int i = 1; i <= n; ++i) {
        cout << shortestRoutes[i] << " ";
    }

    return 0;
}
