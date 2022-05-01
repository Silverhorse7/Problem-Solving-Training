#include "bits/stdc++.h"

using namespace std;
#define vi vector<int>
const int N = 5e5;

vector<int> adj[N];
vi tin(N, -1), low(N, -1), parent(N), vis(N);
vi rnk(N);
vector<pair<int, int>> bridges;

int get_par(int x) { return parent[x] == x ? x : (parent[x] = get_par(parent[x])); }

void merge(int x, int y) {
    x = get_par(x), y = get_par(y);
    if (x == y)return;
    if (rnk[x] > rnk[y])swap(x, y);
    parent[x] = y;
    rnk[y] += rnk[x];
}

void dfs(int v, int p = -1) {
    static int timer = 0;
    vis[v] = true;
    tin[v] = low[v] = timer++;
    for (auto to: adj[v]) {
        if (to == p) continue;
        if (vis[to]) {
            low[v] = min(low[v], tin[to]);
        } else {
            dfs(to, v);
            low[v] = min(low[v], low[to]);
            if (low[to] > tin[v])
                bridges.push_back({v, to});
            else
                merge(v, to);
        }
    }
}

vector<int> Bridge_Tree[N];
int st;

void build() {
    for (auto i: bridges) {
        int x = get_par(i.first), y = get_par(i.second);
        st = x;
        Bridge_Tree[x].push_back(y);
        Bridge_Tree[y].push_back(x);
    }
}

pair<int, int> diameter(int x) {
    queue<int> q;
    q.push(x);
    vector<int> D(N);
    int f;
    while (q.size()) {
        f = q.front();
        q.pop();
        for (auto it: Bridge_Tree[f]) {
            if (D[it] == 0 and it != x)
                D[it] = D[f] + 1, q.push(it);
        }
    }
    return {f, D[f]};
}

signed main() {
    for (int i = 0; i < N; i++)
        rnk[i] = 1, parent[i] = i;
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    dfs(1);
    build();
    cout << diameter(diameter(st).first).second << endl;
}