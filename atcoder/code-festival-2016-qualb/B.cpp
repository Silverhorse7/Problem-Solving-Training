#include <bits/stdc++.h>
 
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define reps(i, s, n) for (int i = s; i < (n); ++i)
#define all(it) it.begin(),it.end()
#define gcd(a, b) __gcd(a, b)
#define lcm(a, b) a / __gcd(a, b) * b
#define out(a) cout << a << endl
 
using namespace std;
using ll=long long;
using ld = long double;
using ull = unsigned long long;
 
const int INF = 2e9;
 
template<typename T> void print(T n){cerr<<n<<endl;}
template<typename T> void print(vector<T> v){for(auto i:v){cerr<<i<<" ";}cerr<<endl;}
template<typename T,typename U> void print(map<T, U> mp){for(auto el:mp){cerr<<el.first<<": "<<el.second<<endl;}}
template<typename T> bool chmax(T& a,const T b){if(a<b){a=b;return true;}return false;}
template<typename T> bool chmin(T& a,const T b){if(a>b){a=b;return true;}return false;}
 
double pi = 3.141592653589793238;
 
int main() {
	int n,a,b;
	cin >> n >> a >> b;
	int total=a+b;
	int curr=0;
	int rank=b,abrank=0;
	string s;
	char c;
	cin >> s;
	rep(i,n) {
		c=s[i];
		if (c=='a' && curr < total) {
			curr++;
			out("Yes");
		}
		else if (c=='b' && curr < total && abrank < rank) {
			curr++;
			abrank++;
			out("Yes");
		}
		else out("No");
	}
}