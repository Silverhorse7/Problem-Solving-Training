#include "bits/stdc++.h"

using namespace std;
#define ll long long 
ll ans =0;
signed main() {
        auto solve = []() {
            int n;
            cin >> n;
            vector<int> arr(n);
            for (auto &i: arr)cin >> i;
	vector<ll> prefix (n);
	vector<ll> suffix (n);
	prefix[0] = arr[0];
	for(int i = 1; i < n; i++) {
		prefix[i] = prefix[i-1]+arr[i];
	}
	suffix[n-1] = arr[n-1];
	for(int i = n-2; i >= 0; i--) {
		suffix[i] = suffix[i+1]+arr[i];
	}
	int p2 = n-1;
	for(int p1 = 0; p1 < n && p1 < p2; p1++) {
		while(p2 >= 0 && suffix[p2] < prefix[p1]) {
			p2--;
		}
		if(p1 < p2 && suffix[p2] == prefix[p1]) {
			ans = max(ans,prefix[p1]);
		}
	}
	cout << ans;
        };
        solve();
}