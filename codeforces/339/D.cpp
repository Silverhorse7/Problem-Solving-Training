#include "bits/stdc++.h"

using namespace std;
#define int long long
const long long N = (1 << 18);
int tree[N], a[N];
int depth[N];

void build(int v, int tl, int tr) {
    if (tl == tr) {
        tree[v] = a[tl];
        depth[v] = 0;
    } else {
        int tm = (tl + tr) / 2;
        build(v * 2, tl, tm), build(v * 2 + 1, tm + 1, tr);
        tree[v] = tree[v * 2] | tree[v * 2 + 1];
        if (depth[v * 2] == 0) {
            tree[v] = tree[v * 2] | tree[v * 2 + 1];
            depth[v] = 1;
        } else {
            tree[v] = tree[v * 2] ^ tree[v * 2 + 1];
            depth[v] = 0;
        }
    }
}

void upd(int v, int tl, int tr, int p, int b) {
    if (tl == tr) {
        a[p] = b;
        tree[v] = a[p];
    } else {
        int tm = (tl + tr) / 2;
        if (p <= tm) {
            upd(v * 2, tl, tm, p, b);
        } else {
            upd(v * 2 + 1, tm + 1, tr, p, b);
        }
        tree[v] = depth[v * 2] == 0 ? tree[v * 2] | tree[v * 2 + 1] : tree[v * 2] ^ tree[v * 2 + 1];
    }
}

signed main() {
    int n, m;
    cin >> n >> m;
    n = (1 << n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    build(1, 0, n - 1);
    while (m--) {
        int p, b;
        cin >> p >> b;
        p--;
        upd(1, 0, n - 1, p, b);
        cout << (tree[1]) << endl;
    }
}