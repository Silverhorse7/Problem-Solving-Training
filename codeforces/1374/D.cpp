#include "bits/stdc++.h"
using namespace std;
signed main() {
    cin.tie();
    cout.tie();
    ios_base::sync_with_stdio();
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int k;
        cin >> k;
        vector<int> v(n);
        for (auto &ele: v) {
            cin >> ele;
            ele = ele % k;
        }
        long long int increase =0 ;
        long long int ans = 0 ;
        sort(v.begin(),v.end(),greater<int>());
        for (int i = 0; i < n; i++) {
            if(v[i]==0)continue;
            if(i==0 or v[i]!=v[i-1]){
                increase=k-v[i];
            }
            else{
                increase+=k;
            }
            ans=max(ans,increase+1);
        }
        cout<<ans<<endl;
    }
}