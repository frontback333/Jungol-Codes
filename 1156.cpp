#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll m, k, mxpg, pg[100005], presum[100005], ans[100005];

void minpar(ll low, ll high, ll val) {
    if (low > high) {
        ll lastcut = m, cnt = 1;
        // cout << low << '\n';
        for (ll i = m - 1; i >= 0; i--) {
            if (presum[lastcut] - presum[i] > low) {
                lastcut = i + 1;
                cnt++;
                if (cnt < val + 1) ans[i + 1]++;
            }
            if (i < k - cnt) {
                ans[i + 1]++;
                cnt++;
            }
        }
        return;
    }
    ll mid = (low + high) / 2;
    ll lastcut = m, cnt = 1;
    for (ll i = m - 1; i >= 0; i--) {
        if (cnt > val) break;
        if (presum[lastcut] - presum[i] > mid) {
            lastcut = i + 1;
            cnt++;
        }
    }
    if (cnt > val)
        minpar(mid + 1, high, val);
    else
        minpar(low, mid - 1, val);
}

int main() {
    // cin.tie(0)->sync_with_stdio();
    cin >> m >> k;
    for (ll i = 1; i <= m; i++) {
        cin >> pg[i];
        presum[i] = presum[i - 1] + pg[i];
        if (pg[i] > mxpg) mxpg = pg[i];
    }
    minpar(mxpg, presum[m], k);
    for (ll i = 1; i <= m; i++) {
        cout << pg[i] << ' ';
        if (ans[i] && i != m) cout << "/ ";
    }
}
