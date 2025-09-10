#include <bits/stdc++.h>
using namespace std;
using ll = long long;
struct dta {
    ll add, par;
    vector<ll> children;
};
ll N, M;
ll arr[505][505], D[505][505];
ll X[5] = {-1, 1, 0, 0}, Y[5] = {0, 0, -1, 1};

ll doD(ll r, ll c) {
    if (r < 1 || c < 1 || r > N || c > M) return 0;
    if (D[r][c] >= 0) return D[r][c];
    D[r][c] = 0;
    for (int i = 0; i < 4; i++) {
        if (arr[r + X[i]][c + Y[i]] > arr[r][c]) D[r][c] += doD(r + X[i], c + Y[i]);
    }
    return D[r][c];
}

int main() {
    cin.tie(0)->sync_with_stdio();
    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            cin >> arr[i][j];
            D[i][j] = -1;
        }
    }
    D[1][1] = 1;
    doD(N, M);
    cout << D[N][M];
}