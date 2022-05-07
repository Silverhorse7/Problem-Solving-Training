#include <bits/stdc++.h>
using namespace std;

int64_t n1, n2, k1, k2;

const int64_t mod = (int64_t)1e8;

map<pair<pair<int64_t,int64_t>,pair<int64_t,int64_t>>,int64_t>dp;

int64_t dfs(int64_t i, int64_t j, int64_t a, int64_t b) {
    if(i + j == n1 + n2)
        return 1;
    if(dp.count({{i,j}, {a,b}}))
        return dp[{{i,j},{a,b}}];
    int64_t ret = 0;
    if(a) {
        if(a+1 <= k1 && i < n1) {
            ret += dfs(i+1, j, a+1, 0);
        }
        if(j < n2)
            ret += dfs(i, j+1, 0, 1);
            ret %= mod;
    } else {
        if(b + 1 <= k2 && j < n2) {
            ret += dfs(i, j+1, 0, b+1);
        }
        if(i < n1)
            ret += dfs(i+1, j, 1, 0);
            ret %= mod;
    }
    return dp[{{i,j},{a,b}}] = ret;
}

signed main() {
    cin>>n1>>n2>>k1>>k2;
    cout << (dfs(1,0,1,0)+dfs(0,1,0,1))%mod;
    return 0;
}
