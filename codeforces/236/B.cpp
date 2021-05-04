#include <bits/stdc++.h>
#include <vector>
#include <chrono>
#include <thread>
#include<iostream>
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
#define f(i,n) for(int i = 0 ; i <n;i++)
// u are standing in (1,1) how to move to all surrounding ? 
int dx[8] = { 0,1,1,1,0,-1,-1,-1 };
int dy[8] = { 1,0,1,-1,-1,-1,0,1 };
// talking about this problem.
// well , in fact any number can be representable by powers of two
// so think very well about the k numbers 
//why dont you turn the number onto bits ? , i guess it's a very good idea 
// 9-->1 0 0 1 --> 8,1  or 4,4,1 or ,2,2,2,2,1
// see ? , as long as the number of his bits %2 , just divide it !
// but make a bit of reservations , k cant be bigger than 9 (corner case alert)
// another example : 8 
// now time to code ! 
ll countDivisors(ll n)
{
    ll cnt = 0;
    for (int i = 1; i <= sqrt(n); i++) {
        if (n % i == 0) {
            // If divisors are equal,
            // count only one
            if (n / i == i)
                cnt++;
 
            else // Otherwise count both
                cnt = cnt + 2;
        }
    }
    return cnt;
}
int main()
{
    Speedo;
    //Idea : 
    // the idea is to get first 1 
    /*how to achieve that ?  if we found 2 numbers that gcd =1
    or if gcd != 1 , then compare current gcd with previous element before pair
    and next element after the pair
    if the gcd((next or previous) , gcd(a,b)) ==1 , then it's done and gg to you <3
    */
    //implementation : 
    ll koko = 1073741824;
    ll a, b, c;
    cin >> a >> b >> c;
    map<ll, ll>mp;//number and his divisors 
    ll answer = 0;
    for (int i = 1; i <= a; i++)
    {
        for (int j = 1; j <= b; j++)
        {
            for (int k = 1; k <= c; k++)
            {
                ll x = i * j * k;
                if (!mp[x])mp[x] = countDivisors(x);
                answer = answer % koko + mp[x] % koko;
            }
        }
    }
    cout << answer << endl; return 0;
}
