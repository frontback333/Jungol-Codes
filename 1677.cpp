#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll N;
ll arr[1005][1005], DL[1005][1005], DR[1005][1005];

void doD(ll r) {
    if (r > N) return;
    DL[r][1] = max(DL[r - 1][1], DR[r - 1][1]) + arr[r][1];
    DR[r][N] = max(DL[r - 1][N], DR[r - 1][N]) + arr[r][N];
    for (int i = 2; i <= N; i++) DL[r][i] = max({DL[r - 1][i], DR[r - 1][i], DL[r][i - 1]}) + arr[r][i];
    for (int i = N - 1; i > 0; i--) DR[r][i] = max({DL[r - 1][i], DR[r - 1][i], DR[r][i + 1]}) + arr[r][i];
    doD(r + 1);
}

int main() {
    cin.tie(0)->sync_with_stdio();
    cin >> N;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) cin >> arr[i][j];
    }
    for (int i = 1; i <= N; i++) DL[1][i] = DL[1][i - 1] + arr[1][i];
    doD(2);
    cout << max(DL[N][N], DR[N][N]);
}