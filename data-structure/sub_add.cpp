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
    int n = a.length();
    for(int i = 0; i < n; i++) {
        temp = (a[i] - '0') + (b[i] - '0') + carry;
        res += (temp%10) + '0';
        carry = temp/10;
    }
    if(carry) res += carry + '0';
    reverse(res.begin(), res.end());
    return res;
}

string subtract(string num1, string num2) {
    // Làm cho cả hai chuỗi có độ dài bằng nhau bằng cách thêm các số 0 vào đầu chuỗi ngắn hơn
    while (num1.length() < num2.length()) {
        num1 = "0" + num1;
    }
    while (num2.length() < num1.length()) {
        num2 = "0" + num2;
    }

    string result = "";
    int borrow = 0;
    for (int i = num1.length() - 1; i >= 0; i--) {
        int digit1 = num1[i] - '0';
        int digit2 = num2[i] - '0';
        int diff = digit1 - digit2 - borrow;
        if (diff < 0) {
            diff += 10;
            borrow = 1;
        } else {
            borrow = 0;
        }
        result = to_string(diff) + result;
    }

    // Xóa các số 0 ở đầu kết quả nếu có
    while (result.length() > 1 && result[0] == '0') {
        result.erase(0, 1);
    }

    return result;
}

int main() {
    long long A[5];
    long long min = INT32_MAX, max = INT32_MIN;
    string sum = "";
    for(int i = 0; i< 5; i++) {
        cin >> A[i];
        if(A[i]<min) min = A[i];
        if(A[i]>max) max = A[i];
        sum = add(sum,to_string(A[i]));
    }
    cout << subtract(sum, to_string(max))<<" "<<subtract(sum, to_string(min)) <<endl;
}
