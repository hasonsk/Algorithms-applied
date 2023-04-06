//Liet ke xau nhi phan co chieu dai N
#include <iostream>
using namespace std;
#define MAX 10
int N;
int x[MAX];// bieu dien loi phuong an cua bai toan

bool check(int v, int k){
    return true;
}
void solution(){
    for(int i = 1; i <= N; i++) cout << x[i] << " "; cout << endl;
}
void TRY(int k){
    for(int v = 0; v <= 1; v++){
        if(check(v,k)){
            x[k] = v;
            if(k == N) solution();
            else TRY(k+1);
        }
    }
}
int main(){
    N = 3;
    TRY(1);// bat dau thu gia tri cho x[1]
}
