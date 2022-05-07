#include "bits/stdc++.h"

using namespace std;

signed main() {
	string s;
	int Q;
	cin >> s >> Q;
	vector<int> P(s.size() + 1);
	s = ' ' + s;
	int n = s.size();
	for (int i = 1; i < n; i++) {
		P[i] = P[i - 1];
		if (s[i] == s[i - 1])P[i]++;
	}
	while (Q--) {
		int l, r;
		cin >> l >> r;
		int cnt = P[r] - P[l - 1];
		if (s[l] == s[l - 1])cnt--;
		cout << cnt << endl;
	}
}