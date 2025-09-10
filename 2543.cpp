#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll N, X, Y;
ll arr[600][600];
ll tiles[5][3][3] = {{{0, 1}, {1, 1}}, {{2, 0}, {2, 2}}, {{3, 3}, {0, 3}}, {{4, 4}, {4, 0}}};

void Fil() {
}

void binS(ll r, ll c, ll n, ll hr, ll hc) {
    if (!n) return;
    ll mr = r + n, mc = c + n;
    ll hn = (hr >= mr) * 2 + (hc >= mc) + 1;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            if (i * 2 + j + 1 == hn)
                binS(r + n * i, c + n * j, n / 2, hr, hc);
            else {
                arr[mr - !i][mc - !j] = hn;
                binS(r + n * i, c + n * j, n / 2, mr - !i, mc - !j);
            }
        }
    }
}

int main() {
    cin >> N >> X >> Y;
    binS(0, 0, N / 2, X, Y);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << arr[i][j] << ' ';
        }
        cout << '\n';
    }
}