#include<bits/stdc++.h>
using namespace std;
    vector<vector<int>>adj(1000007);
    vector<bool>vis(1000007);
int main(){
	int T;
	cin>>T;
	while(T--){
		int n;
		cin>>n;
		vector<int>cnt(32);
		for(int i=0 ; i <n;i++){
			int x;cin>>x;
			int vovo = 0;
			while(x){
				cnt[vovo++]+=(x%2);
				x/=2;
			}
		}
    for (int j = 1; j <= n; j++) {
    	bool ok =true;
      for (int i = 0; i <= 31; i++)
        if (cnt[i] % j) ok=false;
      if (ok) cout << j << ' ';
    }
		cout<<endl;
	}
}