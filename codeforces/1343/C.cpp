#include <bits/stdc++.h>

using namespace std;
const int N = 2e5 + 69;
int a[N];
int n;
signed main() {
    ios_base::sync_with_stdio();
    int t;
    cin >> t;
    while (t--) {
        cin>>n;
        for(int i = 0  ; i <n;i++)cin>>a[i];
        long long sum = 0 ;
        for(int i = 0 ; i <n;){
            int mx = INT_MIN ;
            if(a[i]<0){
                while(i<n and a[i]<0){
                    mx=max(mx,a[i]);
                    i++;
                }
                sum+=mx;
            }
            else{
                while(i<n and a[i]>0){
                    mx=max(mx,a[i]);
                    i++;
                }
                sum+=mx;
            }
        }
        cout<<sum<<endl;
    }
}