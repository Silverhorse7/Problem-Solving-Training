#include<bits/stdc++.h>
using namespace std;
int dp[300000][3];
signed main() {
    int t;
    cin>>t;
    while(t--){
        long long int a,b,k;
        cin>>a>>b>>k;
        cout<<a*((k+1)/2)-b*(k/2)<<endl;
    }
}