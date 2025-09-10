#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll N, M, X, bet, bad, vis[100005];
vector<int> students[3][100005];

ll DFS(ll num, ll type) {
    ll cnt = 1;
    vis[num] = 1;
    for (ll i : students[type][num])
        if (!vis[i]) cnt += DFS(i, type);
    return cnt;
}

int main() {
    cin.tie(0)->sync_with_stdio();
    cin >> N >> M >> X;
    while (M--) {
        ll a, b;
        cin >> a >> b;
        students[0][b].push_back(a);
        students[1][a].push_back(b);
    }
    ll big = DFS(X, 0);
    for (int i = 1; i <= N; i++) vis[i] = 0;
    ll small = DFS(X, 1);
    cout << big << ' ' << N - small + 1;
}
