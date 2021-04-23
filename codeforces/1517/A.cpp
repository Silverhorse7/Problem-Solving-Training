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
bool checkperfectsquare(int n)
{
	if (ceil((double)sqrt(n)) == floor((double)sqrt(n))) {
		return 1;
	}
	else {
		return 0;
	}
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
 ll btsetdiff(string sh,string shoh)
{
	ll diff = 0;
	ll n = sh.size();
	for (int i = 0; i < n; i++)
	{
		if (sh[i] != shoh[i])diff++;
	}
	return diff;
}
string dec_to_bin_str(ll x)
{
	string fol = "";
	int num = x;
	int bin;
	while (num > 0)
	{
		bin = num % 2;
		if (bin == 1)fol += '1';
		else
			fol += '0';
		num /= 2;
	}
	return fol;
}
int convertBinaryToDecimal(string n)
{
	reverse(all(n));
	int cnt = 0;
	for (int i = 0; i < n.size(); i++)
	{
		cnt += (n[i] - '0') * static_cast<ll>(pow(2, i));
	}
	return cnt;
}
long int countConsecutive(long int N)
{
	// constraint on values of L gives us the 
	// time Complexity as O(N^0.5)
	long int count = 0;
	int increase = 2;
	for (long int L = 2050; L * (L + 1) < 2 * N; L*=increase)
	{
		float a = (1.0 * N - (L * (L + 1)) / 2) / (L + 1);
		if (a - (int)a == 0.0)
			count++;
	}
	return count;
}
void it_was_me_dio_hahahahahaha()// if u need precision with ceil
// remove the ceil macro
{
	vector<ll>divisors = { 2050,20500,205000,2050000,20500000,205000000,2050000000,20500000000,205000000000,2050000000000,20500000000000,205000000000000,2050000000000000,20500000000000000,205000000000000000,2050000000000000000 };
	reverse(all(divisors));
	ll x;
	cin >> x;
	int cnt = 0;
	if (x % 2050 != 0 or x < 2050)
	{
		cout << -1 << endl; return;
	}
	for (auto ele : divisors)
	{
		while (x - ele >= 0)
		{
			//cout << ele << " ";
			x -= ele;
			cnt++;
		}
	}
	cout << cnt << endl;
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