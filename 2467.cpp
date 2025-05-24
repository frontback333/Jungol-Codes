#include <bits/stdc++.h>
using namespace std;
using ll = long long;
struct edge {
    int x, y, w;
    bool operator<(const edge& b) const {
        return w > b.w;
    }
};
ll N, M, ans, sum;
ll parent[100005];
ll sz[100005];
edge edges[100005];

ll Find(int a) {
    if (parent[a] != a) parent[a] = Find(parent[a]);
    return parent[a];
}

void UGM(int a, int b, int w) {
    ll px = Find(a), py = Find(b);
    if (px == py) {
        sum -= w;
        return;
    }
    ans += sum * sz[px] * sz[py];
    parent[py] = px;
    sz[px] += sz[py];
    sum -= w;
    ans %= 1000000000;
}

int main() {
    cin.tie(0)->sync_with_stdio();
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        int x, y, w;
        cin >> x >> y >> w;
        edges[i] = {x, y, w};
        sum += w;
    }
    for (int i = 1; i <= N; i++) {
        parent[i] = i;
        sz[i] = 1;
    }
    sort(edges, edges + M);
    for (int i = 0; i < M; i++) {
        UGM(edges[i].x, edges[i].y, edges[i].w);
    }
    cout << ans;
}