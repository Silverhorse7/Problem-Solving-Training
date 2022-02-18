#include<bits/stdc++.h>
using namespace std;
int rn;
#define vi vector<int>
#define vvi vector<vector<int>>
bool cmp(vi&a,vi&b)
{
	if (a[0] / rn != b[0] / rn)return a[0] / rn < b[0]/rn;
	if ((a[0] / rn) & 1)return a[1] < b[1];
	return a[1] > b[1];
}
int main()
{
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);
	int n;
	cin>>n;
	rn = sqrt(2 * n);
	vvi a(n + 1,vi(3));
	for (int i = 1;i<=n;i++){cin>>a[i][0]>>a[i][1];a[i][2] = i;}
	sort(a.begin() + 1,a.end(),cmp);
	for (int i = 1;i<=n;i++)cout<<a[i][2]<<" ";
	return 0;
}
