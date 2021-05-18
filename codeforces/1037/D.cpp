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
#define test   cout<<" We Droped up Here Boss _________________ "<<endl  
#define allout(v) for(auto ele : v){cout<<ele<<" ";}cout<<endl
#define mk make_pair
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pcc pair<char,char>
#define vi vector<int>
#define vl vector<ll>
#define vvi vector<vector<int>>
#define vvl vector<vector<ll>>
#define inputtt freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout);
#define vb vector<bool>
int cnt = 0;
vector<int>tosearch;
bool recurs(vvi & adj, vi &tosearch, int node,int tosearchfor) {
	if (cnt == tosearch.size()-1) {
		return true;
	}
	bool flag = false;
	for (auto el : adj[tosearch[node]]) {
		if (el == tosearch[tosearchfor]) {
			flag = true; break;
		}
	}
	if (flag == true) {
		cnt++;
		cout << "YES" << endl;
		recurs(adj, tosearch, node + 1, tosearchfor + 1);
	}
	else {
		return false;
	}
}
vi inputorder(200007), relorder(200007);
bool cmp(int a, int b) {
	return relorder[a] < relorder[b];
}
vb visited(1e6 + 1);
vi ans;
void bfs(int node,vvi&adj)
{
	queue<int> q;
	q.push(node);
	visited[node] = true;
	while (!q.empty())
	{
		node = q.front();
		ans.push_back(node);
		q.pop();
		for (int child : adj[node])
			if (!visited[child])
			{
				q.push(child);
				visited[child] = true;
			}
	}
}
int main() {	
	int n;
	cin >> n;
	vvi adj(n + 1);
	for (int i = 0; i < n-1; i++) {
		int x, y;
		cin >> x >> y;
		adj[x].pb(y);
		adj[y].push_back(x);
	}
	vector<int>v;
	for (int i = 0; i < n; i++) {
		cin >> inputorder[i];
		v.push_back(inputorder[i]);
		relorder[inputorder[i]] = i;
	}
	for (int i = 1; i <= n; i++)
		sort(all(adj[i]), cmp);
	bfs(1, adj);
	if (ans == v)cout << "yes";
	else
		cout << "no";
}