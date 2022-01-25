#include<bits/stdc++.h>

using namespace std;
vector<vector<long long>> a;
long long n;
int mp[205][205];
long long mx(int i, long long cur_xor, long long cur_size, vector<bool> &vis) {
    if (i >= 2 * n)return -1;
    if (cur_size == n) {
        return cur_xor;
    }
    long long cur = mx(i + 1, cur_xor, cur_size, vis);
    if (!vis[i]) {
        for (int j = 0; j < a[i].size(); j++) {
            if (vis[mp[i][j]])continue;
            vis[mp[i][j]] = 1;
            cur = max(cur, mx(i + 1, a[i][j] ^ cur_xor, cur_size + 1, vis));
            vis[mp[i][j]] = 0;
        }
    }

    return cur;
}

signed main() {
    cin >> n;
    a.resize(2 * n);
    for (long long i = 0; i < (2 * n - 1); i++)
        a[i].resize(2 * n - (i + 1));
    for (auto &i: a)
        for (auto &j: i)
            scanf("%lld", &j);
    for (int i = 0; i < a.size(); i++) {
        for (int j = 0; j < a[i].size(); j++) {
            mp[i][j] = i + j + 1;
        }
    }
    vector<bool> vis(2 * n);
    cout << mx(0, 0, 0, vis);
}