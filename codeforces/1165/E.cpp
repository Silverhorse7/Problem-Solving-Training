#include "bits/stdc++.h"

using namespace std;
#define ll long long
    const int mod = 998244353;
int main() {
    ll n;
    cin>>n;
    vector<pair<ll,ll>>a(n);
    vector<ll>b(n);
    for(auto &ele : a )cin>>ele.first;
    for(int i =  0 ; i <n;i++){
        a[i].second=i+1;
    }
    for(int i = 0 ; i<n;i++){
        a[i].first*=(a[i].second*(n-a[i].second+1));
       // a[i].first%=mod;
    }
    for(auto &ele : b)cin>>ele;
    sort(a.begin(),a.end());
    sort(b.begin(),b.end(),greater<int>());
    ll ans = 0;
    for(int i =0 ; i <n;i++)
    {
        a[i].first%=mod;
        b[i]%=mod;
        ans+=(a[i].first*b[i]%mod);
        ans%=mod;
    }
    cout<<ans<<endl;
}