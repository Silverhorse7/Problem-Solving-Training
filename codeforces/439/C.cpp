#include<bits/stdc++.h>

#define LL long long
#define MAX 100010
using namespace std;

pair<int, int> num[MAX];

bool cmp(pair<int, int> x, pair<int, int> y) {
    return x.second > y.second;
}

int main() {
    LL n, k, p;
    cin >> n >> k >> p;
    LL odd = 0, even = 0;
    for (int i = 0; i < n; i++) {
        cin >> num[i].first;
        num[i].second = num[i].first % 2;
        (num[i].first % 2 == 0 ? even : odd)++;
    }
    if (odd >= (k - p) && (odd - (k - p)) % 2 == 0 && (even + (odd - (k - p)) / 2) >= p) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
        return 0;
    }
    sort(num, num + n, cmp);
    if (p == 0) {
        int cnt = 0;
        for (int i = 1; i <= k; i++) {
            if (i != k) {
                cout << "1 " << num[cnt++].first << endl;
            } else {
                cout << n - cnt << endl;
                for (i = cnt; i < n; i++)
                    cout << " " << num[i].first;
            }
        }
    } else {
        for (int i = 1, cnt = 0; i <= k; i++) {
            if (i <= k - p) {
                cout << "1 " << num[cnt++].first << endl;
            } else if (i > k - p && i < k) {
                (num[cnt].second ? cout << "2 " << num[cnt++].first << " " : cout << "1 ") << num[cnt++].first << endl;
            } else {
                cout << n - cnt;
                for (int j = cnt; j < n; j++)
                    cout << " " << num[j].first;
                cout << endl;
            }
        }
    }
}