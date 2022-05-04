#include "bits/stdc++.h"

using namespace std;

signed main() {
    int T;
    cin >> T;
    while (T--) {
        auto solve = [&]() {
            int n, x;
            cin >> n >> x;
            vector<vector<int>> adj(n + 1);
            for (int i = 0; i < n - 1; i++) {
                int u, v;
                cin >> u >> v;
                adj[u].push_back(v);
                adj[v].push_back(u);
            }
            int mn = INT_MAX;
            auto bfs = [&]() {
                queue<int> Q;
                Q.push(x);
                auto isleaf = [&](int x) {
                    return adj[x].size() == 1;
                };
                vector<int> dist(n + 1);
                while (!Q.empty()) {
                    auto xx = Q.front();
                    Q.pop();
                    if (isleaf(xx))mn = min(mn, dist[xx]);
                    for (auto i: adj[xx]) {
                        if (dist[i] == 0 and i != x)
                            dist[i] = dist[xx] + 1, Q.push(i);
                    }
                }
            };
            bfs();
            cout << (mn == 0 or n % 2 == 0 or n==1 ? "Ayush" : "Ashish") << endl;
        };
        solve();
    }
}