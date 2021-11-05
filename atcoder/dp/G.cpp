#include<bits/stdc++.h>

using namespace std;
#define ll long long
const int N=1e5+5;
vector<int>adj[N];
int dp[N];
int solve(int i){
    if(dp[i])return dp[i];
   // cout<<i<<endl;
    for(auto ele : adj[i]){
        dp[i]=max(dp[i],solve(ele)+1);
    }
    return dp[i];
}
int main() {
    int n,m;cin>>n>>m;
    for(int i =0; i <=m;i++){
        int x,y;cin>>x>>y;
        adj[x].push_back(y);
    }
    int mx = 0 ;
    for(int i =1; i <=1e5+1;i++){
        solve(i);
    }
    cout<<*max_element(dp,dp+N);
}