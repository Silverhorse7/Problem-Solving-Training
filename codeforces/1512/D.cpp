#include <bits/stdc++.h>
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
#define ezi(lblb) int lblb; cin>>lblb
#define ezll(lblb) ll lblb; cin>>lblb		
#define pii pair<int,int>pair
//#define int ll
#define star *
///**************************** C o n s t ****************************///
const double PI = acos(-1);
const double eps = 1e-9;
const int inf = 2000000000; //9 zeros
const ll infLL = 9000000000000000000;
const int lazy = int('a' - 'A');
const ll N = 1e7 + 1;
string alphabet = "abcdefghijklmnopqrstuvwxyz";
ll sum = 0, final = 0, result = 0;
#define lmao(s,arr) for(int i =  0 ; i <s.size();i++){arr[i]=s[i];}
#define allout(first) for(auto ele : first) {cout<<ele<<" ";}cout<<endl;
#define f(i,n) for(int i = 0 ; i<n;i++)
#define ceil(x) static_cast<long long>(ceil(x))
#define float(x) static_cast<long long>(float(x))
#define round(x) static_cast<long long>(round(x))
///**************************** F U N C T I O N S  ****************************///
//Comment Code Block Ctrl + K + C / Ctrl + K + U-->remove comment
template <class T = int>
T scan() {
	T res;
	std::cin >> res;
	return res;
}
int invertBits(int num)
{
	int x = log2(num) + 1;
	for (int i = 0; i < x; i++)
		num = (num ^ (1 << i));
	return num;
}
bool correctbracketsequence(string s)
{
	stack<char>stk;
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] == '(')
		{
			stk.push(s[i]);
		}
		else {
			if (stk.size() > 0)
			{
				stk.pop();
			}
			else {
				return false;
			}
		}
	}
	if (stk.size() > 0)return false;
	return true;
}
void checklater()//that bitmasks problem
{
	string s;
	cin >> s;
	if (count(all(s), 'A') == count(all(s), 'B') and count(all(s), 'C') % 2 != 0)
	{
		cout << "YES" << endl; return;
	}
	int koko = count(all(s), 'A');
	int lolo = count(all(s), 'B');
	if (koko < lolo)
	{
		for (int i = 0; i < s.size(); i++)
		{
			if (s[i] == 'C')s[i] = 'A';
		}
	}
	if (koko > lolo)
	{
		for (int i = 0; i < s.size(); i++)
		{
			if (s[i] == 'C')s[i] = 'B';
		}
	}
	// first one is (
	char kekw = s[0];
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] == kekw)s[i] = '(';
		else {
			s[i] == ')';
		}
	}
	if (correctbracketsequence(s))
	{
		cout << "YES" << endl;
	}
	else {
		cout << "NO" << endl;
	}
}
int sums(string s)
{
	int lol = 0;
	for (auto ele : s)
	{
		lol += (ele - '0');
	}
	return lol;
}
void it_was_me_dio_hahahahahaha()// if u need precision with ceil
// remove the ceil macro
{
	// algorithm used , so. defenitely , the sum is one of the biggest 2 elements , right ? , since then the sum of the elements will be equal to it 
// at that moment we can use the prefix sum
	ll n;
	cin >> n;
	n += 2;
	vector<ll>v(n);
	vector<ll>prefix(n);
	for (int i = 0; i < n; i++)cin >> v[i];
	sort(all(v));
	prefix[0] = v[0];
	for (int i = 1; i < n; i++)
	{
		prefix[i] = prefix[i - 1] + v[i];
	}
	vector<ll>lolo = { v[n - 2],v[n - 1] };
	vector<ll>koko = { prefix[n - 3]+v[n-1],prefix[n - 2] };
	ll sum = -1, fake = -1;
	for (int i = 0; i < lolo.size(); i++)
	{
		for (int j = 0; j < v.size(); j++)
			if (koko[i] - v[j] == lolo[i])
			{
				sum = lolo[i];
				fake = v[j];
			}
	}
	if (sum == -1) { cout << -1 << endl; return; }
	for (int i = 0; i < v.size(); i++)
		if (v[i] == sum)
		{
			v[i] = 0;
			break;
		}
	for (int i = 0; i < v.size(); i++)
		if (v[i] == fake)
		{
			v[i] = 0;
			break;
		}
	ll summn = 0;
	for (int i = 0; i < v.size(); i++)summn += v[i];
	if (summn == sum or summn == fake)
	{
		for (int i = 0; i < v.size(); i++)
		{
			if (v[i] != 0)
			{
				cout << v[i] << " ";
			}
		}
		cout << endl; return;
	}
	cout << -1 << endl; return;
}
int main()
{
	Speedo;
	int t;
	t = 1;
	cin >> t;
	while(t--)
	{
		it_was_me_dio_hahahahahaha();
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