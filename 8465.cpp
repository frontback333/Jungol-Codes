#include <bits/stdc++.h>
using namespace std;
using ll = long long;
struct nod {
    ll ad, parents;
    vector<ll> children;
};
ll N, M, inf, ans;
ll V[10005];
nod Nodes[10005];
queue<ll> q;

void Del() {
    Nodes[1].ad = 1;
    q.push(1);
    while (!q.empty()) {
        auto c = q.front();
        q.pop();
        if (V[c]) continue;
        V[c] = 1;
        for (auto i : Nodes[c].children) {
            if (!V[i]) q.push(i);
        }
    }
    for (ll i = 1; i <= N; i++) {
        if (!V[i] && i != 2) {
            q.push(i);
        }
        V[i] = 0;
    }
    while (!q.empty()) {
        for (auto i : Nodes[q.front()].children) {
            Nodes[i].parents--;
        }
        q.pop();
    }
}

void Topology() {
    Del();
    Nodes[1].ad = 1;
    q.push(1);
    while (!q.empty()) {
        auto c = q.front();
        q.pop();
        V[c] = 1;
        for (auto i : Nodes[c].children) {
            Nodes[i].parents--;
            Nodes[i].ad = (Nodes[i].ad + Nodes[c].ad) % (ll)1e9;
            if (i == 2) {
                V[i] = 1;
                ans = (ans + Nodes[c].ad) % (ll)1e9;
            }
            if (i != 2 && !Nodes[i].parents)
                q.push(i);
        }
    }
    if (!V[2]) inf = 1;
}

int main() {
    cin >> N >> M;
    while (M--) {
        ll A, B;
        cin >> A >> B;
        Nodes[A].children.push_back(B);
        Nodes[B].parents++;
    }
    Topology();
    if (inf)
        cout << "inf";
    else
        cout << ans % (ll)1e9;
}