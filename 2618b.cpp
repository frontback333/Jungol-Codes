#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ln '\n'
struct dta {
    ll x, ys, ye, w;
    bool operator<(const dta& b) const {
        if (x == b.x) return w < b.w;
        return x < b.x;
    }
};
ll N, W, H, ans;
ll lazy[1800005], segT[1800005];
multiset<dta> st;
vector<ll> comp;

void prop(ll c, ll s, ll e) {
    if (!lazy[c]) return;
    if (s < e) {
        lazy[c * 2] += lazy[c];
        lazy[(c * 2) + 1] += lazy[c];
    }
    segT[c] += lazy[c];
    lazy[c] = 0;
    return;
}

void upd(ll c, ll s, ll e, ll qs, ll qe, ll val) {
    prop(c, s, e);
    if (qe < s || e < qs) return;
    if (qs <= s && e <= qe) {
        lazy[c] += val;
        return prop(c, s, e);
    }
    ll m = s + e >> 1, nt = c * 2;
    upd(nt, s, m, qs, qe, val);
    upd(nt + 1, m + 1, e, qs, qe, val);
    segT[c] = max(segT[nt], segT[nt + 1]);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> N >> W >> H;
    for (ll i = 0; i < N; i++) {
        ll x, y, w;
        cin >> x >> y >> w;
        st.insert({x, y - H + 1, y + H - 1, w});
        st.insert({x + W, y - H + 1, y + H - 1, -w});
        comp.push_back(y - H + 1);
        comp.push_back(y + H - 1);
    }
    sort(comp.begin(), comp.end());
    comp.erase(unique(comp.begin(), comp.end()), comp.end());
    for (auto i : st) {
        auto qs = lower_bound(comp.begin(), comp.end(), i.ys) - comp.begin();
        auto qe = lower_bound(comp.begin(), comp.end(), i.ye) - comp.begin();
        upd(1, 0, comp.size() - 1, qs, qe, i.w);
        ans = max(ans, segT[1]);
    }
    cout << ans;
}