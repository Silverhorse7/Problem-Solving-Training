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
	int k;
	cin >> k;
	//k%m +k%w = 100%w
	int a = 100 - k;
	for (int i = 2; i < 100; i++) {
		while ((k % i == 0) && (a % i == 0)) {
			k /= i;
			a /= i;
		}
	}
	cout << a + k << endl;
}
int main() {
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
}