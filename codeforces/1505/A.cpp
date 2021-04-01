#include <bits/stdc++.h>
#define ll long long
const ll mod = 1e9 + 72321;
using namespace std;
#define Speedo ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#include <bits/stdc++.h>
#define all(v) v.begin(),v.end()
        void solve()
        {
            string s;
            while(getline(cin,s))
            {
                if(s=="Is it rated?")
                {
                    cout<<"NO"<<endl;
                }
                else{
                    cout<<"YES"<<endl;
                }
            }
        }
int main()
{
    Speedo;
    int t;
    t=1;
    //cin>>t;
    while(t--){
        solve()    ;
    }
}