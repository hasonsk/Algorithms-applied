#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> parent;
vector<int> sz;

int find(int x) {
    if (x != parent[x]) {
        parent[x] = find(parent[x]);
    }
    return parent[x];
}

void unite(int x, int y) {
    int rootX = find(x);
    int rootY = find(y);
    if (rootX != rootY) {
        if (sz[rootX] < sz[rootY]) {
            parent[rootX] = rootY;
            sz[rootY] += sz[rootX];
        } else {
            parent[rootY] = rootX;
            sz[rootX] += sz[rootY];
        }
    }
}

int main() {
    int n, b;
    cin >> n >> b;

    parent.resize(n + 1);
    sz.resize(n + 1, 1);
    for (int i = 1; i <= n; ++i) {
        parent[i] = i;
    }

    for (int i = 0; i < b; ++i) {
        int city1, city2;
        cin >> city1 >> city2;
        unite(city1, city2);
    }

    int numNeeded = 0;

    vector<pair<int, int>> newRoads;

    for (int i = 2; i <= n; ++i) {
        if (find(1) != find(i)) {
            unite(1, i);
            newRoads.push_back({1, i});
            ++numNeeded;
        }
    }

    cout << numNeeded << endl;
    for (const auto& road : newRoads) {
        cout << road.first << " " << road.second << endl;
    }

    return 0;
}


// 10 10
// 3 9
// 6 8
// 9 10
// 7 8
// 8 10
// 7 10
// 1 9
// 8 9
// 6 9
// 2 7
