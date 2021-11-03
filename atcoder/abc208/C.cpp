#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
	ll N,K;
	cin>>N>>K;
	vector<pair<ll,pair<ll,ll>>>v(N+1);
	for(ll i = 1;  i<=N;i++)cin>>v[i].first,v[i].second.first = i ;
	sort(v.begin()+1,v.end());
	ll incre = 0 ;
	// K*x >=N  ->x>=N/k
	incre+=K/N;
	K=K%N;
	for(ll i = 1;i<=K;i++)v[i].second.second+=1;
	for(ll i =1; i <=N;i++)v[i].second.second+=incre;
	vector<ll>ans(N+1);
	for(ll i =1 ; i <=N;i++)ans[v[i].second.first]=v[i].second.second;
	for(ll i =1 ; i <=N;i++)cout<<ans[i]<<endl;
}