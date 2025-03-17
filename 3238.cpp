#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll N, M, f, mx;
ll tre[400005];

void upd(ll now, ll s, ll e, ll loc, ll val) {
    if (s == e) {
        tre[now] = val;
        return;
    }
    ll lseg = now * 2, rseg = lseg + 1, mid = (s + e) / 2;
    if (loc <= mid)
        upd(lseg, s, mid, loc, val);
    else
        upd(rseg, mid + 1, e, loc, val);
    tre[now] = max(tre[lseg], tre[rseg]);
    return;
}
ll query(ll now, ll s, ll e, ll qs, ll qe) {
    if (e < qs || s > qe) return -2e9;
    if (qs <= s && e <= qe) return tre[now];
    ll lseg = now * 2, rseg = lseg + 1, mid = (s + e) / 2;
    return max(query(lseg, s, mid, qs, qe), query(rseg, mid + 1, e, qs, qe));
}

int main() {
    cin.tie(0)->sync_with_stdio();
    cin >> N >> M;
    for (ll i = 1; i <= N; i++) {
        upd(1, 1, N, i, -2e9);
    }
    while (M--) {
        cin >> f;
        if (f == 1) {
            ll k, val;
            cin >> k >> val;
            upd(1, 1, N, k, val);
        } else if (f == 2) {
            ll s, e;
            cin >> s >> e;
            mx = query(1, 1, N, s, e);
            if (mx > -2e9) cout << mx << '\n';
        } else {
            ll k;
            cin >> k;
            upd(1, 1, N, k, -2e9);
        }
    }
}