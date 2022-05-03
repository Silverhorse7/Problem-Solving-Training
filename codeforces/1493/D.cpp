
#include <bits/stdc++.h>

using namespace std;
const int N = 2e5 + 5, mod = 1e9 + 7;
unordered_map<int, int> t[N * 4];
int a[N], id[N*4];
int final_ans = 1;

int mul(int A, int b) {
    A %= mod;
    b %= mod;
    return (1LL * A * b) % mod;
}

int pf[N];

void pre() { //call pre at the beginning (in main)
    memset(pf, -1, sizeof(pf));
    for (int i = 2; i < N; i++)
        if (pf[i] == -1) {
            for (int j = i; j < N; j += i) pf[j] = i;
        }
}

vector<pair<int, int>> get_pf(int n) { // first : prime , second : power
    vector<pair<int, int>> r;
    int c = n;
    while (c > 1) {
        int v = pf[c];
        r.emplace_back(v, 0);
        while (c % v == 0) r.back().second++, c /= v;
    }
    return r;
}

int FastPower(int A, int b) {
    if (b == 0) return 1;
    int d = FastPower(A, b / 2);
    d = mul(d, d);
    if (b % 2 == 1) d = mul(d, A);
    return d;
}

void fill_id(int v, int tl, int tr) {
    if (tl == tr)
        id[tl] = v;
    else
        fill_id(v * 2, tl, (tl + tr) >> 1), fill_id(v * 2 + 1, ((tl + tr) >> 1) + 1, tr);
}

void update(int v, int x) {
    auto y = get_pf(x);
    for (auto i: y)
        t[v][i.first] += i.second;
    v /= 2;
    while (v > 0) {
        for (auto i: y) {
            if (t[v * 2].find(i.first) == t[v * 2].end() or t[v * 2 + 1].find(i.first) == t[v * 2 + 1].end())continue;
            int z = t[v][i.first];
            t[v][i.first] = min(t[v * 2][i.first], t[v * 2 + 1][i.first]);
            int diff = t[v][i.first] - z;
            if (v == 1) {
                final_ans = mul(final_ans, FastPower(i.first, t[v][i.first] - z));
            }
        }
        v /= 2;
    }
}

int32_t main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    pre();
    int n, Q;
    cin >> n >> Q;
    for (int i = 0; i < n; i++)cin >> a[i];
    fill_id(1, 0, n - 1);
    for (int i = 0; i < n; i++)update(id[i], a[i]);
    int f = 1;
    while (Q--) {
        int l, r;
        cin >> l >> r;
        l--;
        if (n == 1) {
            final_ans = mul(final_ans, r);
            cout << final_ans << endl;
            continue;
        }
        update(id[l], r);
        cout << final_ans << endl;
    }
}
