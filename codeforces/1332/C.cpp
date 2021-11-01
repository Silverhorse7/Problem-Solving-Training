#include <bits/stdc++.h>

using namespace std;
#define ll long long
using namespace std;
#define fast {ios_base::sync_with_stdio();}
#define T int T;cin>>T;while(T--)
#define ld long double
#define yes {cout<<"YES"<<endl;return;};
#define no {cout<<"NO"<<endl;return;};
const int N = 3e5 + 55;
vector<int> adj[N];
bool vis[N];
string s;

signed main() {
    T {
        int n;
        int k;
        cin >> n >> k;
        vector<int> alpha(199);
        for (int i = 0; i <= n; i++)vis[i] = 0, adj[i].clear();
        string kss;
        cin >> kss;
        s = 'a' + kss;
        for (int i = 1; i <= n; i++)adj[i].push_back(n - i + 1);
        for (int i = 1; i+k <= n; i++)adj[i].push_back(i + k), adj[i + k].push_back(i);
        ll ans = 0;
        ll total_calls;

        for (int i = 1; i <= n; i++) {
            if (vis[i])continue;
            total_calls = 0;
            for(auto &j : alpha)j=0;
            int node = i;
            queue<int> q;
            alpha[s[node]]++;
            total_calls += 1;
            q.push(node);
            vis[node]=1;
            while (!q.empty()) {
                node = q.front();
                q.pop();
                for (int child: adj[node])
                    if (!vis[child]) {
                        alpha[s[child]]++;
                        total_calls += 1;
                        q.push(child);
                        vis[child] = true;
                    }
            }
            ans += total_calls - *max_element(alpha.begin(), alpha.end());

        }
        cout << ans << endl;
    }
}