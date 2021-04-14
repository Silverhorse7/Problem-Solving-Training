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
///**************************** F U N C T I O N S  ****************************///
//Comment Code Block Ctrl + K + C / Ctrl + K + U-->remove comment
template <class T = int>
T scan() {
	T res;
	std::cin >> res;
	return res;
}
bool pal(int n)
{
	string lol = to_string(n);
	string s = to_string(n);
	reverse(s.begin(), s.end());
	if (s == lol)
	{
		return true;
	}
	else {
		return false;
	}
}
#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll n = 800000;
vector<ll> prime(n + 1); // initializes as 0 all indexes from 0 to n

vector<ll> it_is_me_dio_hahahahahaha()
{

	prime[1] = 1;
	for (int p = 2; p <= n; p++)
	{
		for (int i = p; i <= n; i += p) {
			prime[i] += p;
		}
		prime[p]++; // add the divisor 1.
	}

	return prime;

}
vector<string>all_numbers = { "1","11","111","1111","2","22","222","2222","3","33","333","3333","4","44","444","4444","5","55","555","5555","6","66","666","6666","7","77","777","7777","8","88","888","8888","9","99","999","9999" };
int main()
{
    Speedo;
	int t;
	cin >> t;
	while (t--)
	{
		string s;
		cin >> s;
		int sum = 0;
		for (int i = 0; i < all_numbers.size(); i++)
		{
			sum += all_numbers[i].size();
			if (s == all_numbers[i])
			{
				break;
			}
		}
		cout << sum << endl;
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