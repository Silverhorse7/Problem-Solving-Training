#include <bits/stdc++.h>

using namespace std;
#define ll long long
using namespace std;
#define fast {ios_base::sync_with_stdio();}
#define inp(v) for(auto &i : v)cin>>i;
#define T int T;cin>>T;while(T--)
#define ld long double
#define yes {cout<<"YES"<<endl;return;};
#define no {cout<<"NO"<<endl;return;};
#define pow(x,y) ll(pow(x,y))
#define all(v) v.begin(),v.end()
int upper(vector<ll> &x, int val) {
    int start = 0;
    int end = x.size() - 1;
    int target = INT_MAX;
    while (start <= end) {
        int mid = (start + end) / 2;
        if (x[mid] >= val) {
            target = x[mid];
            end = mid - 1;
        } else
            start = mid + 1;
    }
    return target;
}

int lower(vector<ll> &x, int val) {
    int start = 0;
    int end = x.size() - 1;
    int target = INT_MAX;
    while (start <= end) {
        int mid = (start + end) / 2;
        if (x[mid] <= val) {
            start = mid + 1;
            target = x[mid];
        } else {
            end = mid - 1;
        }
    }
    return target;
}
signed main() {
    int n,m;
    cin>>n>>m;
    vector<ll>a(n),b(m);
    inp(a);
    inp(b);
    sort(all(b));
    ll mn = INT_MAX;
    for(int i =0 ; i <n;i++){
        mn=min({mn,abs(a[i]-lower(b,a[i])),abs(a[i]-upper(b,a[i]))});
    }
    cout<<mn;
}