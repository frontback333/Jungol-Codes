#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct customer {
    ll r, w, c;
    bool operator<(const customer& b) const {
        if (w == b.w) return c < b.c;
        return w > b.w;
    }
};

ll N, k, tim, ans, ord = 1;
stack<ll> lastcashier;
priority_queue<customer> cashier;

void shift() {
    ans += ord++ * cashier.top().r;
    tim = cashier.top().w;
    lastcashier.push(cashier.top().c);
    // cout << cashier.top().r << ' ' << cashier.top().w << ' ' << cashier.top().c << ' ' << ans << '\n';
    cashier.pop();
    if (!cashier.empty() && tim == cashier.top().w) shift();
    return;
}

int main() {
    cin.tie(0)->sync_with_stdio();
    cin >> N >> k;
    for (ll i = k; i > 0; i--) {
        lastcashier.push(i);
    }
    for (int i = 1; i <= N; i++) {
        ll r, w;
        cin >> r >> w;
        if (cashier.size() >= k) shift();
        cashier.push({r, w + tim, lastcashier.top()});
        lastcashier.pop();
    }
    while (!cashier.empty()) shift();
    cout << ans;
}