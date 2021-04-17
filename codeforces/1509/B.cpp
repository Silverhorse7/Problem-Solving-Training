#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long 
#define allout(v) for(auto ele : v){cout<<ele<<" ";}cout<<endl
void it_was_me_dio_hahahahahaha()
{
	int n;
	cin>>n;
	string s;
	cin>>s;
	int m=0,t=0;
	for(int i = 0 ; i<n;i++)
	{
                if(s[i]=='T')
                {
                    t++;
                }
                else
                {
                    m++;
                }
		if(m>t)
		{
			cout<<"NO"<<endl;return;
		}
	}
	t=0;
	m=0;
	for(int i =n-1;i>=0;i--)
	{
                if(s[i]=='T')
                {
                    t++;
                }
                else
                {
                    m++;
                }
		if(m>t)
		{
			cout<<"NO"<<endl;return;
		}
	}
	if(count(s.begin(),s.end(),'T')==count(s.begin(),s.end(),'M')*2)
	{
		cout<<"YES"<<endl;
	}
	else{
		cout<<"NO"<<endl;
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