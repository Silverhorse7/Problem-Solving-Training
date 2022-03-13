#include "bits/stdc++.h"

using namespace std;
#define pb push_back
const int N = 1005;
vector<int> adj[N];
int n, m, s, e, vis[N][N];

vector<int> dijkstra(int s, int e) {
    queue<int> q;
    q.push(s);
    vector<int> dist(n + 1, -1);
    dist[s] = 0;
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        for (auto i: adj[node]) {
            if (dist[i] == -1) {
                dist[i] = dist[node] + 1;
                q.push(i);
            }
        }
    }
    return dist;
}

signed main() {
    cin >> n >> m >> s >> e;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
        vis[u][v] = vis[v][u] = vis[u][u] = vis[v][v] = 1;
    }
    map<int, int> inside;
    auto start = dijkstra(s, e);
    auto end = dijkstra(e, s);
    long long D = start[e];
    long long cnt = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (!vis[i][j]) {
                if (start[i] + end[j] + 1 >= D and start[j] + end[i] + 1 >= D) {
                    cnt++;
                }
            }
        }
    }
    cout << cnt / 2 << endl;
}