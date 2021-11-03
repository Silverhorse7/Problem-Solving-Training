#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 3e5;
int a[N];
map<int,int>mp;
int main(){
	int n;
	cin>>n;
	ll ans=0;
	for(int i = 0 ; i <n;i++){
		int x;
		cin>>x;
		ans+=i-mp[x];
		mp[x]++;
	}
	cout<<ans;
}