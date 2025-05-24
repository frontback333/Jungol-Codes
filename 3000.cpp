#include <bits/stdc++.h>
using namespace std;
using ll = long long;
struct seg {
    ll parent, s, e;
    vector<ll> children;
};
ll N, Q, num;
ll segT[1000005];
seg tre[200005];

void EulerTour(ll idx) {
    num += 1;
    tre[idx].s = num;
    if (tre[idx].children.empty()) {
        tre[idx].e = num;
        return;
    }
    for (ll i : tre[idx].children) {
        EulerTour(i);
    }
    tre[idx].e = num;
    return;
}

void setSegT(ll now, ll s, ll e) {
    segT[now] = 1;
    if (s == e) return;
    ll m = (s + e) / 2;
    setSegT(now * 2, s, m);
    setSegT(now * 2 + 1, m + 1, e);
}

void changeSegT(ll now, ll s, ll e, ll ts, ll te, ll val) {
    if (e < ts || s > te) return;
    if (ts <= s && e <= te) {
        if (segT[now] < val) segT[now] = val;
        return;
    }
    if (s == e) return;
    ll m = (s + e) / 2;
    changeSegT(now * 2, s, m, ts, te, val);
    changeSegT(now * 2 + 1, m + 1, e, ts, te, val);
}

ll getMaxSegT(ll now, ll s, ll e, ll loc) {
    if (s == e && s == loc) {
        return segT[now];
    }
    if (loc < s || e < loc) return 0;
    ll m = (s + e) / 2;
    if (m < loc) return max(segT[now], getMaxSegT(now * 2 + 1, m + 1, e, loc));
    return max(segT[now], getMaxSegT(now * 2, s, m, loc));
}

int main() {
    cin.tie(0)->sync_with_stdio();
    cin >> N >> Q;
    for (int i = 1; i <= N - 1; i++) {
        cin >> tre[i + 1].parent;
        tre[tre[i + 1].parent].children.push_back(i + 1);
    }
    EulerTour(1);
    setSegT(1, 1, N);
    for (int i = 0; i < Q; i++) {
        ll b, c, d;
        cin >> b >> c >> d;
        if (getMaxSegT(1, 1, N, tre[b].s) == getMaxSegT(1, 1, N, tre[c].s)) {
            cout << "YES\n";
            if (d) changeSegT(1, 1, N, tre[b].s, tre[b].e, tre[b].s);
        } else {
            cout << "NO\n";
            if (d) changeSegT(1, 1, N, tre[c].s, tre[c].e, tre[c].s);
        }
    }
}