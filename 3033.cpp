#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ln '\n'
struct dta {
    ll u, d, tim, temp;
    bool operator<(const dta& b) const {
        return d > b.d;
    }
};
ll N, M, X, ans = 1e13;
ll dist[10005][205], vis[10005][205], typ[10005];
vector<dta> tre[10005];
priority_queue<dta> pq;

void dijkstra() {
    for (int i = 0; i <= N; i++) {
        for (int j = 0; j <= X; j++) {
            dist[i][j] = 1e13;
        }
    }
    dist[1][X] = 0;
    pq.push({1, dist[1][X], X, typ[1]});
    while (!pq.empty()) {
        auto t = pq.top();
        pq.pop();
        if (vis[t.u][t.tim]) continue;
        vis[t.u][t.tim] = 1;
        for (auto i : tre[t.u]) {
            if (typ[i.u] == 1) {
                ll tim = t.tim - i.d;
                if (tim < 0) tim = 0;
                if (dist[i.u][tim] > t.d + i.d) {
                    dist[i.u][tim] = t.d + i.d;
                    pq.push({i.u, dist[i.u][tim], tim, t.temp});
                }
            } else {
                if (t.temp != typ[i.u] && t.tim - i.d > 0) continue;
                if (dist[i.u][X] > t.d + i.d) {
                    dist[i.u][X] = t.d + i.d;
                    pq.push({i.u, dist[i.u][X], X, typ[i.u]});
                }
            }
        }
    }
}

int main() {
    cin.tie(0)->sync_with_stdio();
    cin >> N >> M >> X;
    for (int i = 1; i <= N; i++) {
        ll t;
        cin >> t;
        typ[i] = t;
    }
    while (M--) {
        ll a, b, d;
        cin >> a >> b >> d;
        tre[a].push_back({b, d});
        tre[b].push_back({a, d});
    }
    dijkstra();
    for (int i = 0; i <= X; i++) ans = min(ans, dist[N][i]);
    cout << ans;
}