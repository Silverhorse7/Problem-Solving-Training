#include "bits/stdc++.h"

using namespace std;
#define ll long long
string s;

int main() {
    cin >> s;
    s='s'+s;
    int n = (int) s.size();
    vector<int>a(n+1),b(n+1);
    for(int i =1; i <=n;i++){
        a[i]=a[i-1]+(s[i]=='a');
        b[i]=b[i-1]+(s[i]=='b');
    }
    int ans = 0 ;
    for(int i = 0 ; i <=n;i++){
        for(int j = i;j<=n;j++){
            ans=max(ans,a[n]-a[j]+b[j]-b[i]+a[i]);
        }
    }
    cout<<ans<<endl;
}