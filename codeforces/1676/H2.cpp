
#include "bits/stdc++.h"
 
using namespace std;
 
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
 
#define ordered_set tree<pair<int,int>, null_type,less<pair<int,int>>, rb_tree_tag,tree_order_statistics_node_update>
 
signed main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    int T;
    cin>>T;
    while(T--){
    int n;
    cin>>n;
    vector<int>p(n);
    ordered_set os;
    long long cnt=  0 ;
    for(int i = 0 ; i <n;i++){
        cin>>p[i];
        cnt+=(i)-os.order_of_key({p[i],-1});
        os.insert({p[i],i});
    }
    cout<<cnt<<endl;
    }
}