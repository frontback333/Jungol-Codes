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
int comedist[1005], godist[1005];
vector<village> cadj[1005], gadj[1005];
priority_queue<village> pq;

void setdist() {
    for (int i = 0; i <= 1001; i++) {
        comedist[i] = 2e8;
        godist[i] = 2e8;
    }
    comedist[X] = 0;
    godist[X] = 0;
}

void dijkstra() {
    setdist();
    pq.push({X, 0});
    while (!pq.empty()) {
        village t = pq.top();
        pq.pop();
        if (comedist[t.u] < t.d) continue;
        for (village a : cadj[t.u]) {
            if (comedist[a.u] > a.d + t.d) {
                comedist[a.u] = a.d + t.d;
                pq.push({a.u, comedist[a.u]});
            }
        }
    }
    pq.push({X, 0});
    while (!pq.empty()) {
        village t = pq.top();
        pq.pop();
        if (godist[t.u] < t.d) continue;
        for (village a : gadj[t.u]) {
            if (godist[a.u] > a.d + t.d) {
                godist[a.u] = a.d + t.d;
                pq.push({a.u, godist[a.u]});
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
        cadj[e].push_back({s, d});
        gadj[s].push_back({e, d});
    }
    dijkstra();
    for (int i = 1; i <= N; i++) {
        // cout << godist[i] << ' ' << comedist[i] << '\n';
        if (comedist[i] + godist[i] > mx) mx = comedist[i] + godist[i];
    }
    cout << mx;
}