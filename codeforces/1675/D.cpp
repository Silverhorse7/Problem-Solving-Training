#include "bits/stdc++.h"

using namespace std;

signed main() {
	int T = 1;
	cin >> T;
	while (T--) {
		int n;
		cin >> n;
		vector<int> p(n + 1);
		int root = 0;
		vector<int> adj[n + 3], revadj[n + 3];
		for (int i = 1; i <= n; i++) {
			cin >> p[i], p[i] == i ? root = i : root = root;
			adj[p[i]].push_back(i);
			revadj[i].push_back(p[i]);
		}
		vector<vector<int>> ans;
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
		for (int i = 0; i <= n; i++)
			if (i != 0)Depths[d[i]].push_back(i);
		vector<int> temp;
		map<int, int> vis;
		function<void(int)> dfs = [&](int x) {
			if (vis[x])return;
			vis[x] = 1;
			temp.push_back(x);
			for (auto i: revadj[x])
				dfs(i);
		};
		for (auto i: Depths) {
			for (auto j: i.second) {
				dfs(j);
				if (temp.empty())continue;
				reverse(temp.begin(), temp.end());
				ans.push_back(temp);
				temp.clear();
			}
		}
		cout << ans.size() << endl;
		for (auto i: ans) {
			cout << i.size() << endl;
			for (auto j: i)cout << j << ' ';
			cout << endl;
		}
	}
}