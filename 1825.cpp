#include <bits/stdc++.h>
using namespace std;
using ll = long long;
struct Dta {
    ll price;
    map<ll, ll> used;
};
int N, P;
int gain[25][305];
Dta D[305];

void DP(int pce) {
    if (pce > P) return;
    for (int i = pce - 1; i >= 0; i--) {
        for (int j = 1; j <= N; j++) {
            if (D[i].used[j]) continue;
            if (D[pce].price < D[i].price + gain[j][pce - i]) {
                D[pce].price = D[i].price + gain[j][pce - i];
                D[pce].used = D[i].used;
                D[pce].used[j] = pce - i;
            }
        }
    }
    DP(pce + 1);
}

int main() {
    cin >> P >> N;
    for (int i = 1; i <= P; i++) {
        int pg, a;
        cin >> pg;
        for (int j = 1; j <= N; j++) {
            cin >> a;
            gain[j][pg] = a;
        }
    }
    DP(1);
    cout << D[P].price << '\n';
    for (auto i : D[P].used) {
        cout << i.second << ' ';
    }
}