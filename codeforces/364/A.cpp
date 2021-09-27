#include<bits/stdc++.h>

#define ll long long
#define all(x) x.begin(),x.end()
#define yes {cout<<"YES"<<endl;return;}
#define no {cout<<"NO"<<endl;return;}
using namespace std;
map<ll, ll> sums;

int main() {
    ll a;
    string s;
    cin >> a >> s;
    for (int i = 0; i < s.size(); i++) {
        ll sum = 0;
        for (int j = i; j < s.size(); j++) {
            sum += s[j] - '0';
            sums[sum]++;
        }
    }
    if (!a) {
        cout << sums[0] * (s.size() * (s.size() + 1)) - sums[0] * sums[0];
        return 0;
    }
    ll sol = 0;
    for (auto i: sums) {
        if (i.first && a % i.first == 0)
            sol += i.second * sums[a / i.first];
    }
    cout << sol;
}