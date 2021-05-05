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
    int d;
    cin >> d;
    string s;
    cin >> s;
    for (int j = 'A'; j <= 'Z'; j++)
    {
        int ind1 = -1, ind2 = -1;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == j) {
                ind1 = i; break;
            }
        }
        for (int i = s.size(); i >= 0; i--)
        {
            if (s[i] == j) {
                ind2 = i;
                break;
            }
        }
        if (ind1 != -1) {
            for (int i = ind1; i <= ind2; i++)
            {
                if (s[i] != j) { cout << "NO" << endl; return; }
            }
        }
    }
    cout << "YES" << endl;
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