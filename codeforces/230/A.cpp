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
    int s, n;
    cin >> s >> n;
    vector<pair<int, int>>pr;
    while (n--) {
        int x, y;
        cin >> x >> y;
        pr.push_back({ x,y });
    }
    sort(all(pr));
    for (int i = 0; i < pr.size(); i++)
    {
        if (s > pr[i].first)s += pr[i].second;
        else {
            cout << "NO" << endl; return;
        }
    }
    cout << "YES" << endl; return;
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