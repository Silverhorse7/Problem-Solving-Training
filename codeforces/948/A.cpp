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
void dfs(int node,vector<vector<int>>&adj,int depth)
{
    if (visited[node])
        return;
    ans = max(ans, depth);
    visited[node] = true;
    for (int child : adj[node])
        dfs(child,adj,depth+1);
}
void solve()
{
    int n, m;
    cin >> n >> m;
    char arr[n+99][m+99];
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> arr[i][j];
            if (arr[i][j] == '.') {
                arr[i][j] = 'D';
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (arr[i][j] == 'W') {
                if (arr[i][j - 1] == 'S' or arr[i - 1][j] == 'S' or arr[i][j + 1] == 'S' or arr[i + 1][j] == 'S') {
                    cout << "NO" << endl; return;
                }
            }
        }
    }
    cout << "YES" << endl;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cout << arr[i][j];
        }
        cout << endl;
    }
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