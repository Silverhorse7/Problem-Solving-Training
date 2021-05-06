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
    string s;
    cin >> s;
    int ind = -1;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '0') {
            ind = i; break;
        }
    }
    if (ind == -1) {
        s.pop_back();
        cout << s << endl;
    }
    else {
        s.erase(s.begin() + ind);
        cout << s << endl;
    }
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