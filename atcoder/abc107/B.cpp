#include "bits/stdc++.h"

using namespace std;

int main() {
    int h, w;
    cin >> h >> w;
    vector<string> f(h);
    for (int i = 0; i < h; i++)
        cin >> f[i];
    vector<bool> H(h, true), W(w, true);
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (f[i][j] == '#')H[i] = false;
        }
    }
    for (int j = 0; j < w; j++) {
        for (int i = 0; i < h; i++) {
            if (f[i][j] == '#')W[j] = false;
        }
    }
    for (int i = 0; i < h; i++) {
        if (H[i])continue;
        for (int j = 0; j < w; j++) {
            if (W[j])continue;
            cout << f[i][j];
        }
        cout << endl;
    }
}
 