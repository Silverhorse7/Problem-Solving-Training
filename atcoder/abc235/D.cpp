#include<bits/stdc++.h>

using namespace std;
#define ll long long

class Dijkstra {
public:
    struct Edge {
        long long to, cost;
    };
    vector<ll> d;
    vector<vector<Edge>> G;

    Dijkstra(int n) {
        G = vector<vector<Edge>>(n);
        d = vector<ll>(n, 1e18);
    }

    void add_edge(ll from, ll to, ll cost) {
        Edge e = {to, cost};
        G[from].push_back(e);
    }

    void dijkstra(ll s) {
        priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> que;
        d[s] = 0;
        que.push(pair<ll, ll>(0, s));

        while (!que.empty()) {
            pair<ll, ll> p = que.top();
            que.pop();
            ll v = p.second;
            if (d[v] < p.first) continue;
            for (int i = 0; i < G[v].size(); i++) {
                Edge e = G[v][i];
                if (d[e.to] > d[v] + e.cost) {
                    d[e.to] = d[v] + e.cost;
                    que.push(pair<ll, ll>(d[e.to], e.to));
                }
            }
        }
    }
};

ll cicle(ll a) {
    ll k = a % 10;
    ll kk = k * pow(10, to_string(a).size() - 1);
    return a / 10 + kk;
}

signed main() {
    long long a, N;
    cin >> a >> N;
    Dijkstra djk(1e6 + 4);
    for (int i = 1; i <= 1e6; i++) {
        if (i * a < 1e6) {
            djk.add_edge(i, i * a, 1);
        }
        if (i >= 10 && (i % 10) != 0) {
            string s = to_string(i);
            string y = "";
            y += s.back();
            s.pop_back();
            for (auto j: s)y += j;
            djk.add_edge(i, stoll(y), 1);
        }
    }
    djk.dijkstra(1);
    cout << (djk.d[N] < 1e9 ? djk.d[N] : -1) << endl;
}