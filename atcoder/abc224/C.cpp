#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 3e5;
bool checkTriangle(ll x1, ll y1, ll x2,
                   ll y2, ll x3, ll y3)
{
    ll a = x1 * (y2 - y3)
            + x2 * (y3 - y1)
            + x3 * (y1 - y2);
    if (a == 0)
        return 0;
    else
        return 1;
}
int main(){
	int n;
	cin>>n;
	vector<pair<ll,ll>>P(n);
	for(int i = 0 ; i<n;i++)cin>>P[i].first>>P[i].second;
	ll ans = 0 ;
	for(int i =0 ; i <n;i++){
		for(int j = 0 ; j <n;j++){
			for(int k = 0 ; k <n;k++){
				if(k==j or k==i or j==i)continue;
				if(checkTriangle(P[i].first,P[i].second,P[j].first,P[j].second,P[k].first,P[k].second)){
					ans++;
				}
			}
		}
	}
	cout<<ans/6;
}