#include "bits/stdc++.h"

using namespace std;
char par[300];
char exist[300];

int find(char x) {
	if (par[x] == x)return x;
	return par[x] = find(par[x]);
}

void merge(int a, int b) {
	a = find(a), b = find(b);
	if (a == b)return;
	if (a < b)
		par[b] = a;
	else
		par[a] = b;
}

void init(string &s) {
	for (int i = 0; i < 300; i++)par[i] = i;
	for (auto &i: s)exist[i] = 1;
}

signed main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);
	int T = 1;
	cin >> T;
	while (T--) {
		int n, k;
		cin >> n >> k;
		string s;
		cin >> s;
		init(s);
		int zoz = k;
		for (int i = 0; i < n; i++) {
			exist[s[i]] = 1;
			while (find(s[i]) != 'a' and k > 0) {
				merge(find(s[i]), char(find(s[i]) - 1));
				k--;
			}
		}
		string f = "";
		for (int i = 0; i < n; i++)
			f += char(find(s[i]));
		init(s);
		cout << f << endl;
	}
}