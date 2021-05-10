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
ll N = 1e5 + 5;
vector<bool>visited(N);
int ans = 0;
int flag = 0;
void dfs(int node, vector<vector<int>>&adj, int depth)
{
    if (visited[node]){

        flag = node; return;
    }
    visited[node] = true;
    for (int child : adj[node]){
        dfs(child, adj, depth + 1);
}
}
void solve()
{
    int n;
    cin >> n;
    vector<vector<int>>v(n+1 );
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        v[i].push_back(x);
    }
    vector<ll>answer;
    for (int i = 1; i <= n; i++) {
        dfs(i, v, 0);
        answer.push_back(flag);
        for (int i = 0; i < 10000; i++) {
            visited[i] = 0;
        }
        flag = 0;
    }
    allout(answer);
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