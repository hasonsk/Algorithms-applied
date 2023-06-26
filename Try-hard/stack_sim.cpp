#include <bits/stdc++.h>
using namespace std;

int main() {
    stack<int> st;
    queue<int> qe;
    string s;
    do {
        cin >> s;
        if(s == "PUSH"){
            int a; cin >> a;
            st.push(a);
        }
        else if(s == "POP") {
            if(!st.empty()) {
                cout << st.top() << endl;
                st.pop();
            }
            else {
                cout << "NULL" << endl;
            }
        }
    } while(s != "#");
    return 0;
}
