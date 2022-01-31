	#include<bits/stdc++.h>
	
	using namespace std;
	
	void solve() {
	    string s;
	    cin >> s;
	    string ans = "";
	    if(stoll(s)%7==0){cout<<s<<endl;return;}
	    for (int i = 0; i < s.size(); i++) {
	        for (int j = '0'; j <= '9'; j++) {
	            if (i == 0 and j == '0')continue;
	                        char x = s[i];
	            s[i] = j;
	
	            if(stoll(s)%7==0)ans=s;
	            s[i]=x;
	        }
	    }
	    cout<<ans<<endl;    
	}
	
	signed main() {
	    int t;
	    cin >> t;
	    while (t--)solve();
	}