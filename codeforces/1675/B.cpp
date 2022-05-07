#include "bits/stdc++.h"

using namespace std;
#define return goto p1

signed main() {
	int T = 1;
	cin >> T;
	p1:
	while (T--) {
		int n;
		cin >> n;
		vector<int> v(n);
		for (auto &i: v)
			cin >> i;
		int cnt = 0;
		for (int i = n - 1; i > 0; i--) {
			while (v[i] <= v[i - 1]) {
				if (v[i - 1] == 0) {
					cnt = -1e9;
					break;
				}
				v[i - 1] /= 2, cnt++;
			}
			//cout << v[i] << ' ';
		}
		cout << (cnt<0 ? -1 : cnt) << endl;
	}
}