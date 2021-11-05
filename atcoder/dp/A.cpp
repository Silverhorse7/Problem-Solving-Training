#include<bits/stdc++.h>

using namespace std;
#define ll long long
//dp[i]=max(dp[i],solve(i-1)+abs(diff),solve(i-2)+abs(diff));
const int N = 1e5 + 5;

ll h[N], dp[N];
int diff(int x , int y){
    return abs(h[x]-h[y]);
}

ll solve(int i) {
    if (i <= 0)return INT_MAX;
    if (i == 1)return 0;
    if (dp[i] != INT_MAX)return dp[i];
    return dp[i]=min(solve(i-1)+diff(i,i-1),solve(i-2)+diff(i,i-2));
}

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)cin >> h[i];
    for(int i =1 ; i <=N;i++)dp[i]=INT_MAX;
    cout << solve(n);
}