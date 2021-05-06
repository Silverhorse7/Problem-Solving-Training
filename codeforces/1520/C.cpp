#include <bits/stdc++.h>
#include <vector>
using namespace std;
#define ll long long
#define Speedo ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define all(x) x.begin(),x.end()
#define pb push_back
#define endl       '\n'
#define return0 return 0
#define Endl endl
#define ull unsigned long long
#define elif else if 
#define test   cout<<" We Fucked up Here Boss_________________"<<endl
#define allout(first) for(auto ele : first) {cout<<ele<<" ";}cout<<endl;
void solve()
{
    int n;
    cin >> n;
    if (n == 2) {
        cout << -1 << endl; return;
    }
    int cnt = 0;
    for (int i = 1; i <= n*n; i++)
    {
        if (i % 2 == 0) {
            cnt++;
            cout << i << " ";
            if (cnt % n == 0) {
                cout << endl;
            }
        }
    }
    for (int i = 1; i <= n * n; i++)
    {
        if (i % 2 != 0) {
            cnt++;
            cout << i << " ";
            if (cnt % n == 0) {
                cout << endl;
            }
        }
    }
}
int main()
{
    Speedo;
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}