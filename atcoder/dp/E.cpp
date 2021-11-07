#include<bits/stdc++.h>

using namespace std;
#define ll long long
const int N = 1e5+5;
int n, m;
vector<vector<ll>> dp(102, vector<ll>(N,-1));
vector<pair<int, int>> v(N);

ll solve(int i, int val) {
    if (i > n)return INT_MAX;
    if (i == n)return (val == 0 ? 0 : INT_MAX);
    if (~dp[i][val])return dp[i][val];
    return dp[i][val] = min(solve(i + 1, val),
                            (v[i].second <= val ?  v[i].first + solve(i+1,val - v[i].second) : INT_MAX));
}

signed main() {
    cin >> n >> m;
    int mx = 0;
    for(int i = 0 ;i<n;i++)cin>>v[i].first>>v[i].second;
    for(int i=N-3;i>=0;i--){
        if(solve(0,i)<=m){
            cout<<i;return 0;
        }
    }

}