#include <bits/stdc++.h>

using namespace std;
#define ll long long
using namespace std;
#define fast {ios_base::sync_with_stdio();}
#define inp(v) for(auto &i : v)cin>>i;
#define T int T;cin>>T;while(T--)
#define ld long double
#define yes {cout<<"YES"<<endl;return;};
#define no {cout<<"NO"<<endl;return;};
#define pow(x,y) ll(pow(x,y))
#define all(v) v.begin(),v.end()
int upper(vector<ll> &x, int val) {
    int start = 0;
    int end = x.size() - 1;
    int target = INT_MAX;
    while (start <= end) {
        int mid = (start + end) / 2;
        if (x[mid] >= val) {
            target = x[mid];
            end = mid - 1;
        } else
            start = mid + 1;
    }
    return target;
}

int lower(vector<ll> &x, int val) {
    int start = 0;
    int end = x.size() - 1;
    int target = INT_MAX;
    while (start <= end) {
        int mid = (start + end) / 2;
        if (x[mid] <= val) {
            start = mid + 1;
            target = x[mid];
        } else {
            end = mid - 1;
        }
    }
    return target;
}
signed main() {
    int n,k;
    cin>>n>>k;
    set<int>st;
    vector<int>suff(n+k+3),v(n+1);
    for(int i =1 ; i <=n;i++)cin>>v[i];
    map<int,int>mp;
    for(int i =1 ; i <=k;i++)mp[v[i]]++;
    ll ans = max(ans,(ll)mp.size()); 
    for(int i = k+1 ; i<=n;i++){
    	mp[v[i-k]]--;
    	if(mp[v[i-k]]==0)mp.erase(v[i-k]);
    	mp[v[i]]++;
    	ans=max(ans,(ll)mp.size());
    }
    cout<<ans;
}