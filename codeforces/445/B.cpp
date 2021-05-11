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
#define allout(v) for(auto ele : v){cout<<ele<<" ";}cout<<endl
#define allout2(v,size) for(int i = 0 ; i <size;i++){for(int j=0;j<size;j++){cout<<arr[i][j]<<" ";}cout<<endl;}
ll N = 1e5 + 5;
vector<bool>visited(N);
int ans = 0;
int flag = 0;
ll answ = 1;
int dr[4] = { 0, -1,  0, 1 };
int dc[4] = { 1,  0, -1, 0 };
void dfs(int node, vector<vector<int>>&adj)
{
    if (visited[node]){
        return;
    }
    visited[node] = 1;
    for (auto child : adj[node]) {
        if (!visited[child])answ *= 2;
        dfs(child, adj);
    }
}
void solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>>adj(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);

    }
    for (int i =0; i < n; i++) {
        if (!visited[i])
            dfs(i, adj);
    }
    cout << answ << endl;
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