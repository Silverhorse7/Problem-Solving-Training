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
#define test   cout<<" We Droped up Here Boss_________________"<<endl
#define allout(v) for(auto ele : v){cout<<ele<<" ";}cout<<endl
#define pii pair<short int,short int>
 
#define inputtt freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout);
bool arr[2009][2009];
short  h,w;
vector<pair<short,short>>fires;
short dx[4]={0,-1,0,1};
short dy[4]={-1,0,1,0};
short valid(short x,short y){
    return ( x>=0 and y>=0 and x<h and y<w);
}
pair<short,short>   pr;
void fire(short x , short y){
    if(arr[x][y]==1 or !valid(x,y))return;
   pr={x+1,y+1};
    arr[x][y]=1;
    for(short i = 0 ; i <4;i++){
        int a=x+dx[i];
        int b= y+dy[i];
        if(valid(a,b) and arr[a][b]==0){
            fires.pb({a,b});
        }
    }
}
int main(){
    Speedo;
    inputtt;
    cin>>h>>w;
    short n;
    cin>>n;
    short x,y;
    while(n--){
        
        cin>>x>>y;
        x--;
        y--;
        fires.pb({x,y});
    }
    for(int i = 0 ; i <fires.size();i++){
        if(arr[fires[i].first][fires[i].second]==0)
        fire(fires[i].first,fires[i].second);
    }
    cout<<pr.first<<" "<<pr.second<<endl;
}