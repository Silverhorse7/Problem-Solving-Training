#include "bits/stdc++.h"

using namespace std;

signed main() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &i: v)
        cin >> i;
    stack<int> stk;
    for (int i = 0; i < n; i++)
        !stk.empty() and stk.top() == v[i] % 2 ? stk.pop() : stk.push(v[i] % 2);
    cout<<(stk.size() <= 1 ? "YES" : "NO") << endl;
}