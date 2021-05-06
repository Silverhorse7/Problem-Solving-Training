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
    vector<int>v(n - 1);
    for (auto& cc : v)cin >> cc;
    int a, b;
    cin >> a >> b;
    int koko = 0;
    for (int i = a - 1; i < b-1; i++)
    {
        koko += v[i];
    }
    cout << koko << endl;
}
int main()
{
    Speedo;
    int t = 1;
   // cin >> t;
    while (t--)
    {
        solve();
    }
}