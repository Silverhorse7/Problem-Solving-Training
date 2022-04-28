#include<bits/stdc++.h>

using namespace std;
const int N = 2e5 + 3;

signed main() {
    int n;
    cin >> n;
    vector<int> a(N);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    vector<vector<int>> g(N);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    vector<long long> ans(N);
    function<void(int, int, map<int, int> &)> dfs = [&](int node, int par, map<int, int> &par_fam) {
        par_fam[a[node]]++;
        ans[a[node]]++;
        for (auto i: g[node]) {
            if (i == par)continue;
            map<int, int> i_fam;
            dfs(i, node, i_fam);
            for (auto it: i_fam) {
                for (auto it2: par_fam) {
                    ans[__gcd(it.first, it2.first)] += it.second * 1ll * it2.second;
                }
            }
            for (auto it: i_fam)
                par_fam[__gcd(a[node], it.first)] += it.second;
        }
    };
    map<int, int> f;
    dfs(1, 1, f);
    for (int i = 1; i < N; i++)
        if (ans[i])
            cout << i << ' ' << ans[i] << endl;
}