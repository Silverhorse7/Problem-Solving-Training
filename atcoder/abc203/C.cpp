#include<bits/stdc++.h>

#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization("unroll-loops")
using namespace std;
#define fast {ios_base::sync_with_stdio();}
#define ll long long
#define T int T;cin>>T;while(T--)
#define ld long double
#define yes {cout<<"YES"<<endl;return;};
#define no {cout<<"NO"<<endl;return;};
#define vi vector<int>
#define in(v, n) {for(int i =0 ;  i <n;i++)cin>>v[i];}
#define oo 12345678912345678

int main() {
    int n, k;
    cin >> n >> k;
    vector<pair<ll,ll>>v(n);
    for(int i  = 0 ; i <n;i++)cin>>v[i].first>>v[i].second;
    ll start = 0;
    ll money = k;
    sort(v.begin(),v.end());
    for (int i = 0; i <n; i++) {
        if (v[i].first > (money + start))break;
        money -= (v[i].first - start);
        money += v[i].second;
        start = v[i].first;
    }
    cout << start + money;
}