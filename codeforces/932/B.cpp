#include <bits/stdc++.h>
#include <vector>
using namespace std;
///**************************** M a c r o ****************************///
#define fi(i,n) for(int x = 0 ; x<n;x++) //to write 2d arrays faster ,generally arrays use
#define ll long long
#define Speedo ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define f(i,m,n) for(int i=m; i<n; i++)
#define all(x) x.begin(),x.end()
#define pb push_back
#define print(arr,size) for(int i = 0; i<size;i++){cout<<arr[i]<<" ";}cout<<endl;
#define news(f) int f; cin>>f;
#define endl          '\n'
#define return0 return 0
#define Endl endl
#define ull unsigned long long
#define ssort(arr,n) sort(arr,arr+n)
#define elif else if 
#define lo(f) if (f>='a' && f<='z')
#define up(f) if (f>='A' && f<='Z')
#define pff(a) a.size()
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) (a*(b/gcd(a,b)))
#define test   cout<<" We Fucked up Here Boss_________________"<<endl
#define pii pair<int,int>pair
#define lmao(s,arr) for(int i =  0 ; i <s.size();i++){arr[i]=s[i];}
#define allout(first) for(auto ele : first) {cout<<ele<<" ";}cout<<endl;
#define f(i,n) for(int i = 0 ; i<n;i++)
#define ceil(x) static_cast<long long>(ceil(x))
#define float(x) static_cast<long long>(float(x))
#define round(x) static_cast<long long>(round(x))
#define cnt(s,k) count(all(s),k)
///**************************** F U N C T I O N S  ****************************///
//Comment Code Block Ctrl + K + C / Ctrl + K + U-->remove comment
template <class T = int>
T scan() {
	T res;
	std::cin >> res;
	return res;
}
ll fastpower(ll base, ll power, ll m)
{
	if (power == 0)return 1;
	int res = fastpower(base, power / 2, m) % m;
	res *= res;
	if (power % 2)
	{
		return ((res % m) * (base % m)) % m;
	}
	else {
		return res % m;
	}
}
int koko = 0;
int knapSack(int W, int wt[], int val[], int n)
{

	// Base Case
	if (n == 0 || W == 0)
		return 0;

	// If weight of the nth item is more
	// than Knapsack capacity W, then
	// this item cannot be included
	// in the optimal solution
	if (wt[n - 1] > W)
		return knapSack(W, wt, val, n - 1);

	// Return the maximum of two cases:
	// (1) nth item included
	// (2) not included
	else
		return max(
			val[n - 1]
			+ knapSack(W - wt[n - 1],
				wt, val, n - 1),
			knapSack(W, wt, val, n - 1));
}
 void solve(int indx, vector<int>& v, int weight, int n,int dod=0)
{
	vector<int>ally;
	//base case
	if (indx >= v.size() or weight>n)
	{
		return;
	}
	if (weight == n)
	{
		for (auto ele : ally)cout << ele << " ";
		cout << endl;
		ally.clear();
	}
	//transition
	ally.push_back(v[indx]);
	solve(indx+1, v, weight,n,dod);
	solve(indx + 1, v, weight + v[indx], n,dod+1);
}
 const int l = 1000000;
int main()
{
	Speedo;
	int t;
	t = 1;
	vector<vector<int>>v(10);
	vector<int>nums = { 1,2,3,4,5,6,7,8,9 };
	for (int i = 0; i <= l; i++)
	{
		string s = to_string(i);
		int prod = 1;
		for (auto ele : s)if (ele != '0')prod *= (ele - '0');
		while (prod > 9)
		{
			s = to_string(prod);
			prod = 1;
			for (auto ele : s)if (ele != '0')prod *= (ele - '0');
		}
		v[prod].push_back(i);
	}
	cin >> t;
	while (t--) {
		int l, r, k; cin >> l >> r >> k;
		auto U = upper_bound(all(v[k]), r);
		auto w =lower_bound(all(v[k]), l);
		cout << U - w << endl;
	}
}
// static (data type) by3'aly al data type mostmr 
/**/
/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
	* DON'T GET STUCK ON ONE APPROACH
	* DON"T GET STUCK ON ONE PROBLEM
*/
// 1 1 1 1 1 1 1 1 
// 1,1 1,2 1,3 1,4 1,5 1,6 1,7 1,8 