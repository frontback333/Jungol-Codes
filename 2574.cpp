#include <bits/stdc++.h>
using namespace std;
using ll = long long;
struct nod {
    ll parent, ea;
    vector<ll> children;
};
ll N, ans;
nod tre[1000005];

void maketre(ll curnod, ll par) {
    for (auto i : tre[curnod].children) {
        if (par == i) continue;
        maketre(i, curnod);
        if (!tre[i].ea && !tre[curnod].ea) {
            tre[curnod].ea = 1;
            ans += 1;
        }
    }
    return;
}

int main() {
    cin.tie(0)->sync_with_stdio();
    cin >> N;
    for (int i = 1; i < N; i++) {
        int a, b;
        cin >> a >> b;
        tre[a].children.push_back(b);
        tre[b].children.push_back(a);
    }
    maketre(1, 0);
    cout << ans;
}