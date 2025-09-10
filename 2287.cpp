#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ln '\n'
struct dta {
    ll p, t, typ;
    bool operator<(const dta& b) const {
        if (t == b.t) return typ < b.typ;
        return t < b.t;
    }
};
ll N, M, ans, lst;
dta arr[200005];
multiset<ll> market;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> N >> M;
    for (ll i = 0; i < N; i++) {
        cin >> arr[i].p >> arr[i].t;
        arr[i].typ = 0;
    }
    for (ll i = N; i < N + M; i++) {
        cin >> arr[i].p >> arr[i].t;
        arr[i].typ = 1;
    }
    sort(arr, arr + N + M);
    for (ll i = N + M - 1; i >= 0; i--) {
        if (arr[i].typ) {
            market.insert(arr[i].p);
        } else {
            auto loc = market.lower_bound(arr[i].p);
            if (loc == market.end()) {
                ans = -1;
                break;
            }
            ans += (*loc);
            market.erase(loc);
        }
    }
    cout << ans;
}