#include <bits/stdc++.h>

#define ll long long
using namespace std;
const int N = 2e5 + 69;
ll n;
signed main() {
    ios_base::sync_with_stdio();
    int t;cin>>t;
    while(t--){
        cin>>n;
        int steps = 0 ;
        while(n!=1){
            if(n%2==0){
                n/=2;
            }
            else if (n%3==0){
                n=(2*n)/3;
            }
            else if(n%5==0){
                n=(4*n)/5;
            }
            else{
                steps=-1;break;
            }
            steps++;
        }
        cout<<steps<<endl;
    }
}