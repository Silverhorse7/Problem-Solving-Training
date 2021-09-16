#include "bits/stdc++.h"

using namespace std;

int main() {
    long long  n, k;
    cin >> n >> k;
    vector<long long > v(n);
    for (auto &a: v)
        cin >> a;
    sort(v.begin(),  v.end());
    long long  start = 0;
    long long  end = 1e11;
    long long  answer = 0;
    while (start <= end) {
        long long  mid = (start + end) / 2;
        long long  sum = 0;
        for (long long  i = n/2; i < n; i++) {
            if (v[i] < mid) {
                sum += mid - v[i];
            }
        }
        if (sum <= k) {
            answer = mid;
            start = mid + 1;
        } else
            end = mid - 1;
    }
    cout << answer;
}