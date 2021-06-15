#include <bits/stdc++.h>
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
#define test   cout<<" We Droped up Here Boss _________________ "<<endl  
#define allout(v) for(auto ele : v){cout<<ele<<" ";}cout<<endl
#define mk make_pair
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pcc pair<char,char>
#define vi vector<int>
#define vl vector<ll>
#define vvi vector<vector<int>>
#define vvl vector<vector<ll>>
#define txt freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout);
#define vb vector<bool>
#define getlost {cout<<"No"<<endl;return 0;}
#define getgud {cout<<"Yes"<<endl;return 0;}
#define tests(x) for(int i =  1 ; i<=x;i++)
#define inp(v,n) for(int i = 0 ;  i<n;i++)cin>>v[i];
#define outq(q) (    queue<int>qq = q;while (qq.size()) { cout << qq.front() << " "; qq.pop();})
#define outp(v) (for(auto ele: v){cout<<ele.first<<" "<<ele.second;}cout<<endl;)
ll mod = 1e9 + 7;
#define summ(v,sum) for(auto ele : v)sum+=ele;

int main(){
	int a,b,c;
	cin>>a>>b>>c;
	int arr[6]={1,2,3,4,5,6};
	cout<<(arr[6-a]+arr[6-b]+arr[6-c]);
}