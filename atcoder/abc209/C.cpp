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
signed main() {
	int n;
	cin>>n;
	vector<int>v(n);
	for(auto &i : v)cin>>i;
	sort(all(v));
	ll ans = v[0];
	for(int i =1 ; i <n;i++){
		ans*=(v[i]-i);
		ans%=((int)(1e9+7));
	}
	cout<<ans;
}