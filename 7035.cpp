#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll N, Q;
ll scores[100005], arr[100005];

void upd(ll now, const ll& val) {
    if (now > 100000) return;
    arr[now] += val;
    upd(now + (now & -now), val);
    return;
}

ll query(ll e) {
    ll s = 0;
    while (e > 0) {
        s += arr[e];
        e -= e & -e;
    }
    return s;
}

int main() {
    cin.tie(0)->sync_with_stdio();
    cin >> N >> Q;
    for (int i = 1; i <= N; i++) {
        cin >> scores[i];
        upd(scores[i], 1);
    }
    while (Q--) {
        ll ty, x, y;
        cin >> ty;
        if (ty & 1) {
            cin >> x;
            cout << query(100000) - query(scores[x]) + 1 << '\n';
        } else {
            cin >> x >> y;
            upd(scores[x], -1);
            scores[x] = y;
            upd(scores[x], 1);
        }
    }
}