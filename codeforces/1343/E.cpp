#include "bits/stdc++.h"

using namespace std;
const long long N = 2e5 + 5;
long long n, m, a, b, c;
vector<long long> adj[N];
long long P[N];
long long dist[N][3];

void bfs(long long s, long long idx) {
    for (long long i = 1; i <= n; i++) {
        dist[i][idx] = 1e9;
    }
    queue<long long> q;
    dist[s][idx] = 0;
    q.push(s);
    while (!q.empty()) {
        long long node = q.front();
        q.pop();
        for (auto t: adj[node]) {
            if (dist[t][idx] > dist[node][idx] + 1) {
                dist[t][idx] = dist[node][idx] + 1;
                q.push(t);
            }
        }
    }
}

void solve() {
    cin >> n >> m >> a >> b >> c;
    for (long long i = 1; i <= n; i++)
        adj[i].clear();
    for (long long i = 1; i <= m; i++)
        cin >> P[i];
    sort(P + 1, P + m + 1);
    vector<long long> sum(m + 1);
    for (long long i = 1; i <= m; i++)
        sum[i] = sum[i - 1] + P[i];
    for (long long i = 0, u, v; i < m; i++) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    bfs(a, 0);
    bfs(b, 1);
    bfs(c, 2);
    long long ans = 1e17;
    for (long long i = 1; i <= n; i++) {
        long long d1 = dist[i][0];
        long long d2 = dist[i][1];
        long long d3 = dist[i][2];
        if (d1 + d2 + d3 > m)continue;
        long long cur = sum[d2] + (sum[d3 + d2 + d1]);
        ans = min(ans, cur);
    }
    cout << ans << endl;
}

signed main() {
    long long T;
    cin >> T;
    while (T--) {
        solve();
    }
}