#include <bits/stdc++.h>
using namespace std;
using ll = long long;
struct nod {
    ll parent;
    vector<ll> children;
};
ll N, Q, K, ans;
ll U[250005];
map<ll, ll> S, sze;
nod nodes[250005];

void setPar(ll idx) {
    for (auto i : nodes[idx].children) {
        if (i != nodes[idx].parent) {
            nodes[i].parent = idx;
            setPar(i);
        }
    }
    return;
}

ll Find(ll idx) {
    if (U[idx] == idx) return idx;
    return U[idx] = Find(U[idx]);
}

void Union(ll idx) {
    ll a = Find(idx);
    ll b = Find(nodes[idx].parent);
    // cout << idx << ' ' << a << ' ' << b << ' ' << S[b] << '\n';
    if (a != b && S[b] && S[nodes[idx].parent]) {
        U[a] = U[b];
        sze[b] += sze[a];
        sze[a] = 1;
        Union(nodes[idx].parent);
    }
}

int main() {
    cin.tie(0)->sync_with_stdio();
    cin >> N;
    for (int i = 0; i < N - 1; i++) {
        ll a, b;
        cin >> a >> b;
        nodes[a].children.push_back(b);
        nodes[b].children.push_back(a);
    }
    setPar(1);
    cin >> Q;
    while (Q--) {
        S.clear();
        sze.clear();
        ans = 0;
        cin >> K;
        for (int i = 0; i < K; i++) {
            ll sk;
            cin >> sk;
            S[sk] = 1;
            U[sk] = sk;
            sze[sk] = 1;
        }
        for (auto i : S) {
            if (i.second) Union(i.first);
        }
        for (auto i : sze) {
            if (i.second > 1) {
                // cout << i.first << ' ' << i.second << '\n';
                ans += i.second * (i.second - 1) / 2;
            }
        }
        cout << ans << '\n';
    }
}