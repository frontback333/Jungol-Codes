#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll N, ans;
ll x[100005], a[100005], b[100005];

int calc(ll val) {
    ll mx = val, mn = 0;
    for (ll i = 0; i < N; i++) {
        ll c;
        if (a[i] == b[i]) {
            if (x[i] / a[i] < val) return 0;
        } else if (a[i] > b[i]) {
            if ((x[i] - val * b[i]) < 0) return 0;
            c = (x[i] - val * b[i]) / (a[i] - b[i]);
            if (c < mx) mx = c;
        } else {
            if ((x[i] - val * a[i]) < 0) return 0;
            c = (x[i] - val * a[i]) / (b[i] - a[i]);
            if (c > mn) mn = c;
        }
    }
    return mn <= mx;
}

void mxpars(ll s, ll e) {
    if (e < s) {
        ans = e;
        return;
    }
    ll m = (s + e) / 2;
    // cout << m << ' ' << calc(m) << '\n';
    if (calc(m))
        mxpars(m + 1, e);
    else
        mxpars(s, m - 1);
}

int main() {
    cin.tie(0)->sync_with_stdio();
    cin >> N;
    for (ll i = 0; i < N; i++) cin >> x[i];
    for (ll i = 0; i < N; i++) cin >> a[i];
    for (ll i = 0; i < N; i++) cin >> b[i];
    mxpars(0, 1000000000);
    cout << ans;
}