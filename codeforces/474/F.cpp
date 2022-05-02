#include "bits/stdc++.h"

using namespace std;
#define int long long
const int N = 1e5 + 5;
int n;
long long t[4 * N][2];// 0 = min,  1 = QueryGcd
int a[N];

void build(int v, int tl, int tr) {
    if (tl == tr) {
        t[v][0] = t[v][1] = a[tl];
    } else {
        int tm = (tl + tr) / 2;
        build(v * 2, tl, tm);
        build(v * 2 + 1, tm + 1, tr);
        t[v][0] = min(t[v * 2][0], t[v * 2 + 1][0]);
        t[v][1] = __gcd(t[v * 2][1], t[v * 2 + 1][1]);
    }
}

int QueryMin(int v, int tl, int tr, int l, int r) {
    if (l > r)
        return INT_MAX;
    if (l == tl && r == tr)
        return t[v][0];
    int tm = (tl + tr) / 2;
    return min(QueryMin(v * 2, tl, tm, l, min(r, tm)), QueryMin(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r));
}

int QueryGcd(int v, int tl, int tr, int l, int r) {
    if (l > r)
        return 0;
    if (l == tl && r == tr)
        return t[v][1];
    int tm = (tl + tr) / 2;
    return __gcd(QueryGcd(v * 2, tl, tm, l, min(r, tm)), QueryGcd(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r));
}

unordered_map<int, vector<int> > store;

int occourance(int element, int left, int right) {
    int a = lower_bound(store[element].begin(),
                        store[element].end(),
                        left)
            - store[element].begin();
    int b = upper_bound(store[element].begin(),
                        store[element].end(),
                        right)
            - store[element].begin();

    return b - a;
}

signed main() {
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];

    for (int i = 0; i < n; i++)
        store[a[i]].push_back(i);
    build(1, 0, n - 1);
    int Q;
    cin >> Q;
    while (Q--) {
        int l, r;
        cin >> l >> r;
        l--, r--;
        int x = QueryMin(1, 0, n - 1, l, r);
        int y = QueryGcd(1, 0, n - 1, l, r);
        if (y % x == 0) {
            cout << r - l + 1 - occourance(x, l, r) << endl;
        } else
            cout << r - l + 1 << endl;
    }
}