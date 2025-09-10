#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ln '\n';
ll T, N;
stack<pair<ll, ll>> stk;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> T;
    for (ll tt = 1; tt <= T; tt++) {
        ll ans = 0, sum = 0;
        while (!stk.empty()) stk.pop();
        cin >> N;
        for (ll i = 0; i < N; i++) {
            ll tmp;
            cin >> tmp;
            ll sum = stk.empty() ? 0 : stk.top().second;
            if (tmp >= 0)
                stk.push({tmp, sum + tmp * (stk.size() + 1)});
            else {
                while (tmp < 0 && !stk.empty()) {
                    tmp += stk.top().first;
                    stk.pop();
                }
                sum = stk.empty() ? 0 : stk.top().second;
                if (tmp >= 0) stk.push({tmp, sum + tmp * (stk.size() + 1)});
            }
            if (!stk.empty()) ans += stk.top().second;
        }
        cout << "Case #" << tt << ": " << ans << ln;
    }
}