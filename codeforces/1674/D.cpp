#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];
  int prv = 1e9;
  for (int i = n - 1; i >= 1; i -= 2) {
    if (max(a[i], a[i - 1]) > prv) {
      cout << "NO";
      return;
    }
    prv = min(a[i], a[i - 1]);
  }
  if (n % 2 and a[0] > prv) {
    cout << "NO";
    return;
  }
  cout << "YES";
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  int t;
  cin >> t;
  while (t--) {
    solve();
    cout << '\n';
  }

  return 0;
}
