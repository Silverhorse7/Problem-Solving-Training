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
	#define b00l bool
	///**************************** C o n s t ****************************///
	const double PI = acos(-1);
	const double eps = 1e-9;
	const int inf = 2000000000; //9 zeros
	const ll infLL = 9000000000000000000;
	const int lazy = int('a' - 'A');
	//const ll N = 1e7 + 1;
	string alphabet = "abcdefghijklmnopqrstuvwxyz";
	ll sum = 0, final = 0, result = 0;
	#define lmao(s,arr) for(int i =  0 ; i <s.size();i++){arr[i]=s[i];}
	#define allout(first) for(auto ele : first) {cout<<ele<<" ";}cout<<endl;
	#define returnYES cout<<"YES"<<endl; return 
	#define returnNO cout<<"NO"<<endl; return;
	///**************************** F U N C T I O N S  ****************************///
	//algorithm
	//	A		Hello
	//	B		Codeforces
	// B.FIND(A[I])==FALSE ? -->A.ERASE(A[I]); :
	string lol="";
	bool isPalindrome(string s)
	{
		string lol = "";
		for(int i = s.size()-1 ; i >=0;i--)
		{
			lol+=s[i];
		}
		if(lol==s)
		{
			return true;
		}
		else{
			return false;
		}
	}
	inline bool IsPowerOfTwo(ll n)
	{
		if (n <= 0)
			return false;
		return (ceil(log2(n)) == floor(log2(n)));
	}
const int N = 2e7;
int primes[N + 1];

void sieve() {
	primes[1] = 1;
	for (int i = 2; i <= N; ++i) {
		if (primes[i]) continue;
		for (int j = i + i; j <= N; j += i) {
			primes[j] = 1;
		}
	}
}
	//Comment Code Block Ctrl + K + C / Ctrl + K + U-->remove comment
	//Comment Code Block Ctrl + K + C / Ctrl + K + U-->remove comment
	void it_is_me_dio_hahahahahaha()
	{
		int n,q;
		cin>>n>>q;
		deque<int>st;
		for(int i = 0 ;  i <n;i++)
		{
			int lol;
			cin>>lol;
			st.push_back(lol);
		}
		while(q--)
		{
			int k ;
			cin>>k;
			for(int i = 0 ;  i <st.size();i++)
			{
				if(st[i]==k)
				{
					cout<<i+1<<" ";
					int copy = st[i];
					st.erase(st.begin()+i);
					st.push_front(copy);
					break;
				}
			}
		}
	}
	// ll keep = 100000000;
	int main()
	{
		Speedo;
		int t;
		t=1;
	//	cin>>t;
		while(t--){
			it_is_me_dio_hahahahahaha();
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
	/*
	imagine u have number x
x gets to divise by y lol times and z lmao times and f lmfao times and so on
then the number of divisors is equal to :
(lol+1) * (lmao+1) * (lmfao +1 ) * ......
*/
