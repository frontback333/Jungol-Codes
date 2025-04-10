#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll N, Q, a, b, tmp;
ll tre[200005];

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
}

ll query(ll now, ll s, ll e, ll qs, ll qe) {
    if (e < qs || qe < s) return -1e10;
    if (qs <= s && e <= qe) return tre[now];
    ll lseg = now * 2, rseg = lseg + 1, mid = (s + e) / 2;
    return max(query(lseg, s, mid, qs, qe), query(rseg, mid + 1, e, qs, qe));
}

int main() {
    cin.tie(0)->sync_with_stdio();
    cin >> N >> Q;
    for (int i = 1; i <= N; i++) {
        cin >> tmp;
        upd(1, 1, N, i, tmp);
    }
    while (Q--) {
        cin >> a >> b;
        cout << query(1, 1, N, a, b) << '\n';
    }
}