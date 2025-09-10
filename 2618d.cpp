#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ln '\n'
struct dta {
    ll p;
    vector<ll> children;
};
ll N;
dta Tre[70005];

void setTre(int idx) {
    if (Tre[idx].children.empty()) return;
    for (auto i : Tre[idx].children) {
        if (i != Tre[idx].p) {
            Tre[i].p = idx;
            setTre(i);
        }
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> N;
    for (int i = 1; i < N; i++) {
        ll u, v;
        cin >> u >> v;
        Tre[u].children.push_back(v);
        Tre[v].children.push_back(u);
    }
    setTre(1);
    for (int i = 1; i <= N; i++) {
        if (Tre[i].children.size() == 1)
            cout << 1 << ln;
        else
            cout << 2 << ln;
    }
}