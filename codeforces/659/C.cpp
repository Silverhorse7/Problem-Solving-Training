//#pragma GCC optimize("Ofast")
//#pragma GCC optimize ("unroll-loops")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include "bits/stdc++.h"
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
template<class T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag,
        tree_order_statistics_node_update>;
using namespace std;
#define ll long long
#define Silver_is_better_than_Gold ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define all(x) x.begin(),x.end()
#define allr(x) x.rbegin(),x.rend()
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
#define txt freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout);
#define ld long D
#define vb vector<bool>
#define no {cout<<"NO"<<endl;return ;}
#define yes {cout<<"YES"<<endl;return ;}
#define tests(x) for(int i =  1 ; i<=x;i++)
#define in(v, n) for(int i = 0 ;  i<n;i++)cin>>i;
#define outp(v) for(auto ele : v){        cout << ele.first << " " << ele.second << " ";}cout<<endl
const ll mod = 1e9 + 7;
#define inti int i
#define sz(x) ((int) (x).size())
#define dups(divs)     divs.erase(unique(divs.begin(), divs.end()), divs.end());
#define fo(i, v, b) for(int i = v ; i<=b;i++)
#define outq(q)     queue<int>qq = q;while (qq.size()) { cout << qq.front() << " "; qq.pop();};
#define sttk(x) static_cast<ll>(x)
#define re register
#define intj int j
#define debug cout<<"Output is  :  ";
#define debug2 cout<<"End of the output______________________"<<endl;
#define sum(v) accumulate(v.begin(),v.end(),0ll)
#define range(i, n) for(int i = 0 ; i <n;i++)
#define point pair<int,int>
#define T int XXX;cin>>XXX;while(XXX--)
#define F first
#define S second
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

template<class A>
istream &operator>>(istream &cin, vector<A> &p) {
    for (int i = 0; i < sz(p) - 1; i++)
        cin >> p[i];
    return cin >> p.back();
}

template<class A>
ostream &operator<<(ostream &cout, vector<A> const &v) {
    allout(v);
    return cout;
}

ll fastpow(ll base, ll power, ll M) {
    if (power == 1) return base;
    ll val = fastpow(base, power / 2, M);
    return (power % 2 == 0) ? (val * val) % M : (((val * val) % M) * base) % M;
}

//----------------------Code Starts Here-----------------------------//
class BigInt {
    string digits;
public:

    //Constructors:
    BigInt(unsigned long long n = 0);

    BigInt(string &);

    BigInt(const char *);

    BigInt(BigInt &);

    //Helper Functions:
    friend void divide_by_2(BigInt &a);

    friend bool Null(const BigInt &);

    friend int Lenght(const BigInt &);

    int operator[](const int) const;

    /* * * * Operator Overloading * * * */

    //Direct assignment
    BigInt &operator=(const BigInt &);

    //Post/Pre - Incrementation
    BigInt &operator++();

    BigInt operator++(int temp);

    BigInt &operator--();

    BigInt operator--(int temp);

    //Addition and Subtraction
    friend BigInt &operator+=(BigInt &, const BigInt &);

    friend BigInt operator+(const BigInt &, const BigInt &);

    friend BigInt operator-(const BigInt &, const BigInt &);

    friend BigInt &operator-=(BigInt &, const BigInt &);

    //Comparison operators
    friend bool operator==(const BigInt &, const BigInt &);

    friend bool operator!=(const BigInt &, const BigInt &);

    friend bool operator>(const BigInt &, const BigInt &);

    friend bool operator>=(const BigInt &, const BigInt &);

    friend bool operator<(const BigInt &, const BigInt &);

    friend bool operator<=(const BigInt &, const BigInt &);

    //Multiplication and Division
    friend BigInt &operator*=(BigInt &, const BigInt &);

    friend BigInt operator*(const BigInt &, const BigInt &);

    friend BigInt &operator/=(BigInt &, const BigInt &);

    friend BigInt operator/(const BigInt &, const BigInt &);

    //Modulo
    friend BigInt operator%(const BigInt &, const BigInt &);

    friend BigInt &operator%=(BigInt &, const BigInt &);

    //Power Function
    friend BigInt &operator^=(BigInt &, const BigInt &);

    friend BigInt operator^(BigInt &, const BigInt &);

    //Square Root Function
    friend BigInt sqrt(BigInt &a);

    //Read and Write
    friend ostream &operator<<(ostream &, const BigInt &);

    friend istream &operator>>(istream &, BigInt &);

    //Others
    friend BigInt NthCatalan(int n);

    friend BigInt NthFibonacci(int n);

    friend BigInt Factorial(int n);
};

BigInt::BigInt(string &s) {
    digits = "";
    int n = s.size();
    for (int i = n - 1; i >= 0; i--) {
        if (!isdigit(s[i]))
            throw ("ERROR");
        digits.push_back(s[i] - '0');
    }
}

BigInt::BigInt(unsigned long long nr) {
    do {
        digits.push_back(nr % 10);
        nr /= 10;
    } while (nr);
}

BigInt::BigInt(const char *s) {
    digits = "";
    for (int i = strlen(s) - 1; i >= 0; i--) {
        if (!isdigit(s[i]))
            throw ("ERROR");
        digits.push_back(s[i] - '0');
    }
}

BigInt::BigInt(BigInt &a) {
    digits = a.digits;
}

bool Null(const BigInt &a) {
    if (a.digits.size() == 1 && a.digits[0] == 0)
        return true;
    return false;
}

int Lenght(const BigInt &a) {
    return a.digits.size();
}

int BigInt::operator[](const int index) const {
    if (digits.size() <= index || index < 0)
        throw ("ERROR");
    return digits[index];
}

bool operator==(const BigInt &a, const BigInt &b) {
    return a.digits == b.digits;
}

bool operator!=(const BigInt &a, const BigInt &b) {
    return !(a == b);
}

bool operator<(const BigInt &a, const BigInt &b) {
    int n = Lenght(a), m = Lenght(b);
    if (n != m)
        return n < m;
    while (n--)
        if (a.digits[n] != b.digits[n])
            return a.digits[n] < b.digits[n];
    return false;
}

bool operator>(const BigInt &a, const BigInt &b) {
    return b < a;
}

bool operator>=(const BigInt &a, const BigInt &b) {
    return !(a < b);
}

bool operator<=(const BigInt &a, const BigInt &b) {
    return !(a > b);
}

BigInt &BigInt::operator=(const BigInt &a) {
    digits = a.digits;
    return *this;
}

BigInt &BigInt::operator++() {
    int i, n = digits.size();
    for (i = 0; i < n && digits[i] == 9; i++)
        digits[i] = 0;
    if (i == n)
        digits.push_back(1);
    else
        digits[i]++;
    return *this;
}

BigInt BigInt::operator++(int temp) {
    BigInt aux;
    aux = *this;
    ++(*this);
    return aux;
}

BigInt &BigInt::operator--() {
    if (digits[0] == 0 && digits.size() == 1)
        throw ("UNDERFLOW");
    int i, n = digits.size();
    for (i = 0; digits[i] == 0 && i < n; i++)
        digits[i] = 9;
    digits[i]--;
    if (n > 1 && digits[n - 1] == 0)
        digits.pop_back();
    return *this;
}

BigInt BigInt::operator--(int temp) {
    BigInt aux;
    aux = *this;
    --(*this);
    return aux;
}

BigInt &operator+=(BigInt &a, const BigInt &b) {
    int t = 0, s, i;
    int n = Lenght(a), m = Lenght(b);
    if (m > n)
        a.digits.append(m - n, 0);
    n = Lenght(a);
    for (i = 0; i < n; i++) {
        if (i < m)
            s = (a.digits[i] + b.digits[i]) + t;
        else
            s = a.digits[i] + t;
        t = s / 10;
        a.digits[i] = (s % 10);
    }
    if (t)
        a.digits.push_back(t);
    return a;
}

BigInt operator+(const BigInt &a, const BigInt &b) {
    BigInt temp;
    temp = a;
    temp += b;
    return temp;
}

BigInt &operator-=(BigInt &a, const BigInt &b) {
    if (a < b)
        throw ("UNDERFLOW");
    int n = Lenght(a), m = Lenght(b);
    int i, t = 0, s;
    for (i = 0; i < n; i++) {
        if (i < m)
            s = a.digits[i] - b.digits[i] + t;
        else
            s = a.digits[i] + t;
        if (s < 0)
            s += 10,
                    t = -1;
        else
            t = 0;
        a.digits[i] = s;
    }
    while (n > 1 && a.digits[n - 1] == 0)
        a.digits.pop_back(),
                n--;
    return a;
}

BigInt operator-(const BigInt &a, const BigInt &b) {
    BigInt temp;
    temp = a;
    temp -= b;
    return temp;
}

BigInt &operator*=(BigInt &a, const BigInt &b) {
    if (Null(a) || Null(b)) {
        a = BigInt();
        return a;
    }
    int n = a.digits.size(), m = b.digits.size();
    vector<int> v(n + m, 0);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            v[i + j] += (a.digits[i]) * (b.digits[j]);
        }
    n += m;
    a.digits.resize(v.size());
    for (int s, i = 0, t = 0; i < n; i++) {
        s = t + v[i];
        v[i] = s % 10;
        t = s / 10;
        a.digits[i] = v[i];
    }
    for (int i = n - 1; i >= 1 && !v[i]; i--)
        a.digits.pop_back();
    return a;
}

BigInt operator*(const BigInt &a, const BigInt &b) {
    BigInt temp;
    temp = a;
    temp *= b;
    return temp;
}

BigInt &operator/=(BigInt &a, const BigInt &b) {
    if (Null(b))
        throw ("Arithmetic Error: Division By 0");
    if (a < b) {
        a = BigInt();
        return a;
    }
    if (a == b) {
        a = BigInt(1);
        return a;
    }
    int i, lgcat = 0, cc;
    int n = Lenght(a), m = Lenght(b);
    vector<int> cat(n, 0);
    BigInt t;
    for (i = n - 1; t * 10 + a.digits[i] < b; i--) {
        t *= 10;
        t += a.digits[i];
    }
    for (; i >= 0; i--) {
        t = t * 10 + a.digits[i];
        for (cc = 9; cc * b > t; cc--);
        t -= cc * b;
        cat[lgcat++] = cc;
    }
    a.digits.resize(cat.size());
    for (i = 0; i < lgcat; i++)
        a.digits[i] = cat[lgcat - i - 1];
    a.digits.resize(lgcat);
    return a;
}

BigInt operator/(const BigInt &a, const BigInt &b) {
    BigInt temp;
    temp = a;
    temp /= b;
    return temp;
}

BigInt &operator%=(BigInt &a, const BigInt &b) {
    if (Null(b))
        throw ("Arithmetic Error: Division By 0");
    if (a < b) {
        a = BigInt();
        return a;
    }
    if (a == b) {
        a = BigInt(1);
        return a;
    }
    int i, lgcat = 0, cc;
    int n = Lenght(a), m = Lenght(b);
    vector<int> cat(n, 0);
    BigInt t;
    for (i = n - 1; t * 10 + a.digits[i] < b; i--) {
        t *= 10;
        t += a.digits[i];
    }
    for (; i >= 0; i--) {
        t = t * 10 + a.digits[i];
        for (cc = 9; cc * b > t; cc--);
        t -= cc * b;
        cat[lgcat++] = cc;
    }
    a = t;
    return a;
}

BigInt operator%(const BigInt &a, BigInt &b) {
    BigInt temp;
    temp = a;
    temp %= b;
    return temp;
}

BigInt &operator^=(BigInt &a, const BigInt &b) {
    BigInt Exponent, Base(a);
    Exponent = b;
    a = 1;
    while (!Null(Exponent)) {
        if (Exponent[0] & 1)
            a *= Base;
        Base *= Base;
        divide_by_2(Exponent);
    }
    return a;
}

BigInt operator^(BigInt &a, BigInt &b) {
    BigInt temp(a);
    temp ^= b;
    return temp;
}

void divide_by_2(BigInt &a) {
    int add = 0;
    for (int i = a.digits.size() - 1; i >= 0; i--) {
        int digit = (a.digits[i] >> 1) + add;
        add = ((a.digits[i] & 1) * 5);
        a.digits[i] = digit;
    }
    while (a.digits.size() > 1 && !a.digits.back())
        a.digits.pop_back();
}

BigInt sqrt(BigInt &a) {
    BigInt left(1), right(a), v(1), mid, prod;
    divide_by_2(right);
    while (left <= right) {
        mid += left;
        mid += right;
        divide_by_2(mid);
        prod = (mid * mid);
        if (prod <= a) {
            v = mid;
            ++mid;
            left = mid;
        } else {
            --mid;
            right = mid;
        }
        mid = BigInt();
    }
    return v;
}

BigInt NthCatalan(int n) {
    BigInt a(1), b;
    for (int i = 2; i <= n; i++)
        a *= i;
    b = a;
    for (int i = n + 1; i <= 2 * n; i++)
        b *= i;
    a *= a;
    a *= (n + 1);
    b /= a;
    return b;
}

BigInt NthFibonacci(int n) {
    BigInt a(1), b(1), c;
    if (!n)
        return c;
    n--;
    while (n--) {
        c = a + b;
        b = a;
        a = c;
    }
    return b;
}

BigInt Factorial(int n) {
    BigInt f(1);
    for (int i = 2; i <= n; i++)
        f *= i;
    return f;
}

istream &operator>>(istream &in, BigInt &a) {
    string s;
    in >> s;
    int n = s.size();
    for (int i = n - 1; i >= 0; i--) {
        if (!isdigit(s[i]))
            throw ("INVALID NUMBER");
        a.digits[n - i - 1] = s[i];
    }
    return in;
}

ostream &operator<<(ostream &out, const BigInt &a) {
    for (int i = a.digits.size() - 1; i >= 0; i--)
        cout << (short) a.digits[i];
    return cout;
}

signed main() {
    int n, budget;
    cin >> n >> budget;
    set<int> st;
    unordered_map<int, int> mp;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        mp[x] = 1;
    }
    for (int i = 1; i <= 3e6; i++)
        if(mp.find(i)==mp.end())
        st.insert(i);
    vector<int> purchease;
    for (auto i: st) {
        if (budget >= i)
            budget -= i, purchease.push_back(i);
    }
    cout << purchease.size() << endl;
    allout(purchease);
}