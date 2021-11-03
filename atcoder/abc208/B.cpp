#include<bits/stdc++.h>
using namespace std;
#define ll long long
long long fact(int x ){
	ll y = 1;
	for(int i =1 ; i <=x;i++){
		y*=i;
	}
	return y;
}
int main(){
	long long p;
	cin>>p;
	vector<int>facts(11);
  facts[0] = 1;
  for (int i = 1; i <= 10; i++) {
    facts[i] = facts[i - 1] * i;
  }
		ll ans = 0 ;
		for(int i=10 ; i >=1;i--){
			while(p>=facts[i]){
				ans++;
				p-=facts[i];
			}
		}
		cout<<ans;
}