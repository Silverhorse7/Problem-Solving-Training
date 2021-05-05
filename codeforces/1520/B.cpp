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

}
int main()
{
    Speedo;
    int t;
    cin >> t;
    vector<vector<ll>>v(10);
    for (int i = 1; i <= 9; i++) {
        string s = "";
        s += (i + '0');
        v[i - 1].push_back(stoll(s));
        for (int j = 0; j < 9; j++)
        {
            s += (i + '0');
            v[i - 1].push_back(stoll(s));
        }
    }
    while (t--)
    {
        ll n;
        cin >> n;
        int cnt = 0;
        for (int j = 0; j <= 8; j++)
        {
            for (int i = 0; i < v[j].size(); i++)
            {
                if (v[j][i] <= n)
                {
                    cnt++;
                }
            }
        }
        cout << cnt << endl;
    }
}