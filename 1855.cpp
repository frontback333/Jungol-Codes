#include <bits/stdc++.h>
using namespace std;
using ll = long long;
struct vil {
    ll u, cost;
    bool operator<(const vil& b) const {
        return cost > b.cost;
    }
};
ll N, P, C, ans = 2e8;
ll dist[805], stloc[505];
vector<vil> adj[805];
priority_queue<vil> pq;

void rstdist(ll st) {
    for (int i = 1; i <= P; i++) dist[i] = 2e8;
    dist[st] = 0;
}

void dijkstra(ll st) {
    rstdist(st);
    pq.push({st, 0});
    while (!pq.empty()) {
        vil t = pq.top();
        pq.pop();
        if (dist[t.u] < t.cost) continue;
        for (vil a : adj[t.u]) {
            if (dist[a.u] > a.cost + t.cost) {
                dist[a.u] = a.cost + t.cost;
                pq.push({a.u, dist[a.u]});
            }
        }
    }
}

int main() {
    cin.tie(0)->sync_with_stdio();
    cin >> N >> P >> C;
    while (C--) {
        ll s, e, co;
        cin >> s >> e >> co;
        adj[s].push_back({e, co});
        adj[e].push_back({s, co});
    }
    for (int i = 0; i < N; i++) {
        cin >> stloc[i];
    }
    for (int i = 1; i <= P; i++) {
        int sum = 0;
        dijkstra(i);
        for (int j : stloc) {
            sum += dist[j];
            cout << sum << '\n';
            if (sum > ans) break;
        }
        if (sum < ans) ans = sum;
    }
    cout << ans;
}