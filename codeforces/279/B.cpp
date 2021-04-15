#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long 
void it_was_me_dio_hahahahahaha()
{
	ll n,t;
	cin>>n>>t;
	vector<ll>v;
	for(int i = 0 ; i <n;i++)
	{
		ll k ;cin>>k;
		v.push_back(k);
	}
	ll sum = 0 ;
	int cpy=0;
	for(int i= 0 ; i <n;i++)
	{
		sum+=v[i];
		if(sum>t)
		{
			sum-=v[cpy];
			cpy++;
		}
	}
	cout<<n-cpy<<endl;
}
int  main()
{
       ios_base::sync_with_stdio(0); cin.tie(0);
	int t;
	t = 1;
	//cin >> t;
	while (t--)
	{
		it_was_me_dio_hahahahahaha();
	}
}