#include "bits/stdc++.h"

using namespace std;
vector<vector<int>> g;
vector<bool> work;
vector<int> dist;

void distMark(int node, int par, int depth) {
	dist[node] = depth;
	for (auto e: g[node]) {
		if (e != par) {
			distMark(e, node, depth + 1);
		}
	}
	return;
}

int path = 0;

bool pathFind(int node, int par) {
	bool ans = false;
	if (work[node]) {
		ans = true;
	}
	int nodes = 0;
	for (auto e: g[node]) {
		if (e != par) {
			nodes++;
			ans |= pathFind(e, node);
		}
	}
	if (nodes == 0) {
	}
	if (ans) {
		path += 2;
	}
	return ans;
}

signed main() {
	int T;
	cin >> T;
	while (T--) {
		int n, k;
		cin >> n >> k;
		work.assign(n + 1, false);
		dist.assign(n + 1, -1);
		g.clear();
		g.resize(n + 1);
		int root, endp;
		cin >> root >> endp;
		for (int i = 1; i <= k; i++) {
			int a;
			cin >> a;
			work[a] = true;
		}
		work[endp] = true;
		for (int i = 0; i < n-1; i++) {
			int a, b;
			cin >> a >> b;
			g[b].push_back(a);
			g[a].push_back(b);
		}
		path = 0;
		distMark(root, root, 0);
		pathFind(root, root);
		cout << path - 2 - dist[endp] << endl;

	}
}