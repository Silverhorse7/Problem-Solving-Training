#include<bits/stdc++.h>

using namespace std;
#define ll long long
const int N = 1003;
ll dp[N][N];
char G[N][N];
int n, m;
const ll mod = 1e9+7;
bool valid(int x, int y) {
    return x >= 1 and y >= 1 and x <= n and y <= m and G[x][y] == '.';
}
ll solve(int i, int j) {
    if (dp[i][j]!=INT_MIN)return dp[i][j];
    return dp[i][j] = ((valid(i - 1, j) ? (solve(i - 1, j))%mod : 0) + (valid(i, j - 1) ? (solve(i, j - 1))%mod : 0))%mod;
}
int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> G[i][j];
            dp[i][j]=INT_MIN;
        }
    }
    dp[1][1]=1;
    ll x= solve(n,m);
    cout<<x;
}