#include<bits/stdc++.h>
using namespace std;
    vector<long long int>v,dp;
    int k;
    long long int solve(int i){
        if(i==0)return 0;
        if(~dp[i])return dp[i];
        dp[i]=INT_MAX;
        for(int j = i-1 ;j>=i-k and j>=0;j--){
            dp[i]=min(solve(j)+(abs(v[i]-v[j])),dp[i]);
        }
        return dp[i];
    }
signed main() {
    int n;
    cin>>n>>k;
    v.resize(n);for(auto &ele  :v)cin>>ele;
    dp.resize(n+123,-1);
    cout<<solve(n-1);
}