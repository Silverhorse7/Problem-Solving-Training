#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define vi vector<int>
#define vl vector<ll>
#define q(v, n) for(ll i = 0 ;  i <n;i++)cin>>v[i];
#define q1(v, n) for(ll i = 1 ;  i <=n;i++)cin>>v[i];
#define out(v) {for(auto &a : v)cout<<a<<' ';cout<<endl;}
#define re resize
#define all(v) v.begin(),v.end()
#define no {printf("%s\n","NO");return 0;};
#define yes {printf("%s\n","YES");return 0;};
#define minus {printf("%s\n","-1");return 0;};
#define IM INT_MAX
#define Cin cin
#define inti ll i
#define intj ll j
#define OR or
const int N =4e5+69;
ll a[N],b[N],pa[N],pb[N],n,m,k;
ll calc(ll val,ll pb[],int l){
    int cnt = 0 ;
    for(int i =val;i<=l;i++){
        if(pb[i]-pb[i-val] ==val)cnt++;
    }
    return cnt;
}
signed main(){
    cin>>n>>m>>k;
    q1(a,n);
    q1(b,m);
    for(int i =1 ; i <=n;i++)pa[i]= pa[i - 1] + a[i];
    for(int i =1 ; i <=m;i++)pb[i]= pb[i - 1] + b[i];
    set<ll>divs;
    for(ll i = 1 ; i*i<=k;i++){
        if(k%i==0){
            divs.insert(i);
        }
    }
    ll ans=  0 ;
    for(auto ele : divs){
        ll val=k/ele;
        if(val==ele)ans+=calc(val,pa,n)*calc(ele,pb,m);
        else{
            ans+=calc(val,pb,m)*calc(ele,pa,n);
            ans+=calc(val,pa,n)*calc(ele,pb,m);
        }
    }
    cout<<ans<<endl;
}