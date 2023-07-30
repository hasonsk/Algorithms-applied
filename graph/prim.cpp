#include <bits/stdc++.h>
using namespace std;

using ll = long long;
int const MAX = 1e5+1;
int n, m;
struct canh{
    int x, y, w;
};
vector<pair<int, int>> adj[MAX];
bool  bVisited[MAX];  // 1: thuoc V(MST) 
                      // 0: Thuoc tap V

void input() {
    cin >> n >> m;
    for(int i= 0; i<m ; i++) {
        int x, y, w; cin >> x >> y >> w;
        adj[x].push_back({y, w});
        adj[y].push_back({x, w});
    }
    memset(bVisited, false, sizeof(bVisited));
}

void Prim(int u) {
    // khoi tao cay khung rong, d tong trong so cay khung
    vector<canh> MST;
    int d = 0;
    bVisited[u] = true;
    while(MST.size() < n-1) {
        // chon ra canh e ngan nha x thuoc V, y thuoc V(MST)
        int min_w = INT_MAX;
        int X, Y; // luu 2 dinh cua canh e
        for(int i = 1; i<=n; i++) {
            // neu dinh i thuoc V(MST)
            if(bVisited[i]) {
                // duyet ds ke cua dinh i
                for(pair<int, int> it : adj[i]){
                    int j = it.first, trongso = it.second;
                    if(!bVisited[j] && trongso < min_w) {
                        min_w = trongso;
                        X = j; Y = i;
                    }
                }
            }
        }
        MST.push_back({X, Y, min_w});
        d += min_w;
        bVisited[X] = true; // cho dinh x vao VMST  
    }
    cout << d << endl;
    // for(canh e: MST) {
    //     cout << e.x << " " << e.y << " "<< e.w << endl;
    // }
}


int main() {
    input();
    Prim(1);
}
