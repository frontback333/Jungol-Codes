#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ln '\n';
struct dta {
    ll u, t;
    bool operator<(const dta& b) const {
        return t > b.t;
    }
};
ll N, M, a, b;
ll C[2005], dist[2005], vis[2005];
vector<dta> inptTre[2005], Tre[2005];
priority_queue<dta> pq;

void SetTre(int stt) {
    for (int i = 0; i <= N; i++) {
        dist[i] = (ll)1e14;
        vis[i] = 0;
    }
    dist[stt] = 0;
    pq.push({stt, 0});
    while (!pq.empty()) {
        auto t = pq.top();
        pq.pop();
        if (vis[t.u]) continue;
        vis[t.u] = 1;
        for (auto i : inptTre[t.u]) {
            if (dist[i.u] > t.t + i.t) {
                dist[i.u] = t.t + i.t;
                pq.push({i.u, dist[i.u]});
            }
        }
    }
}

void trackdij(int stt) {
    for (int i = 0; i <= N; i++) {
        dist[i] = (ll)1e14;
        vis[i] = 0;
    }
    dist[stt] = 0;
    pq.push({stt, 0});
    while (!pq.empty()) {
        auto t = pq.top();
        pq.pop();
        if (vis[t.u]) continue;
        vis[t.u] = 1;
        cout << t.u << ' ' << dist[t.u] << ln;
        ll x = (dist[t.u] / (a + b)) * (a + b);
        for (auto i : Tre[t.u]) {
            ll tmp = t.t + i.t;
            if (x + a < tmp) tmp += (x + a + b) - dist[t.u];
            if (dist[i.u] > tmp) {
                dist[i.u] = tmp;
                pq.push({i.u, dist[i.u]});
            }
        }
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> N >> M;
    while (M--) {
        int x, y, t;
        cin >> x >> y >> t;
        inptTre[x].push_back({y, t});
    }
    for (int i = 1; i <= N; i++) cin >> C[i];
    cin >> a >> b;
    for (int i = 1; i <= N; i++) {
        if (C[i]) continue;
        SetTre(i);
        for (int j = 1; j <= N; j++) {
            if (i == j || C[j]) continue;
            if (dist[j] <= a) Tre[i].push_back({j, dist[j]});
        }
    }
    trackdij(1);
    cout << ((dist[N] == (ll)1e14) ? -1 : dist[N]);
}