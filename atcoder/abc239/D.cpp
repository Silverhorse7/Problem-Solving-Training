#include<bits/stdc++.h>

using namespace std;

int isprime(long long number) {

    if (number == 0 || number == 1 || (number % 2 == 0 && number > 2)) {
        return 0;
    } else {
        for (long long i = 3; i <= (long long) sqrt(number) + 1; i++) {
            if (number % i == 0) {
                return 0;
            }
        }
        return 1;
    }
}

signed main() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    for (int i = a; i <= b; i++) {
        bool flag = 0;
        for (int j = c; j <= d; j++) {
            if (isprime(i + j)) {
                flag = 1;
            }
        }
        if (!flag) {
            cout << "Takahashi";
            exit(0);
        }
    }
    cout << "Aoki" << endl;
}