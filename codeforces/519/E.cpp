#include <bits/stdc++.h>

using namespace std;
const int N = 100005, D = 19;
vector<int> g[N];
int n, root;
int par[D][N], depth[N], sub[N];

void dfs(int v, int p, int d) {
    par[0][v] = p;
    sub[v] = 1;
    depth[v] = d;
    for (int i = 0; i < g[v].size(); ++i) {
        if (g[v][i] != p) {
            dfs(g[v][i], v, d + 1);
            sub[v] += sub[g[v][i]];
        }
    }
}

void init() {
    dfs(root, -1, 0);
    for (int k = 0; k + 1 < D; ++k) {
        for (int v = 1; v <= n; ++v) {
            if (par[k][v] < 0) par[k + 1][v] = -1;
            else par[k + 1][v] = par[k][par[k][v]];
        }
    }
}

int lca(int u, int v) {
    if (depth[u] > depth[v]) swap(u, v);
    for (int k = 0; k < D; ++k) {
        if ((depth[u] - depth[v]) >> k & 1) {
            v = par[k][v];
        }
    }
    if (u == v) return u;
    for (int k = D - 1; k >= 0; --k) {
        if (par[k][u] != par[k][v]) {
            u = par[k][u];
            v = par[k][v];
        }
    }
    return par[0][u];
}

 int kth(int x, int len) {
    int ans = x;
    for(int i = 0 ; i <D;i++) {
        if (len & (1 << i)) ans = par[i][ans];
    }
    return ans;
}

signed main() {
    int a, b, m;
    scanf("%d",&n);
    for(int i =1 ; i <n;i++) {
        scanf("%d%d",&a,&b);
        g[a].push_back(b);
        g[b].push_back(a);
    }
    root = 1;
    init();
    cin >> m;
    for(int i = 0 ; i <m;i++) {
        scanf("%d%d",&a,&b);
        if (a == b) {
            printf("%d\n", n);
            continue;
        }
        int c = lca(a, b);
        if (depth[a] == depth[b]) {
            int len = depth[a] - depth[c];
            int u = kth(a, len - 1), v = kth(b, len - 1);
            printf("%d\n", n - sub[u] - sub[v]);
        }
        else {
            if (depth[a] < depth[b]) swap(a, b);
            int dist = depth[a] - depth[b];
            if (dist & 1) printf("0\n");
            else {
                int len = depth[a] - depth[c] - dist / 2;
                int v = kth(a, len), u = kth(a, len - 1);
                printf("%d\n", sub[v] - sub[u]);
            }
        }
    }
    return 0;
}