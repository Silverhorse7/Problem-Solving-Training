#include<bits/stdc++.h>

using namespace std;
const int N = 2e5 + 55;
int a[N];

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    sort(a, a + n);
    long long finale = 1e15;
    vector<vector<long long>> powers(N);
    powers[0] = vector<long long>(N, 1);
    for (int i = 2; i < N; i++) {
        long long cur = 1;
        while (cur <= static_cast<long long>(1e14)) {
            powers[i].push_back(cur);
            cur *= i;
        }
    }
    for (auto i: powers) {
        if (i.size() < n)continue;
        long long ans = 0;
        for (int j = 0; j < n; j++)
            ans += abs(i[j] - a[j]);
        finale = min(finale, ans);
    }
    cout << finale << endl;
}