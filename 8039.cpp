#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll N, Q;
int candids[100005];
map<ll, set<ll>> pyo;

int main() {
    cin.tie(0)->sync_with_stdio();
    cin >> N >> Q;
    for (ll i = 1; i <= N; i++) {
        pyo[0].insert(i);
    }
    while (Q--) {
        ll typ;
        cin >> typ;
        if (!typ) {
            ll n, k;
            cin >> n >> k;
            pyo[candids[n]].erase(n);
            candids[n] += k;
            pyo[candids[n]].insert(n);
        } else {
            ll x;
            cin >> x;
            if (pyo[x].empty())
                cout << "None";
            else
                for (ll e : pyo[x]) cout << e << ' ';
            cout << '\n';
        }
    }
}