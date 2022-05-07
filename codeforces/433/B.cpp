#include "bits/stdc++.h"

using namespace std;
#define int long long
signed main() {
	int n;
	cin >> n;
	vector<int> v(n + 1), u;
	for (int i = 1; i <= n; i++)cin >> v[i];
	u = v;
	sort(u.begin() + 1, u.end());
	vector<int> P1(n + 1), P2(n + 1);
	for (int i = 1; i <= n; i++)
		P1[i] += P1[i - 1] + v[i], P2[i] += P2[i - 1] + u[i];
	int Q;
	cin >> Q;
	while (Q--) {
		int op, l, r;
		cin >> op >> l >> r;
		cout << (op == 1 ? P1[r] - P1[l - 1] : P2[r] - P2[l - 1]) << endl;
	}
}