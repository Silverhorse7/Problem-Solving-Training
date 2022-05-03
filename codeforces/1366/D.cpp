
#include <bits/stdc++.h>

using namespace std;
const int N = 1e7 + 5;
int pf[N], ans[N][2];

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

signed main() {
    pre();
    int n;
    cin >> n;
    memset(ans, -1, sizeof ans);
    for (int idx = 0; idx < n; idx++) {
        int x;
        cin >> x;
        auto v = get_pf(x);
        if (v.size() == 1)continue;
        ans[idx][0] = v[0].first;
        ans[idx][1] = 1;
        for (int i = 1; i < v.size(); i++)
            ans[idx][1] = ans[idx][1] * v[i].first;
    }
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < n; j++)
            cout << ans[j][i] << ' ';
        cout << endl;
    }
}