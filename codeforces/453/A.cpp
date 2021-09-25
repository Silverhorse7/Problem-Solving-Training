#include<bits/stdc++.h>

#define ll long long
using namespace std;

int main() {
    int n, m;
    cin >> m >> n;
    double ans = 0;
    /*
     * for every x numbers (1<=x<=m) , it has expected value of
     * (x/m)^n , (x-1 / m)^n , (x-2 / m )^n  , and so on
     *
     */
    for (int i = 1; i <= m; i++) {
        ans += i * (pow(1.0*(i)/m,n) - pow(1.0*(i-1)/m,n));
    }
    cout<<fixed<<setprecision(9)<<ans;
}
