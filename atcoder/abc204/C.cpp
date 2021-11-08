#include<bits/stdc++.h>

#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization("unroll-loops")
using namespace std;
#define fast {ios_base::sync_with_stdio();}
#define ll long long
#define T int T;cin>>T;while(T--)
#define ld long double
#define yes {cout<<"YES"<<endl;return;};
#define no {cout<<"NO"<<endl;return;};
const int N = 2005;
vector<int> adj[N];
int vis[N];

void dfs(int node, ll &val) {
    vis[node] = 1;
    for (auto ele : adj[node]) {
        if (!vis[ele]) {
            val++;
            dfs(ele, val);
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
    }
    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        dfs(i, ans);
        for (auto &j : vis)j = 0;
    }
    cout << ans+n << endl;
}