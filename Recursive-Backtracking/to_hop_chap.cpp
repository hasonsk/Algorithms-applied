#include <iostream>
using namespace std;
#define MAX 100
//liet ke to hop chap m cua n phan tu

int a[MAX];
int n, m;
bool bVisited[MAX] = {0};

void Ghinhan() {
    for(int i = 1; i<= m;i++) cout<<a[i]<< " ";
    cout<<endl;
}

void Try(int k) {
    for(int v = a[k-1]+1; v <= n - m + k; v++){
        a[k] = v;
        if(k == m) Ghinhan();
        else Try(k+1);
    
    }
}


int main() {
    n = 10, m =7;
    Try(1);
}
