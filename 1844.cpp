#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll N, M;
ll maxseg[600005];
ll minseg[600005];
map<ll, ll> pos;

void upd(ll now, ll s, ll e, ll loc, ll val) {
    if (s == e) {
        minseg[now] = val;
        maxseg[now] = val;
        return;
    }
    ll lseg = now * 2, mid = (s + e) / 2;
    if (loc <= mid)
        upd(lseg, s, mid, loc, val);
    else
        upd(lseg + 1, mid + 1, e, loc, val);
    minseg[now] = min(minseg[lseg], minseg[lseg + 1]);
    maxseg[now] = max(maxseg[lseg], maxseg[lseg + 1]);
    return;
}

ll maxquery(ll now, ll s, ll e, ll qs, ll qe) {
    if (e < qs || s > qe) return -2e9;
    if (qs <= s && e <= qe) return maxseg[now];
    ll lseg = now * 2, mid = (s + e) / 2;
    return max(maxquery(lseg, s, mid, qs, qe), maxquery(lseg + 1, mid + 1, e, qs, qe));
}

ll minquery(ll now, ll s, ll e, ll qs, ll qe) {
    if (e < qs || s > qe) return 2e9;
    if (qs <= s && e <= qe) return minseg[now];
    ll lseg = now * 2, mid = (s + e) / 2;
    return min(minquery(lseg, s, mid, qs, qe), minquery(lseg + 1, mid + 1, e, qs, qe));
}

int main() {
    cin.tie(0)->sync_with_stdio();
    cin >> N >> M;
    for (ll i = 1; i <= N; i++) {
        ll tmp;
        cin >> tmp;
        upd(1, 1, N, tmp, i);
        pos[i] = tmp;
    }
    while (M--) {
        ll typ, x, y;
        cin >> typ >> x >> y;
        if (typ == 1) {
            ll xnum = pos[x];
            ll ynum = pos[y];
            upd(1, 1, N, xnum, y);
            upd(1, 1, N, ynum, x);
            swap(pos[x], pos[y]);
        } else {
            ll mx = maxquery(1, 1, N, x, y);
            ll mn = minquery(1, 1, N, x, y);
            if (mx - mn <= abs(x - y))
                cout << "YES";
            else
                cout << "NO";
            cout << '\n';
        }
    }
    return 0;
}