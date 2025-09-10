#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ln '\n'
struct dta {
    ll i, o, p;
    bool operator<(const dta& b) const {
        return o < b.o;
    }
};
ll N;
dta ipt[100005];
ll segt[4000005];
vector<ll> comp;

void upd(ll c, ll s, ll e, ll idx, ll val) {
    if (idx < s || e < idx) return;
    if (s == e) {
        segt[c] = max(segt[c], val);
        // cout << idx << ' ' << segt[c] << ln;
        return;
    }
    int m = s + e >> 1, nxt = c * 2;
    upd(nxt, s, m, idx, val);
    upd(nxt + 1, m + 1, e, idx, val);
    segt[c] = max(segt[nxt], segt[nxt + 1]);
}

ll query(ll c, ll s, ll e, ll qs, ll qe) {
    if (qe < s || e < qs) return 0;
    if (qs <= s && e <= qe) return segt[c];
    int m = s + e >> 1, nxt = c * 2;
    return max(query(nxt, s, m, qs, qe), query(nxt + 1, m + 1, e, qs, qe));
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> ipt[i].i >> ipt[i].o >> ipt[i].p;
        comp.push_back(ipt[i].i);
        comp.push_back(ipt[i].o);
    }
    sort(ipt, ipt + N);
    sort(comp.begin(), comp.end());
    comp.erase(unique(comp.begin(), comp.end()), comp.end());
    for (int i = 0; i < N; i++) {
        ll idx = lower_bound(comp.begin(), comp.end(), ipt[i].o) - comp.begin();
        ll iidx = lower_bound(comp.begin(), comp.end(), ipt[i].i) - comp.begin();
        /*cout << ipt[i].i << ' ' << ipt[i].o << ' ' << ipt[i].p << ' ';
        cout << idx << ' ' << iidx << ln;*/
        upd(1, 0, comp.size() - 1, idx, ipt[i].p + query(1, 0, comp.size() - 1, 0, iidx));
    }
    cout << segt[1];
}