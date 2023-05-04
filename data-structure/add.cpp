#include <bits/stdc++.h>
using namespace std;


string add(string a, string b) {
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());


    while(a.length() < b.length()) a += '0';
    while(b.length() < a.length()) b += '0';

    string res = "";
    int temp;
    int carry = 0;
    for(int i = 0; i< a.length(); i++) {
        temp = (a[i] - '0') + (b[i] - '0') + carry;
        res += (temp%10) + '0';
        carry = temp/10;
    }
    if(carry) res += carry + '0';
    reverse(res.begin(), res.end());
    return res;
}

int main() {
    string num1, num2;

    cout << "Nhap so thu nhat: ";
    cin >> num1;
    cout << "Nhap so thu hai: ";
    cin >> num2;

    string result = add(num1, num2);
    cout << "Tong cua hai so: " << result << endl;

    return 0;
}
