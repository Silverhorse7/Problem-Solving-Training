#include <bits/stdc++.h>

using namespace std;
#define ll long long
using namespace std;
#define fast {ios_base::sync_with_stdio();}
#define T int T;cin>>T;while(T--)
#define ld long double
#define yes {cout<<"YES"<<endl;return;};
#define no {cout<<"NO"<<endl;return;};
int getRemainder(int num, int divisor)
{
    return (num - divisor * (num / divisor));
}
void solve(){
    ll x,y;
    cin>>x>>y;
    if (x <= y) {
        cout << y - (((x+y)/2)-x * ( ((x+y)/2)/x)) << endl;
    } else {
        cout << (x + y) << endl;
    }
}
signed main() {
    T {
        solve();
    }

    return 0;
}