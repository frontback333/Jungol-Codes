#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll N, M, K, Q;

ll tre[4000005];

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
    tre[now] = tre[lseg] + tre[rseg];
    return;
}
ll query(ll now, ll s, ll e, ll qs, ll qe) {
    if (e < qs || s > qe) return 0;
    if (qs <= s && e <= qe) return tre[now];
    ll lseg = now * 2, rseg = lseg + 1, mid = (s + e) / 2;
    return query(lseg, s, mid, qs, qe) + query(rseg, mid + 1, e, qs, qe);
}

int main() {
    cin.tie(0)->sync_with_stdio();
    cin >> N >> M >> K;
    for (ll i = 1; i <= N; i++) {
        ll tmp;
        cin >> tmp;
        upd(1, 1, N, i, tmp);
    }
    Q = M + K;
    while (Q--) {
        ll f, a, b;
        cin >> f >> a >> b;
        if (f == 1) {
            upd(1, 1, N, a, b);
        } else {
            cout << query(1, 1, N, a, b) << '\n';
        }
    }
}