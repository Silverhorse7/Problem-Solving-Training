#include <bits/stdc++.h>

#define ll long long
using namespace std;
#define fast {ios_base::sync_with_stdio();}
#define T int T;cin>>T;while(T--)
#define ld long double

signed main() {
    fast;
    T {
        int n, k;
        cin >> n >> k;
        if (n % 2 == 0) {
            cout << (k % n == 0 ? n : k % n) << endl;
        } else {
            k--;
            int x= n/2;
            cout<<(k/x + k)%n + 1 <<endl;
        }
    }
}