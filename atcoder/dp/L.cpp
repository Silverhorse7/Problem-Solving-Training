#include<bits/stdc++.h>

using namespace std;
const int N = 3005;
int n, a[N];
int64_t dp[N][N][2];

long long solve(int x, int y, bool player) {
    if (x > y)return 0;
    if (~dp[x][y][player])return dp[x][y][player];
    auto &c = dp[x][y][player];
    c=max(a[x]-solve(x+1,y,player^1),a[y]-solve(x,y-1,player^1));
    return c;
}

signed main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    memset(dp,-1,sizeof dp);
    printf("%lld",solve(1,n,0));
}