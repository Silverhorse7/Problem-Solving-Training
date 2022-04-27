#include<bits/stdc++.h>

using namespace std;

signed main() {
    string s;
    cin >> s;
    stack<char> stk;
    bool flag = 1;
    for (int i = 0; i < s.size(); i++) {
        if (stk.size()) {
            if (stk.top() == s[i])
                stk.pop(), flag ^= 1;
            else
                stk.push(s[i]);
        } else
            stk.push(s[i]);
    }
    if (flag)
        cout << "No" << endl;
    else
        cout << "Yes" << endl;
}