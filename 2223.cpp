#include <bits/stdc++.h>
using namespace std;
using ll = long long;
struct Dta {
    int s, e, d;
};
int F, N, M, B, ck;
int dist[505];
Dta blackhole[205];
vector<Dta> edge;

void rstdist(int st) {
    for (int i = 1; i <= N; i++) dist[i] = 2e8;
    dist[st] = 0;
}

int belmanford(int st) {
    rstdist(st);
    int negc = 0;
    for (int i = 1; i <= N; i++) {
        negc = 0;
        // for (int j = 1; j <= N; j++) cout << dist[j] << '\n';
        for (Dta j : edge) {
            // cout << j.s << ' ' << j.e << ' ' << j.d << '\n';
            if (dist[j.e] > dist[j.s] + j.d) {
                dist[j.e] = dist[j.s] + j.d;
                negc = 1;
            }
        }
    }
    return negc;
}

int main() {
    cin.tie(0)->sync_with_stdio();
    cin >> F;
    while (F--) {
        edge.clear();
        cin >> N >> M >> B;
        int s, e, t;
        for (int i = 1; i <= M + B; i++) {
            cin >> s >> e >> t;
            if (i <= M) {
                edge.push_back({s, e, t});
                edge.push_back({e, s, t});
            } else {
                edge.push_back({s, e, -t});
                blackhole[i - M] = {s, e, -t};
            }
        }
        ck = 0;
        ck = belmanford(1);
        if (ck)
            cout << "YES" << '\n';
        else
            cout << "NO" << '\n';
    }
}