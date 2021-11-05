#include<bits/stdc++.h>

using namespace std;
#define ll long long
//dp[i]=max(dp[i],solve(i-1-> k);
const int N = 1e5 + 5;
int k;
ll h[N], dp[N];

ll solve(ll i) {
    if (i <= 0)return INT_MAX;
    if (i == 1)return 0;
    if (dp[i] != INT_MAX)return dp[i];
    for (int j = 1; j <= k; j++) {
        if (i - j <= 0)break;
        dp[i] = min(dp[i], solve(i - j) + abs(h[i] - h[i-j]));
    }
    return dp[i];
}

int main() {
    int n;
    cin >> n >> k;
    for (int i = 1; i <= n; i++)cin >> h[i];
    for(int i =1 ; i <=N;i++)dp[i]=INT_MAX;
    cout << solve(n);
}