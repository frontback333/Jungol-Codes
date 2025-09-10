#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int N;
int D[100][20];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> N;
    D[0][0] = 1;
    for (int i = 0; i <= 3 * N; i++) {
        for (int j = 0; j <= 0b1111; j++) {
            if (!D[i][j]) continue;
            if (j & 1)
                D[i + 1][j >> 1] += D[i][j];
            else {
                if (!(j & 0b0010) && ((i + 1) % 3)) D[i][j | 0b0011] += D[i][j];
                if (!(j & 0b1000)) D[i][j | 0b1001] += D[i][j];
            }
        }
    }
    cout << D[N * 3][0];
}