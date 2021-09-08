#include<bits/stdc++.h>
using namespace std;
#define no {cout<<"NO"<<endl;return;};
void solve(){
    int n;
    cin>>n;
    string s;cin>>s;
    int x = s.find("ab");
    int y = s.find("ba");
    if(x!=-1){
        cout<<x+1<<" "<<x+2<<endl;
    }
   else if(y!=-1){
        cout<<y+1<<" "<<y+2<<endl;
    }
   else{
       cout<<-1<<' '<<-1<<endl;
   }
}
signed main() {
int t;
cin>>t;
while(t--)solve();
}