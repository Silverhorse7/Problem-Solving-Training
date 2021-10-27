#include <bits/stdc++.h>

#define ll long long
using namespace std;
const int N = 2e5 + 69;
int a[N];
int n;
pair<int, ll> dp[2];

pair<int,int> solve(int i) {
    if (i < 0)return {0,0};
    bool parity = a[i]>0;
    pair<int,int>v=solve(i-1);
    dp[parity]=max(dp[parity],{dp[!parity].first+1,dp[!parity].second+a[i]});
}
void s(){

    cin >> n;
    for (int i = 0; i < n; i++)cin >> a[i];
    for(int i=1 ; i<n;i++){
        if(abs(a[i]-a[i-1])>=2){cout<<"YES\n";cout<<i<<' '<<i+1<<endl;return;}
    }
    cout<<"NO\n";
}
signed main() {
    ios_base::sync_with_stdio();
    int t;
    cin >> t;
    while (t--) {
s();

    }
}