#include<bits/stdc++.h>

using namespace std;

#define ll long long


void TaskB() {
    ll n, m;
    cin >> n >> m;
    char a[n][m];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> a[i][j];
        }
    }
    ll flag = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (a[i][j] != '1') {}
            else {
                if (j > 0 && i < n - 1 && a[i][j - 1] == '1' && a[i + 1][j - 1] == '1' && a[i + 1][j] == '0') {
                    flag = 0;
                } else if (j > 0 && i > 0 && a[i][j - 1] == '1' && a[i - 1][j - 1] == '1' && a[i - 1][j] == '0') {
                    flag = 0;
                } else if (j <= 0 || i <= 0 || a[i - 1][j] != '1' || a[i - 1][j - 1] != '1' || a[i][j - 1] != '0') {
                    if (j < m - 1 && i > 0 && a[i - 1][j + 1] == '1' && a[i - 1][j] == '1' && a[i][j + 1] == '0') {
                        flag = 0;
                    }
                        //
                    else if (j < m - 1 && i < n - 1 && a[i][j + 1] == '1' && a[i + 1][j + 1] == '1' &&
                             a[i + 1][j] == '0') {
                        flag = 0;
                    } else if (j < m - 1 && i > 0 && a[i][j + 1] == '1' && a[i - 1][j + 1] == '1' &&
                               a[i - 1][j] == '0') {
                        flag = 0;
                    } else if (j > 0 && i < n - 1 && a[i + 1][j - 1] == '1' && a[i + 1][j] == '1' &&
                               a[i][j - 1] == '0') {
                        flag = 0;
                    } else if (j < m - 1 && i < n - 1 && a[i + 1][j + 1] == '1' && a[i + 1][j] == '1' &&
                               a[i][j + 1] == '0') {
                        flag = 0;
                    }
                } else {
                    flag = 0;
                }
            }
            if (!flag)
                break;
        }
        if (!flag)
            break;
    }
    if (!flag)
    {
        cout << "NO" << endl;
    }
    else
    {
        cout << "YES" << endl;
    }
}

int main() {
    int T;
    cin >> T;
    while (T--)TaskB();
}