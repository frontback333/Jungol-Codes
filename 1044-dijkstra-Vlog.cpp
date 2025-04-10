#include <bits/stdc++.h>
using namespace std;
using ll = long long;
struct Dta {
    int u, d;
    bool operator<(const Dta& b) const {
        return d > b.d;
    }
};
int N, M;
int path[105], dist[105], vis[105];
vector<Dta> adj[105];
priority_queue<Dta> pq;

void dijkstra(int source) {
    for (int i = 1; i <= N; i++) dist[i] = 2e9;
    dist[source] = 0;
    pq.push({source, 0});
    while (!pq.empty()) {
        Dta mn = pq.top();
        pq.pop();
        if (vis[mn.u]) continue;
        vis[mn.u] = 1;
        for (Dta& a : adj[mn.u]) {
            if (!vis[a.u] && dist[a.u] > mn.d + a.d) {
                dist[a.u] = mn.d + a.d;
                path[a.u] = mn.u;
                pq.push({a.u, dist[a.u]});
            }
        }
    }
}

int main() {
    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            int tmp;
            cin >> tmp;
            adj[i].push_back({j, tmp});
        }
    }
    dijkstra(1);
    cout << dist[M] << '\n';
    vector<int> trc;
    while (M > 0) {
        trc.push_back(M);
        M = path[M];
    }
    reverse(trc.begin(), trc.end());
    for (int i : trc) {
        cout << i << ' ';
    }
}