#include "bits/stdc++.h"

using namespace std;

signed main() {
    int n, m;
    cin >> n >> m;
    vector<int> f(n), b(m);
    for (auto &i: f)
        cin >> i;
    for (auto &i: b)
        cin >> i;
    vector<int> a(m);
    map<int, vector<int>> mp;
    bool chk = 0;
    for (int i = 0; i < n; i++)
        mp[f[i]].push_back(i);
    for (int i = 0; i < m; i++) {
        if (mp[b[i]].empty()) {
            cout << "Impossible";
            exit(0);
        }
        if (mp[b[i]].size() >= 2) {
            chk = 1;
        }
        a[i] = mp[b[i]].back();
    }
    if (chk) {
        cout << "Ambiguity";
        exit(0);
        
    }
    cout << "Possible" << endl;
    for (auto i: a)
        cout << i + 1 << ' ';

}