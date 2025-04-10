#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int X, Y, N, arr[550][550], checkarr[550][550];
struct Tiles {
    int X[5], Y[5];
};
Tiles T[5] = {
    {{1, 1, 0}, {0, 1, 1}},
    {{0, 1, 1}, {-1, -1, 0}},
    {{-1, -1, 0}, {0, 1, 1}},
    {{0, -1, -1}, {-1, -1, 0}},
};

void FillTile(int X, int Y, int sze, int hx, int hy) {
    if (sze <= 2) return;
    sze /= 2;
    if (hx >= X + sze) {
        if (hy >= Y + sze) {
            for (int i = 0; i < 4; i++) {
                arr[X + sze + T[3].X[i]][Y + sze + T[3].Y[i]] = 4;
            }
        } else {
            for (int i = 0; i < 4; i++) {
                arr[X + sze + T[3].X[i]][Y + sze - 1 + T[3].Y[i]] = 2;
            }
        }
    }
    FillTile(X, Y, sze / 2);
    FillTile(X + sze / 2, Y, sze / 2);
    FillTile(X, Y + sze / 2, sze / 2);
    FillTile(X + sze / 2, Y + sze / 2, sze / 2);
}

int main() {
    cin.tie(0)->sync_with_stdio();
    cin >> N >> X >> Y;
    arr[X][Y] = -1;
    FillTile(0, 0, N, X, Y);
    arr[X][Y] = 5;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << arr[i][j] << ' ';
        }
        cout << '\n';
    }
}