#include <bits/stdc++.h>
using namespace std;
using ll = long long;
struct village {
    int u, d;
    bool operator<(const village& b) const {
        return d > b.d;
    }
};
int N, M, X, mx;
int dist[1005];
vector<village> gph[1005];
priority_queue<village> pq;

void setdist() {
    for (int i = 0; i <= N; i++) {
        dist[i] = 2e8;
    }
    dist[X] = 0;
}

void dijkstra() {
    setdist();
    pq.push({X, 0});
    while (!pq.empty()) {
        village t = pq.top();
        pq.pop();
        if (dist[t.u] < t.d) continue;
        for (village a : gph[t.u]) {
            if (dist[a.u] > a.d + t.d) {
                dist[a.u] = a.d + t.d;
                pq.push({a.u, dist[a.u]});
            }
        }
    }
}

int main() {
    cin.tie(0)->sync_with_stdio();
    cin >> N >> M >> X;
    for (int i = 0; i < M; i++) {
        int s, e, d;
        cin >> s >> e >> d;
        gph[s].push_back({e, d});
    }
    for (int i = 1; i <= N; i++) {
        if (mx < dist[i]) mx = dist[i];
    }
    cout << mx;
}