#include <bits/stdc++.h>
using namespace std;
using ll = long long;
double m;
double L[4][2], X[4][2];

int main() {
    // cin.tie(0)->sync_with_stdio(0);
    cin >> L[0][1];
    for (ll i = 0; i < 3; i++) {
        for (ll j = 0; j < 2; j++) {
            cin >> X[i][j];
        }
    }
    for (ll i = 0; i < 3; i++) {
        if (X[i][0] != X[i][1])
            m = (X[i][0] + X[i][1]) / 2;
        else
            m = 0;
        // cout << m << '\n';
        L[i + 1][0] = min(m, L[i][1] - m);
        L[i + 1][1] = max(m, L[i][1] - m);
        // cout << L[i + 1][0] << ' ' << L[i + 1][1] << '\n';
        for (ll j = i + 1; j < 3; j++) {
            X[j][0] = abs(m - X[j][0]);
            X[j][1] = abs(m - X[j][1]);
        }
        // cout << X[i + 1][0] << ' ' << X[i + 1][1] << '\n';
    }
    cout << fixed;
    cout.precision(1);
    cout << L[3][1];
}
