#include<bits/stdc++.h>

using namespace std;
#define all(v) (v).begin(),(v).end()

const int N = 1e6 + 5;
vector<int> tree[3 * N];
vector<int> V, a;
map<long long, int> mp;
long long ans;
int n, i;

void build(int v, int tl, int tr) {
    if (tl == tr) {
        tree[v].push_back(V[tl]);
    } else {
        int tm = (tl + tr) / 2;
        build(v * 2, tl, tm);
        build(v * 2 + 1, tm + 1, tr);
        merge(all(tree[v * 2]), all(tree[v * 2 + 1]), back_inserter(tree[v]));
    }
}

int query(int v, int tl, int tr, const int l, const int r, long long k) {
    if (r < tl || l > tr)
        return 0;
    if (tl >= l && tr <= r) {
        return ((lower_bound(tree[v].begin(), tree[v].end(), k) - tree[v].begin()));
    }
    int mid = (tl + tr) / 2;
    return (query(2 * v, tl, mid, l, r, k) + query(2 * v + 1, mid + 1, tr, l, r, k));
}

int main() {

    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    a.resize(n);
    V.resize(n);
    for (i = 0; i < n; i++)
        cin >> a[i];
    for (i = n - 1; i >= 0; i--) {
        mp[a[i]]++;
        V[i] = mp[a[i]];
    }
    build(1, 0, n - 1);
    mp.clear();
    for (i = 0; i < n; i++)
        mp[a[i]]++, V[i] = mp[a[i]];
    mp.clear();
    for (i = 0; i < n - 1; i++) {
        ans += query(1, 0, n - 1, i + 1, n - 1, V[i]);
    }
    cout << ans << endl;
}