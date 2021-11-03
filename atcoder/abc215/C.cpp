#include<bits/stdc++.h>

using namespace std;
#define ll long long
    int arr[400000];
    int ans[400000];
int main() {
	string s;
	int k;
	cin>>s>>k;
	vector<string>v;
	sort(s.begin(),s.end());
	do{
		v.push_back(s);
	}while(next_permutation(s.begin(),s.end()));
	cout<<v[k-1];
}