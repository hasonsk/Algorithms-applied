#include <bits/stdc++.h>
using namespace std;
#define MAX 1001
int n, m;
int c[MAX];      // trinh tu sap xep 
int x[MAX]; 
int d[MAX][MAX]; // khoang cach 2 diem i va j 
int f = 0;

int main() {
    cin >> n;
    for(int i = 1; i <=n; i++){
        cin >> x[i];
        c[x[i]] = i;
    }
    for(int i= 1; i<=n; i++)
        for(int j= 1; j<=n; j++) 
            cin >> d[i][j];
    cin >> m;
    int flag = 0;
    for(int i= 1; i<=m; i++) {
        int a, b; 
        cin >> a >> b;
        if(c[a] > c[b])  flag = 1;
    }
    if(flag == 1) cout << "-1";
    else {
        for(int i= 1; i<=n; i++) f+=d[x[i-1]][x[i]];
        cout << f+d[x[n]][1];
    }
} 
