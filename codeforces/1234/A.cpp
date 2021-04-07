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
	///**************************** F U N C T I O N S  ****************************///
	//algorithm 
	//	A		Hello
	//	B		Codeforces
	// B.FIND(A[I])==FALSE ? -->A.ERASE(A[I]); : 
	bool isSubset(vector<int>arr1, vector<int>arr2,
		int m, int n)
	{
		int i = 0;
		int j = 0;
		for (i = 0; i < n; i++)
		{
			for (j = 0; j < m; j++)
			{
				if (arr2[i] == arr1[j])
					break;
			}

			if (j == m)
				return 0;
		}
	}
	bool isPalindrome(string s)
	{
		string lol = s;
		reverse(lol.begin(), lol.end());
		if (s == lol)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	inline bool IsPowerOfTwo(ll n)
	{
		if (n <= 0)
			return false;
		return (ceil(log2(n)) == floor(log2(n)));
	}
	//const ll n = 1000000000;     
	//vector<bool>primes(n, true);
	//void sieve(ll n)
	//{
	////	vector<char>primes(n + 1, true);
	//	for (ll p = 2; p * p <= n; p++)
	//	{
	//		if (primes[p] == true)
	//		{
	//			for (int i = p * p; i <= n; i++)
	//			{
	//				primes[i] = false;
	//			}
	//		}
	//	}
	//}
	//Comment Code Block Ctrl + K + C / Ctrl + K + U-->remove comment
	void it_is_me_dio_hahahahahaha()
	{
		int n;
		cin >> n;
		 sum = 0;
		for (int j = 0; j < n; j++)
		{
			int lol; cin >> lol;
			sum += lol;
		}
		cout << static_cast<long long>(ceil(double(sum) / n)) << endl;
	}
	// kol al fekra  ank btshof lw tkrar al 7rf aktr mn al tanen
	int main()
	{
		Speedo;
		int t;
		t = 1;

		cin >> t;
		while (t--)
		{
			it_is_me_dio_hahahahahaha();
		}
		return 0;
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