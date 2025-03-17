// D[i][j] = [i][j]������ ���� ���� �κм���
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
string A, B;
int D[1005][1005];
ll N, M;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> N >> A >> M >> B;
    for (ll i = 0; i <= max(N, M); i++) {
        D[i][0] = i;
        D[0][i] = i;
    }
    for (ll i = 1; i <= N; i++) {
        for (ll j = 1; j <= M; j++) {
            if (A[i - 1] == B[j - 1])
                D[i][j] = D[i - 1][j - 1];
            else
                D[i][j] = min(D[i - 1][j - 1], min(D[i - 1][j], D[i][j - 1])) + 1;
        }
    }
    for (ll i = 0; i <= N; i++) {
        for (ll j = 0; j <= M; j++) {
            cout << D[i][j] << ' ';
        }
        cout << '\n';
    }
    cout << D[N][M];
}