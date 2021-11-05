#include<bits/stdc++.h>

using namespace std;
#define ll long long
const int N = 1e5 + 5;
ll a[N], b[N], c[N];
ll dp[N][4];
int n;
int main() {
    cin >> n;
    for (int i = 1; i <= n; i++)cin >> a[i]>>b[i]>>c[i];
    dp[1][1]=a[1];
    dp[1][2]=b[1];
    dp[1][3]=c[1];
    for(int i =2 ;i <=n;i++){
        dp[i][1]=max(dp[i-1][2],dp[i-1][3])+a[i];
        dp[i][2]=max(dp[i-1][1],dp[i-1][3])+b[i];
        dp[i][3]=max(dp[i-1][1],dp[i-1][2])+c[i];
    }
    cout<<*max_element(dp[n],dp[n]+4);
}