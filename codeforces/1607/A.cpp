#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define vi vector<int>
#define vl vector<ll>
#define q(v, n) for(ll i = 0 ;  i <n;i++)cin>>v[i];
#define out(v) {for(auto &a : v)cout<<a<<' ';cout<<endl;}
#define re resize
#define all(v) v.begin(),v.end()
#define no {printf("%s\n","NO");return 0;};
#define yes {printf("%s\n","YES");return 0;};
#define minus {printf("%s\n","-1");return 0;};
#define IM INT_MAX
#define Cin cin
#define inti ll i
#define intj ll j
#define OR or

int cnt(string s, string t) {
    int x = 0;
    int n = s.size();
    for (int i = 0; i < n; i++) {
        if (s[i] == t[0]) {
            if (i + 1 < n and s[i + 1] == t[1])x++;
        }
    }
    return x;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        string a, b;
        cin >> a >> b;
        map<char,int>mp;
        for(int i = 0;i<a.size();i++)mp[a[i]]=i+1;
        int lol = 0 ;
        for(int i =1 ; i <b.size();i++)lol+=abs(mp[b[i]]-mp[b[i-1]]);
        cout<<lol<<endl;
    }
}