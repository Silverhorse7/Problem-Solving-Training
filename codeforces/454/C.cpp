#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define all(v) v.begin(),v.end()
#define cc(x)              cout<<#x<<" = { "<<x<<" }\n"
#define allout(v) {for(auto ele  : v)cout<<ele<<" ";cout<<endl;}
#define endl "\n"
#define yes cout<<"YES"<<endl;
#define no cout<<"NO"<<endl;
int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    int n,m;
    cin>>m>>n;
    double ans = m ;
    for(int i = 1 ; i <m;i++){
        ans-=pow((double)i/m , n);
    }
    cout<<fixed<<setprecision(9)<<ans<<endl;
}