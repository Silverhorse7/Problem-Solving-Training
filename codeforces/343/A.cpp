#include<bits/stdc++.h>

#define ll long long
#define all(x) x.begin(),x.end()
#define yes {cout<<"YES"<<endl;return;}
#define no {cout<<"NO"<<endl;return;}
using namespace std;

int main() {
    ll a,b;
    cin>>a>>b;
    ll ans=  0 ;
    if(a%b==0)return cout<<a/b,0;
    while(b>1 or a>1){
        if(a>b){
            ans+=a/b;
            a%=b;
        }
        else
            ans+=b/a,b%=a;
    }
    cout<<ans;
}