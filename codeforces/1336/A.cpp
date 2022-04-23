#include "bits/stdc++.h"

using namespace std;
#define int long long
const int N = 5e5;
int n, k;
vector<int> adj[N];
int happiness[N], industry[N], dep[N];
int vis[N];
int cnt[N];

void dfs(int root, int cur_score) { //to calculate the happiness of each node.
    if (vis[root])return;
    vis[root] = 1;
    happiness[root] = cur_score;
    for (auto i: adj[root]) {
        dfs(i, cur_score + (industry[root] == 0 ? 1 : 0));
    }
}

void dfs2(int root, int d) {//calculate
    if (vis[root])return;
    vis[root] = 1;
    cnt[root] = 1;
    dep[root] = d;
    for (auto i: adj[root]) {
        if (!vis[i]) {
            dfs2(i, d + 1);
            cnt[root] += cnt[i];
        }
    }
}

signed main() {
    scanf("%lld%lld", &n, &k);

    for (int i = 1; i < n; i++) {
        int u, v;
        scanf("%lld%lld", &u, &v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs2(1, 0);

    fill(vis, vis + N, 0);

    vector<pair<int, int>> v;

    for (int i = 1; i <= n; i++)
        v.emplace_back(dep[i] - cnt[i], i);

    sort(v.rbegin(), v.rend());

    for (int i = 0; i < k; i++)
        industry[v[i].second] = 1;

    dfs(1, 0);

    int ans = 0;

    for (int i = 1; i <= n; i++)
        if (industry[i] == 1)
            ans += happiness[i];

    printf("%lld", ans);
}