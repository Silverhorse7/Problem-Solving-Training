#include "bits/stdc++.h"

using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> v(m);
    map<int, int> mp;
    vector<int> ans(m);
    for (int i = 0; i < m; i++) {
        int k_i;
        cin >> k_i;
        v[i].resize(k_i);
        for (int j = 0; j < k_i; j++) {
            cin >> v[i][j];
        }
        if (k_i == 1) {
            mp[v[i][0]]++;
        }
    }
    for (int i = 0; i < m; i++) {
        if (v[i].size() > 1) {
            ans[i] = 0;
            for (auto j: v[i])
                if (mp[j] + 1 <= (m + 1) / 2) {
                    ++mp[j], ans[i] = j;
                    break;
                }
            if (!ans[i]) {
                cout << "NO\n";
                return;
            }
        } else
            ans[i] = v[i][0];
    }
    map<int, int> chk;
    for (auto i: ans) {
        chk[i]++;
        if (chk[i] > (m + 1) / 2) {
            cout << "NO\n" << endl;
            return;
        }
    }
    cout << "YES" << endl;
    for (auto i: ans)cout << i << ' ';
    cout << endl;
}

signed main() {
    int T;
    cin >> T;
    while (T--)
        solve();
}