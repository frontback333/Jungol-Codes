#include <bits/stdc++.h>
using namespace std;
using ll = long long;
struct farm {
    int u, d;
    bool operator<(const farm& b) const {
        return d > b.d;
    }
};
int P, mn = 2e8;
char mnC;
int dist[135];
vector<farm> adj[135];
priority_queue<farm> pq;

void setdist() {
    for (int i = 0; i <= 135; i++) {
        dist[i] = 2e8;
    }
    dist[(int)'Z'] = 0;
}

void dijkstra() {
    setdist();
    pq.push({(int)'Z', 0});
    while (!pq.empty()) {
        farm t = pq.top();
        pq.pop();
        if (dist[t.u] < t.d) continue;
        for (farm a : adj[t.u]) {
            if (dist[a.u] > a.d + t.d) {
                dist[a.u] = a.d + t.d;
                pq.push({a.u, dist[a.u]});
            }
        }
    }
}

int main() {
    cin.tie(0)->sync_with_stdio();
    cin >> P;
    while (P--) {
        char ftyp, styp;
        int dist;
        cin >> ftyp >> styp >> dist;
        adj[(int)ftyp].push_back({(int)styp, dist});
        adj[(int)styp].push_back({(int)ftyp, dist});
    }
    dijkstra();
    for (int i = (int)'A'; i <= (int)'Y'; i++) {
        // cout << dist[i] << '\n';
        if (dist[i] && dist[i] < mn) {
            mn = dist[i];
            mnC = (char)i;
        }
    }
    cout << mnC << ' ' << mn;
}