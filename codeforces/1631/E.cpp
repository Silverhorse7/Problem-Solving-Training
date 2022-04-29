#include "bits/stdc++.h"

using namespace std;
const int N = 2e5 + 1;
int seg[N], lazy[N];

void push(int v) {
    seg[v * 2] += lazy[v];
    seg[v * 2 + 1] += lazy[v];
    lazy[v * 2] += lazy[v];
    lazy[v * 2 + 1] += lazy[v];
    lazy[v] = 0;
}

void update(int v, int tl, int tr, int l, int r) {
    if (l > r)return;
    if (l == tl and r == tr)
        lazy[v] += 1, lazy[v] += 1;
    else {
        push(v);
        int tm = (tl + tr) / 2;
        update(v * 2, tl, tm, l, min(r, tm));
        update(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r);
    }
}

int query(int v, int tl, int tr, int pos) {
    if (tl == tr)
        return seg[v];
    else {
        push(v);
        int tm = (tl + tr) / 2;
        if (pos <= tm) {
            return (query(v * 2, tl, tm, pos));
        } else {
            return (query(v * 2 + 1, tm + 1, tr, pos));
        }
    }
}

signed main() {
    int n;
    cin >> n;
    map<int, int> mp;
    vector<int> v(n);
    for (auto &i: v)
        cin >> i;
    for (int i = 0; i < n; i++)
        mp[v[i]] = i;
    int maximum_area = 0;
    int covered_area = 0;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        maximum_area = max(maximum_area, mp[v[i]]);
        if (covered_area > i)
            ans++;
        else
            covered_area = maximum_area;
    }
    cout << ans << endl;
}