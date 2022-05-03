#include "bits/stdc++.h"

using namespace std;
#define int long long

signed main() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &i: v)
        cin >> i;
    stack<int> stk;
    int mn = INT_MAX;
    int ans = 0;
    for (int i = n - 1; i >= 0; i--) {
        if (!stk.empty() and stk.top() > v[i]) {
            ans += stk.top() - mn;
            mn = v[i];
            while (stk.size())stk.pop();
            stk.push(v[i]);
        } else
            stk.push(v[i]), mn = min(mn,v[i]);
    }
    if (!stk.empty()) {
        ans += stk.top() - mn;
    }
    cout << ans << endl;
}