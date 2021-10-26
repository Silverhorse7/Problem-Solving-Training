#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define vi vector<int>
#define vl vector<ll>
#define q(v, n) for(ll i = 0 ;  i <n;i++)cin>>v[i];
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
const int N = 1e4 + 69;
signed main() {
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        set<int>s;
        for(int i =1;i<=n;i++)s.insert(i);
        for(int i = 0 ;  i<m;i++){
            int a,b,c;
            cin>>a>>b>>c;
            s.erase(b);
        }
        int x = *s.begin();
        for(int i = 1;i<=n;i++){
            if(i!=x){
                cout<<x<<' '<<i<<endl;
            }
        }
    }
}