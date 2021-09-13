#include "bits/stdc++.h"
using namespace std;
void B(){
    //000011110000
    string s;
    cin>>s;
    int mn =INT_MAX,x,y;
    x=count(s.begin(),  s.end(),'0'),y=count(s.begin(),  s.end(),'1');
    mn=2;
    int zrs = 0 ;
    for(int i  = 0 ; i <s.size();i++){
        if(s[i]=='0'){zrs++;while(i<s.size() and s[i]=='0')i++;}
    }
    cout<<min(mn,zrs)<<endl;
}
signed main() {
    int t;
    cin>>t;
    while(t--){B();
    }
}