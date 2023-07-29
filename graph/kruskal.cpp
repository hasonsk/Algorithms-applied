#include <bits/stdc++.h>
using namespace std;

int const MAX = 1e5+1;
struct edge{
    int u, v;
    int w;
};
vector<edge> canh;
int n, m;
int parent[MAX], sz[MAX];

void make_set() {
    for(int i= 1; i<=n; i++) {
        parent[i] = i;
        sz[i] = 1;
    }
}

int find(int v) {
    if(v == parent[v]) return v;
    return parent[v] = find(parent[v]);
}

bool Union(int a, int b) {
    a = find(a);
    b = find(b);
    if(a==b) {
        return false;
    }
    else{
        if(sz[a] < sz[b]) swap(a, b);
        parent[b] = a;
        sz[a] += sz[b];
        return true;
    }
}


void input() {  
    cin >> n >> m;
    make_set();
    for(int i=1 ; i<=m; i++){
        int u, v, w;
        cin >> u >> v >> w;
        edge e;
        e.u = u; e.v= v; e.w = w;
        canh.push_back(e);
    }
}
bool cmp(edge a, edge b) {
    return a.w < b.w;
}

void Kruskal() {
    // tao cay
    vector<edge> mst;
    int d = 0;
    // sort theo chieu dai tang dan
    sort(canh.begin(), canh.end(), cmp);
    // lap
    for(int i=0; i<=m; i++) {
        if(mst.size() == n-1) break;
        edge e = canh[i];
        // check xem co thoa man
        if(Union(e.u, e.v)) {
            mst.push_back(e);
            d += e.w;
        }
    }
    if(mst.size() != n-1) cout <<" do thi khong lien thong.\n";
    cout << d<< endl;
}

int main() {
    input();
    Kruskal();
    return 0;
}


// Khoi tao: cay khung rong, trongj so bang 0
// Sap xep: canh theo chieu dai tang dan
// Lap: Chung nao so canh < n-1
//      E != 0
//      tim ra canh nho nhat --> Khong tao chu trinh, them canh e, d+= de
//      DISJOINT & SET
