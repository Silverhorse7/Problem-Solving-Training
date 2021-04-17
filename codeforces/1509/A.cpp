#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long 
void it_was_me_dio_hahahahahaha()
{
	int n;
	cin>>n;
	vector<int>odds;
	vector<int>evens;
	while(n--)
	{
		int k ;
		cin>>k;
		if(k%2!=0)
		{
			odds.push_back(k);
		}
		else{
			evens.push_back(k);
		}
	}
	for(auto ele : odds)
	{
		cout<<ele<<" ";
	}
	for(auto ele : evens)
	{
		cout<<ele<<" ";
	}
}
int  main()
{
       ios_base::sync_with_stdio(0); cin.tie(0);
	int t;
	t = 1;
	cin >> t;
	while (t--)
	{
		it_was_me_dio_hahahahahaha();
	}
}