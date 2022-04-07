#include<bits/stdc++.h>
using namespace std;
int main(){
	int T;	
	cin>>T;
	while(T--){
		string s;
		cin>>s;
		map<char,int>mp;
		for(auto i : s)
		mp[i]++;
		string ans= s;
		reverse(ans.begin(),ans.end());
		
		for(int i = 0 ; i <s.size();i++){
			if(mp[s[i]]==1){
				break;
			}
			ans.pop_back();
			mp[s[i]]--;
		}
				reverse(ans.begin(),ans.end());
		cout<<ans<<endl;
	}
}