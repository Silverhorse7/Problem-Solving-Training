#include "bits/stdc++.h"

using namespace std;
#define int long long

bool cmp(pair<int, int> p1, pair<int, int> p2) {
    if (p1.first == p2.first) {
        return p1.second > p2.second;
    }
    return p1.first < p2.first;
}

signed main() {
    int n, d;
    cin >> n >> d;
    vector<pair<int, int>> a(n);
    for (auto &i: a)cin >> i.first >> i.second;
    sort(a.begin(), a.end());
    vector<int> m(n), s(n), p(n);
    for (int i = 0; i < n; i++) m[i] = a[i].first, s[i] = a[i].second;
    partial_sum(s.begin(), s.end(), p.begin());
    auto get = [&](int l, int r) -> int {
        if (l == 0) return p[r];
        return p[r] - p[l - 1];
    };
    int x = 0;
    for (int i = 0; i < n; i++) {
        int j = (upper_bound(m.begin(), m.end(), m[i] + d - 1) - m.begin()) - 1;
        x = max(x, get(i, j));
    }
    cout << x;
    return 0;
}