#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll N, D[35];

ll doD(int idx) {
    if (D[idx] >= 0) return D[idx];
    if (!idx) return 1;
    D[idx] = doD(idx - 2) * 3;
    for (int i = 4; i <= idx; i += 2) {
        D[idx] += doD(idx - i) * 2;
    }
    return D[idx];
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> N;
    for (int i = 0; i <= 30; i++) D[i] = -1;
    N % 2 ? cout << 0 : cout << doD(N);
}