#include<bits/stdc++.h>
using namespace std;
void solve(){
    string s;
    cin>>s;
    bitset<64>bs=stoll(s);
    long long int cnt = 0 ;
    s="";for(int i =64-1 ; i >=0;i--)s+=std::to_string(bs[i]);
    for(int i =64-1 ; i >=0;i--){
        cnt+=(s[i]=='1' ?pow(2,(64-i))-1 : 0);
    }
    cout<<cnt<<endl;
}
signed main() {
    int t;
    cin>>t;
    while(t--)solve();
}