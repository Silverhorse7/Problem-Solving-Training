#include "bits/stdc++.h"

using namespace std;
#define return goto p1

signed main() {
	int T = 1;
	cin >> T;
	p1:
	while (T--) {
		int a, b, c, x, y;
		cin >> a >> b >> c >> x >> y;
		x -= min(a, x);
		y -= min(b, y);
		if (c >= x + y) {
			cout << "Yes" << endl;
		} else
			cout << "NO" << endl;
	}
}