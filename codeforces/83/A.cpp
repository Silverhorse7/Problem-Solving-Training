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
bool check_grid(int arr[8][8], int x, int y)// checking the 4 by 4 grid if it's valid                                               
                                         //Update , when there's a multi-zeros it will trigger , despite we dont want to 
{
    set<int>st;
    st.insert(arr[x][y]);
    int times = 0;
    for (int i = 0; i < 8; i++)
    {
        int x_axis = x - dx[i]; // to prevent arr[0][-1] and similar cases
        int y_axis = y - dy[i];
        if (x - dx[i] < 0 || x - dx[i] >= 8) {
            x_axis = x;
        }
        if (y - dy[i] < 0 || y - dy[i] >= 8) {
            y_axis = y;
        }
        if (arr[x_axis][y_axis] != 0) {
            st.insert(arr[x_axis][y_axis]);
            times++;
        }
    }
    if (st.size() == times || st.size() == times - 1) { // if it has a 1 occourance or no occourance at all
        return true;
    }
    return false;
}
bool check_column(int arr[8][8], int x)// check the column
{
    set<int>st;
    int times = 0;
    for (int i = 0; i < 8; i++)
    {
        if (arr[i][x] != 0) {
            times++;
            st.insert(arr[i][x]);
        }
    }
    if (st.size() == times)return true;
    return false;
}
bool check_row(int arr[8][8], int y)// check the row 
{
    set<int>st;
    int times = 0;
    for (int i = 0; i < 8; i++)
    {
        if (arr[i][y] != 0) {
            times++;
            st.insert(arr[i][y]);
        }
    }
    if (st.size() == times)return true;
    return false;
}
bool sudoko_valid(int arr[8][8])
{
    for (int i = 0; i < 8; i++)
    {
        if (!check_row(arr, i) || !check_column(arr, i)) {
            return false;
        }
    }
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if (!check_grid(arr, i, j))
            {
                return false;
            }
        }
    }
    return true;
}
bool validvalue(int arr[8][8], int x, int y)
{
    if (check_row(arr, y) and check_column(arr, x) and check_grid(arr, x, y))return true;
    return false;
}
void printarr(int arr[8][8])
{
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}
int cnt = 0;
vector<pair<int, int>>zero_locations;
 bool sudoko_solve(int arr[8][8],int i =0 ,int j = 0)
{
     if (i > 7 || j > 7)
     {
         return true;
     }
     bool flag = 0;
     int last = i;
     for (int i = 0; i < zero_locations.size(); i++)
     {
         for (int j = 1; j <= 8; j++)
         {
             arr[zero_locations[i].first][zero_locations[i].second] = j;
             if (validvalue(arr, zero_locations[i].first, zero_locations[i].second) and sudoko_solve(arr, zero_locations[i + 1].first, zero_locations[i + 1].second))
             {
                 flag = 1;
                 last = i;
                 return true;
             }
         }
     }
         if (flag == 0)
         {
             sudoko_solve(arr, zero_locations[last].first, zero_locations[last].second);
         }
}
 vector<int>answer;
 ll knapsack(vector<int>v, int weight, int items,int k,int trails)
 {
     if (trails >= v.size()) {
         if (weight == k)
         {
             return items;
         }
         else
         return 99;
     }
      if (weight == k) {
         answer.push_back(items);
         return items;
     }
      return(min(knapsack(v, weight + v[trails], items + 1, k, trails + 1),
      knapsack(v, weight, items, k, trails + 1)));
 }
int main()
{
    Speedo;
    int t;
    t = 1;
  //  cin >> t;
    while(t--){
        int n; cin >> n;
        vector<ll>v;
        v.push_back(-1000000000);
        for (int i = 0; i < n; i++)
        {
            int k; cin >> k;
            v.push_back(k);
        }
        ll subarrays = 1;
            ll ans = 0;
        for (int i = 1; i <= n; i++)
        {
            if (v[i] == v[i - 1])
            {
                subarrays += 1;
                ans += subarrays;
            }
            else {
                subarrays = 1;
                ans += subarrays;//single element
            }
        }
        cout << ans << endl;
    }
}