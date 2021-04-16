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

vector<ll>lucky_number_from10000000_to100000000/*from 1e7 to 1e8*/ = { 44447777,44474777,44477477,44477747,44477774,44744777,44747477,44747747,44747774,44774477,44774747,44774774,44777447,44777474,44777744,47444777,47447477,47447747,47447774,47474477,47474747,47474774,47477447,47477474,47477744,47744477,47744747,47744774,47747447,47747474,47747744,47774447,47774474,47774744,47777444,74444777,74447477,74447747,74447774,74474477,74474747,74474774,74477447,74477474,74477744,74744477,74744747,74744774,74747447,74747474,74747744,74774447,74774474,74774744,74777444,77444477,77444747,77444774,77447447,77447474,77447744,77474447,77474474,77474744,77477444,77744447,77744474,77744744,77747444,77774444,4444477777 };
void it_is_me_dio_hahahahahaha()
{
	
}
void it_was_me_dio_hahahahahaha()
{
	int n, q;
	cin >> n >> q;
	vector<int>v;
	vector<int>k;
	while (n--)
	{
		int f; cin >> f;
		v.push_back(f);
		k.push_back(f);
		
	}
	sort(all(k), greater<int>());
	int ind = -1;
	f(i, k.size())
	{
		if (k[i] == 1)
		{
			ind = i;
		}
	}
	while (q--)
	{
		int f; cin >> f; 
		if (f == 1)
		{
			int x; cin >> x; x--;
			if (v[x] == 1)
			{
				k[ind] = 0;
				ind--;
				v[x] = 0;
			}
			else
			{
				v[x] = 1;
				ind++;
			}
		}
		if (f == 2)
		{
			int x; cin >> x; x--;
			if (x > ind)
			{
				cout << 0 << endl;
			}
			else if (ind == -1)
			{
				cout << 0 << endl;
			}
			else {
				cout << 1 << endl;
			}
		}
	}
}
int main()
{
    Speedo;
	int t;
	t = 1;
	//cin >> t;
	while (t--)
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