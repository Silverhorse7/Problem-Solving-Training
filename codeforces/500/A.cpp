#include <bits/stdc++.h>
#include <vector>
using namespace std;
#define ll long long
#define Speedo ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define all(x) x.begin(),x.end()
#define pb push_back
#define endl       '\n'
#define return0 return 0
#define Endl endl
#define ull unsigned long long
#define elif else if 
#define test   cout<<" We Fucked up Here Boss_________________"<<endl
ll N = 1e5 + 5;
vector<bool>visited(N);
int ans = 0;
bool flag = 0;
void dfs(int node,vector<vector<int>>&adj,int depth,int t)
{
    if (visited[node])
        return;
    visited[node] = true;
    if (node == t) {
        flag = 1;
    }
   // cout << node << endl;
    for (int child : adj[node])
        dfs(child,adj,depth+1,t);
}
void solve()
{
    int n, t;
    cin >> n >> t;
    t--;
    vector<vector<int>>v(n + 1);
    for (int i = 1; i <= n - 1; i++) {
        int x;
        cin >> x;
        v[i - 1].push_back(i-1 + x);
    }
    dfs(0, v, 0, t);
    if (flag) {
        cout << "YES" << endl;
    }
    else
        cout << "NO" << endl;
}
int main()
{
    Speedo;
    int t = 1;
   // cin >> t;
    while (t--)
    {
        solve();
    }
}