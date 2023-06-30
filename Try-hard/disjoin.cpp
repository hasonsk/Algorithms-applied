#include <bits/stdc++.h>
using namespace std;
int const MAX = 100005;
int n;
pair<int, int> a[MAX];

void input() {
    cin >> n;
    for(int i= 1; i<=n; i++) 
        cin >> a[i].first >> a[i].second;
}

int cmp(pair<int, int> a, pair<int, int> b) {
    return a.second < b.second;
}

void solve() {
    int res=0;
    sort(a+1, a+n+1, cmp);
    int last = -1;
    for(int i = 1; i<=n; i++) {
        if(a[i].first > last) {
            ++res;
            last = a[i].second;
        }
    }
    cout << res << endl;
}

int main() {
    input();
    solve();
    return 0;
}
