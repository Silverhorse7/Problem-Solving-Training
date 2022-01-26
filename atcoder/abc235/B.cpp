#include<bits/stdc++.h>

using namespace std;
const int N = 1e5 + 5;
int h[N];

signed main() {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &h[i]);
    int mx = 0;
    for (int i = 1; i <= n; i++) {
        if (h[i] > mx)
            mx = h[i];
        else
            break;
    }
    printf("%d", mx);
}