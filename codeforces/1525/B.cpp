#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define Speedo ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define all(x) x.begin(),x.end()
#define pb push_back
#define endl       '\n'
#define return0 return 0
#define Endl endl
#define ull unsigned long long
#define elif else if 
#define test   cout<<" We Droped up Here Boss_________________"<<endl
#define allout(v) for(auto ele : v){cout<<ele<<" ";}cout<<endl
bool valid(int i ,int j) {
	return (i >= 0 and j >= 0);//add the limits later
}

void dfs() {
}
void bfs() {
}
void fastpower() {
}
void dijkstra() {
}
void solve() {
	int n;
	cin >> n;
	vector<int>sorted(n);
	vector<int>v(n);
	for (int i = 0; i < n; i++){
		cin >> sorted[i]; v[i] = sorted[i];
}//retest
	sort(all(sorted));
	if (v == sorted) {
		cout << 0 << endl;
	}
	elif(v[0] == 1 or v[n - 1] == n)cout << 1 << Endl;
	elif(v[0] == n and v[n - 1] == 1)cout << 3 << endl;
	else
		cout << 2 << Endl;
}
int main() {
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
}