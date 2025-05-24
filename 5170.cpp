#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll X, Y, Z;

ll BinS(ll s, ll e) {
    if (e < s) return s;
    int m = s + e >> 1;
    if ((Y + m) * 100 / (X + m) > Z)
        return BinS(s, m - 1);
    else
        return BinS(m + 1, e);
}

int main() {
    cin.tie(0)->sync_with_stdio();
    cin >> X >> Y;
    Z = (Y * 100) / X;
    ll ans = BinS(1, 1e9);
    (ans > 1e9) ? cout << -1 : cout << ans;
}