#include <bits/stdc++.h>

using namespace std;
const int N = 2e5;
vector<int> adj[N];
vector<int> depths(N);
vector<bool> vis(N);

void bfs(int node) {
    queue<int> q;
    q.push(node);
    vis[node] = 1;
    depths[node] = 1;
    while (!q.empty()) {
        node = q.front();
        vis[node] = 1;
        q.pop();
        for (auto &child: adj[node]) {
            if (!vis[child]) {
                depths[child] = depths[node] + 1;
                q.push(child);
            }
        }
    }
}

bool flag = 0;

void bfss(int node) {
    queue<int> q;
    q.push(node);
    vis[node] = 1;
    while (!q.empty()) {
        node = q.front();
        vis[node] = 1;
        q.pop();
        for (auto &child: adj[node]) {
            if (child == node)continue;
            if (depths[child] <= depths[node])flag = 1;
            if (!vis[child]) {
                q.push(child);
            }
        }
    }
}

signed main() {
    string a, b, c;
    map<char,int>k,m;
    int s=0;
    cin >> a >> b >> c;
    a = a + b;
    for (int i = 0; i < a.size(); i++)
        k[a[i]]++;
    for (int i = 0; i < c.size(); i++)
        m[c[i]]++;
    for (int i = 65; i < 91; i++)
        if (m[i] != k[i]) s = 1;    // cout<<s<<" ";
    //  if(a.size()+b.size()!=c.size())	s=1; cout<<s<<" "<<endl;
    if (s == 1) cout << "NO";
    else cout << "YES";
    return 0;
}