#include <bits/stdc++.h>
using namespace std;
using ll = long long;
struct Dta {
    int ui, uj, d;
    bool operator<(const Dta& b) const {
        return d > b.d;
    }
};
int N, Ai, Aj, mn = 2e8;
int mount[105][105], ck[105][105];
int visit[105][105], dist[105][105];
int X[6] = {-1, 1, 0, 0}, Y[6] = {0, 0, -1, 1};
vector<Dta> adj[105][105];
priority_queue<Dta> pq;

void dijkstra() {
    for (int i = 0; i <= N + 1; i++)
        for (int j = 0; j <= N + 1; j++)
            dist[i][j] = 2e8;
    dist[Ai][Aj] = 0;
    pq.push({Ai, Aj, 0});
    while (!pq.empty()) {
        Dta t = pq.top();
        pq.pop();
        if (visit[t.ui][t.uj]) continue;
        visit[t.ui][t.uj] = 1;
        for (const Dta& a : adj[t.ui][t.uj]) {
            if (!visit[a.ui][a.uj] && dist[a.ui][a.uj] > t.d + a.d) {
                dist[a.ui][a.uj] = t.d + a.d;
                pq.push({a.ui, a.uj, dist[a.ui][a.uj]});
            }
        }
    }
}

void makegraph(int a, int b) {
    if (!a || !b || a > N || b > N || ck[a][b]) return;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            int newi = a + Y[i], newj = b + X[i];
            int price;
            if (mount[a][b] < mount[newi][newj])
                price = mount[newi][newj] - mount[a][b];
            else if (mount[a][b] > mount[newi][newj])
                price = (mount[a][b] - mount[newi][newj]) * (mount[a][b] - mount[newi][newj]);
            else
                price = 0;
            adj[a][b].push_back({newi, newj, price});
            ck[a][b] = 1;
            makegraph(newi, newj);
        }
    }
    return;
}

int main() {
    cin >> N >> Ai >> Aj;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> mount[i][j];
        }
    }
    makegraph(Ai, Aj);
    dijkstra();
    for (int i = 0; i <= N + 1; i++) {
        int minx = min(dist[0][i], dist[N + 1][i]);
        int miny = min(dist[i][0], dist[i][N + 1]);
        int finmin = min(minx, miny);
        if (finmin < mn) mn = finmin;
    }
    cout << mn;
}