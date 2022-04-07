#include <bits/stdc++.h>

using namespace std;
const int N = 1e5 + 5, mod = 1e9 + 7, SQ = 317, LOG = 18;

bool vis2[N];
int up[N][LOG];
vector<int> G[N];
int lvl[N], vis[N], ans[N];
map<pair<int, int>, int> id;

void dfs(int node, int par) {
    for (int i = 1; i < LOG; i++)
        up[node][i] = up[up[node][i - 1]][i - 1];

    for (auto ch: G[node]) {
        if (ch == par)
            continue;

        up[ch][0] = node;
        lvl[ch] = lvl[node] + 1;

        dfs(ch, node);
    }
}

int getKthParent(int node, int k) {
    for (int i = LOG - 1; i >= 0; i--) {
        if ((k >> i) & 1)
            node = up[node][i];
    }
    return node;
}

int lca(int a, int b) {
    if (lvl[b] > lvl[a])
        swap(a, b);

    a = getKthParent(a, lvl[a] - lvl[b]);

    if (a == b)
        return a;

    for (int i = LOG - 1; i >= 0; i--) {
        if (up[a][i] != up[b][i])
            a = up[a][i], b = up[b][i];
    }
    return up[a][0];
}

void dfs2(int node) {
    if (vis2[node])return;
    vis2[node] = 1;
    for (auto child: G[node])
        if (lvl[child] < lvl[node])
            vis[child] += vis[node], ans[id[{min(node, child), max(node, child)}]] = vis[node];
}

signed main() {
    int n;
    scanf("%d", &n);
    for (int i = 1; i < n; i++) {
        int u, v;
        scanf("%d%d", &u, &v);
        G[u].push_back(v);
        G[v].push_back(u);
        id[{min(u, v), max(u, v)}] = i;
    }
    dfs(1, -1);
    int k;
    scanf("%d", &k);
    while (k--) {
        int u, v;
        scanf("%d%d", &u, &v);
        vis[u]++, vis[v]++, vis[lca(u, v)] -= 2;
    }
    vector<pair<int, int>> nodes;
    for (int i = 1; i <= n; i++)//level for each node
        nodes.emplace_back(lvl[i], i);

    sort(nodes.rbegin(), nodes.rend());
    for (auto child: nodes)
        if (!vis2[child.second])
            dfs2(child.second);
    for(int i =1 ; i <n;i++)
        cout<<ans[i]<<' ';
}