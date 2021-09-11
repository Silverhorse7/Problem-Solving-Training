
#include<bits/stdc++.h>
using namespace std;
signed main() {
    cin.tie();
    cout.tie();
    ios_base::sync_with_stdio();
    int t;
    cin>>t;
    while(t--){
        long long int x,y,n;
        cin>>x>>y>>n;
        long long int ans=x*(n/x)+y;
        cout<<ans+(ans>n ? -x : 0)<<endl;
        //ans+num*x <=n
    }
}