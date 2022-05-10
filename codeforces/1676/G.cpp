#include "bits/stdc++.h"

using namespace std;

signed main() {
	int T = 1;
	cin >> T;
	while (T--) {
		int n;
		cin >> n;
		vector<int> p(n + 1);
		int root = 1;
		vector<int> adj[n + 3], revadj[n + 3];
		for (int i = 2; i <= n; i++) {
			cin >> p[i], p[i] == i ? root = i : root = root;
			adj[p[i]].push_back(i);
		}
		string ans;
		int cnt = 0;
		queue<int> Q;
		Q.push(root);
		map<int, vector<int>, greater<>> Depths;
		vector<int> d(n + 33);
		d[root] = 1;
		while (!Q.empty()) {
			auto f = Q.front();
			Q.pop();
			for (auto i: adj[f]) {
				if (d[i] == 0 and i != root)
					d[i] = d[f] + 1, Q.push(i);
			}
		}
		cin >> ans;
		vector<long long> cost(n + 33);
		int ansss = 0;
		//cout << ans.size() << endl;
		function<void(int, int)> dfs = [&](int cur, int par) {
			cost[cur] = (ans[cur - 1] == 'W' ? 1 : -1);
			for (auto i: adj[cur])
				if (i != par) {
					dfs(i, cur);
					cost[cur] += cost[i];
				}
			if (cost[cur] == 0)
				ansss++;
		};
		dfs(root, root);
		cout << ansss << endl;
	}
}