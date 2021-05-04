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
string s = "";
void bin(unsigned n)
{
    if (n > 1)
        bin(n >> 1);
    s += to_string(n & 1);
}
 int main()
 {
     Speedo;
     int n;
     cin >> n;
     int k;
     cin >> k;
     bin(n);
     reverse(all(s));
     vector<int>v;
     priority_queue<int>pq;
     for (int i = 0; i < s.size(); i++)
     {
         if (s[i] == '1')
         {
             v.push_back(static_cast<ll>(pow(2, i)));
         }
     }
     for (int i = 0; i < v.size(); i++)
     {
         pq.push(v[i]);
     }
     while (pq.top() % 2 == 0 and pq.size()<k)
     {
         int ss = pq.top();
         pq.pop();
         pq.push(ss / 2);
         pq.push(ss / 2);
     }
     if (pq.size() == k) {
         cout << "YES" << endl;
         while (!pq.empty())
         {
             cout << pq.top() << " "; pq.pop();
         }
     }
     else {
         cout << "NO" << endl;
     }
 }
