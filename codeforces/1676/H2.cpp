//#pragma GCC optimize("Ofast")
//#pragma GCC optimize ("unroll-loops")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include "bits/stdc++.h"
#include <ext/pb_ds/assoc_container.hpp>
#include <random>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;

using namespace __gnu_pbds;
template<class T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag,
		tree_order_statistics_node_update>;
using namespace std;
#define ll long long
#define Silver_is_better_than_Gold \
    ios_base::sync_with_stdio(0);  \
    cin.tie(0);                    \
    cout.tie(0);
#define all(x) x.begin(), x.end()
#define allr(x) x.rbegin(), x.rend()
#define pb push_back
#define endl '\n'
#define test cout << " We Droped up Here Boss _________________ " << endl
#define pii pair<int, int>
#define vi vector<int>
#define vl vector<ll>
#define vvi vector<vector<int>>
#define vvl vector<vector<ll>>
#define no                    \
    {                         \
        cout << "NO" << endl; \
    }
#define yes                    \
    {                          \
        cout << "YES" << endl; \
    }
const int mod = 1e9 + 7;
#define sz(x) ((int)(x).size())
#define dups(divs) divs.erase(unique(divs.begin(), divs.end()), divs.end());
#define sum(v) accumulate(v.begin(), v.end(), 0ll)
#define T       \
    int XXX;    \
    cin >> XXX; \
    while (XXX--)
#define F first
#define SS second
#define ld long double
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

template<class A>
istream &operator>>(istream &cin, pair<A, A> p) {
	return cin >> p.first >> p.second;
}

template<class A>
istream &operator>>(istream &cin, vector<A> &p) {
	for (int i = 0; i < sz(p) - 1; i++)
		cin >> p[i];
	return cin >> p.back();
}

template<class A>
ostream &operator<<(ostream &cout, pair<A, A> const &v) {
	return cout << v.first << ' ' << v.second << endl;
}

template<class A>
ostream &operator<<(ostream &cout, vector<A> const &v) {
	for (auto ele: v) {
		cout << ele << " ";
	}
	cout << endl;
	return cout;
}

ll fastpow(ll base, ll power, ll M) {
	if (power == 1)
		return base;
	ll val = fastpow(base, power / 2, M);
	return (power % 2 == 0) ? (val * val) % M : (((val * val) % M) * base) % M;
}

///////////////////////////////////////////////////////////////////////////]
long long cnt = 0;
// structure to hold queries
struct Query {
	int l, r, x, idx;
};

// structure to hold array
struct ArrayElement {
	int val, idx;
};

// bool function to sort queries according to k
bool cmp1(Query q1, Query q2) {
	return q1.x < q2.x;
}

// bool function to sort array according to its value
bool cmp2(ArrayElement x, ArrayElement y) {
	return x.val < y.val;
}

// updating the bit array
void update(int bit[], int idx, int val, int n) {
	for (; idx <= n; idx += idx & -idx)
		bit[idx] += val;
}

// querying the bit array
int query(int bit[], int idx, int n) {
	int sum = 0;
	for (; idx > 0; idx -= idx & -idx)
		sum += bit[idx];
	return sum;
}

void answerQueries(int n, Query queries[], int q,
                   ArrayElement arr[]) {
	// initialising bit array
	int bit[n + 1];
	memset(bit, 0, sizeof(bit));

	// sorting the array
	sort(arr, arr + n, cmp2);

	// sorting queries
	sort(queries, queries + q, cmp1);

	// current index of array
	int curr = 0;

	// array to hold answer of each Query
	int ans[q];

	// looping through each Query
	for (int i = 0; i < q; i++) {
		// traversing the array values till it
		// is less than equal to Query number
		while (arr[curr].val <= queries[i].x && curr < n) {
			// updating the bit array for the array index
			update(bit, arr[curr].idx + 1, 1, n);
			curr++;
		}

		// Answer for each Query will be number of
		// values less than equal to x upto r minus
		// number of values less than equal to x
		// upto l-1
		ans[queries[i].idx] = query(bit, queries[i].r + 1, n) -
		                      query(bit, queries[i].l, n);
		cnt += ans[queries[i].idx];
	}
}

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	T {
		int n = 4;
		cin >> n;
		ArrayElement arr[n];
		for (int i = 0; i < n; i++)
			cin >> arr[i].val, arr[i].idx = i;
		Query queries[n] = {};
		for (int i = 0; i < n - 1; i++)
			queries[i].l = i + 1, queries[i].r = n - 1, queries[i].x = arr[i].val;
		answerQueries(n, queries, n, arr);
		cout << cnt << endl;
		cnt = 0;
	}
}
