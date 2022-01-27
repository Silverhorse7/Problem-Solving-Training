#include<bits/stdc++.h>

using namespace std;

signed main() {
    long long k;
    cin >> k;
    string s = "";
    while (k) {
        s += (k % 2 + '0');
        k /= 2;
    }
    reverse(s.begin(), s.end());
    for (auto &i: s) {
        if (i == '1')i = '2';
        cout << i;
    }
}