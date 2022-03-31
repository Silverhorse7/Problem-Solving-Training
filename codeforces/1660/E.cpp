

#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
template<class T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag,
        tree_order_statistics_node_update>;
using namespace std;
//----------------------Code Starts Here-----------------------------//
const int N = 2e5 + 1;
#define ll long long

pair<ll, ll> maxProductSubArray(vector<ll> &nums) {
    ll maxLeft = nums[0];
    ll maxRight = nums[0];

    ll prod = 1;

    bool zeroPresent = false;
    ll right = 0;
    for (ll i = 0; i < nums.size(); i++) {
        prod *= nums[i];
        if (nums[i] == 0) {
            zeroPresent = true;
            prod = 1;
            continue;
        }
        ll prev = maxLeft;
        maxLeft = max(maxLeft, prod);
        if (prev != maxLeft) {
            right = i;
        }
    }

    prod = 1;
    ll left = 0;
    for (ll j = nums.size() - 1; j >= 0; j--) {
        prod *= nums[j];
        if (nums[j] == 0) {
            zeroPresent = true;
            prod = 1;
            continue;
        }
        ll prev = maxRight;
        maxRight = max(maxRight, prod);
        if (prev != maxRight) {
            left = j;
        }
    }
    ll p = max(maxLeft, maxRight);
    if (p <= 0) {
        return {(ll) nums.size(), 0};
    }
    if (maxLeft > maxRight) {
        ll mul = 1;
        for (ll i = right; i >= 0; i--) {
            mul *= nums[i];
            if (mul == maxLeft) {
                //cout << maxLeft << " L" << endl;
                return {i, right + 1};
            }
        }
    } else {
        ll mul = 1;
        for (ll i = left; i < nums.size(); i++) {
            mul *= nums[i];
            if (mul == maxRight) {
                return {left, i + 1};
            }
        }
    }
    return {left + 1, right + 1};
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> a;
        int O = 0;
        string s;
        a.resize(n, vector<int>(n));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                char x;
                cin>>x;
                a[i][j] = x - '0';
                O += a[i][j];
            }
        }
        int Brack = 0, Bucket = 0;
        for (int i = 0; i < n; i++) {
            Bucket = 0;
            for (int j = 0; j < n; j++) {
                Bucket += a[j][(i + j) % n];
            }
            Brack = max(Bucket, Brack);
        }
        cout << n - 2 * Brack + O << endl;
    }
}