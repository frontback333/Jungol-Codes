#include <bits/stdc++.h>
using namespace std;

int N, K;
int D[1005][1005], ck[1005][1005];

void Dcnt(int i, int j) {
    if (i > N || j > K || j >= i) return;
    if (ck[i][j]) return;
    D[i][j] = (D[i - 2][j - 1] + D[i - 1][j]) % 1000000003;
    ck[i][j] = 1;
    // cout << D[i][j] << ' ';
    Dcnt(i + 1, j);
    if (!D[i - 1][j]) Dcnt(i, j + 1);
    return;
}

int main() {
    cin >> N >> K;
    for (int i = 2; i <= N; i++) {
        D[i][1] = i;
        ck[i][1] = 1;
    }
    Dcnt(4, 2);
    cout << D[N][K];
}