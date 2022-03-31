

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
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        long long ans = 0;
        for (int i = 0; i < n; i++) {
            ll c1, c2;
            c1 = 0;
            c2 = 0;
            for (int j = i; j < n; j++) {
                (s[j] == '-' ? c2 : c1)++;
                if (c1 != c2) {
                    if (c2 > c1 && (c2 - c1) % 3 == 0) ans++;
                } else ans++;
            }
        }
        cout << ans << endl;
    }
}