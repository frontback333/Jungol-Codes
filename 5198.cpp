#include <bits/stdc++.h>
using namespace std;
using ll = long long;
struct nod {
    vector<ll> children;
};
ll N, Q, K, ans;
ll S[250005], Trsze[250005], U[250005];
map<ll, ll> mp;
nod nodes[250005];

ll Find(ll idx) {
    if (U[idx] == idx) return idx;
    return U[idx] = Find(U[idx]);
}

void Union(ll idx) {
    ll lst = 0, ck = 0;
    for (auto i : nodes[idx].children) {
        if (!mp[i]) continue;
        ll crt = Find(i);
        if (!lst) lst = crt;
        if (crt != lst) {
            ck = 1;
        }
        lst = crt;
    }
    if (!ck) return;
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
    while (Q--) {
        mp.clear();
        cin >> K;
        for (int i = 0; i < K; i++) {
            cin >> S[i];
            U[S[i]] = S[i];
            mp[S[i]] = 1;
        }
    }
}