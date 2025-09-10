#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ln '\n';
struct dta {
    ll x, typ, s, e;
    bool operator<(const dta& b) const {
        if (x == b.x) return typ > b.typ;
        return x < b.x;
    }
};
ll SY, SX, EY, EX, N, Q, ans;
ll lazy[4000005], segT[4000005];
vector<dta> updq;

void prop(ll c, ll s, ll e) {
    if (!lazy[c]) return;
    if (s < e) {
        lazy[c * 2] += lazy[c];
        lazy[(c * 2) + 1] += lazy[c];
    }
    segT[c] += lazy[c];
    lazy[c] = 0;
}

void ad(ll c, ll s, ll e, ll qs, ll qe, ll val) {
    prop(c, s, e);
    if (qs > e || qe < s) return;
    // cout << c << ' ' << segT[c] << ln;
    if (qs <= s && e <= qe) {
        lazy[c] += val;
        return prop(c, s, e);
    }
    ll mid = s + e >> 1, nxt = c * 2;
    ad(nxt, s, mid, qs, qe, val);
    ad(nxt + 1, mid + 1, e, qs, qe, val);
    segT[c] = max(segT[nxt], segT[nxt + 1]);
    return;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> SX >> SY >> EX >> EY >> N >> Q;
    for (ll i = 0; i < Q; i++) {
        ll sx, sy, ex, ey;
        cin >> sx >> sy >> ex >> ey;
        if (ex - sx <= N) {
            updq.push_back({ex - N, 0, ey, sy});
            updq.push_back({sx + 1, 1, ey, sy});
        }
    }
    sort(updq.begin(), updq.end());
    for (auto i : updq) {
        if (!i.typ)
            ad(1, EY, SY + N, i.e, i.s + N, 1);
        else
            ad(1, EY, SY + N, i.e, i.s + N, -1);
        ans = max(ans, segT[1]);
    }
    cout << ans;
}