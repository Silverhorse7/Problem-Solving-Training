#include "bits/stdc++.h"

using namespace std;
#define mp   make_pair
#define ll long long
int n, m;
ll w;
const int inf = 1e9;
const vector<pair<int, int>> D = {{-1, 0},
                                  {1,  0},
                                  {0,  -1},
                                  {0,  1}};

vector<vector<int>> get_dist(vector<vector<ll>> &a, pair<int, int> p) {
    vector<vector<int>> d(n, vector<int>(m, inf));
    d[p.first][p.second] = 0;
    queue<pair<int, int>> q;
    q.emplace(p);
    while (!q.empty()) {
        auto[x, y] = q.front();
        q.pop();
        for (auto[dx, dy]: D) {
            int x1 = x + dx, y1 = y + dy;
            if (x1 < 0 || y1 < 0 || x1 >= n || y1 >= m) continue;
            if (a[x1][y1] == -1) continue;
            if (d[x1][y1] <= d[x][y] + 1) continue;
            d[x1][y1] = d[x][y] + 1;
            q.emplace(x1, y1);
        }
    }
    return d;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m >> w;
    vector<vector<ll>> a(n, vector<ll>(m));
    for (auto &b: a)
        for (auto &c: b)cin >> c;
    const int inf = 1e9;
    auto d1 = get_dist(a, {0, 0});
    auto d2 = get_dist(a, {n - 1, m - 1});
    ll ans = 1e18;
    if (d1[n - 1][m - 1] != inf)
        ans = d1[n - 1][m - 1] * w;

    ll min1 = 1e18;
    ll min2 = 1e18;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (a[i][j] > 0 && d1[i][j] != inf) {
                min1 = min(min1, a[i][j] + d1[i][j] * w);
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (a[i][j] > 0 && d2[i][j] != inf) {
                min2 = min(min2, a[i][j] + d2[i][j] * w);
            }
        }
    }

    ans = min(ans, min1 + min2);

    if (ans > 1e16) {
        ans = -1;
    }
    cout << ans << '\n';

    return 0;
}