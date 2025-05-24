#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int N, ans;
int D[355];
char S[355];
string O;

void DP(int idx) {
    if (idx > N) return;
    if (S[idx] == S[idx - 1] || S[idx] == 'w') {
        D[idx] = D[idx - 1] + 1;
        DP(idx + 1);
        return;
    }
    if (S[idx - 1] == 'w') {
        int ck = 0;
        for (int i = idx; i >= 0; i--) {
            if (S[i] != 'w' && S[i] != S[idx]) {
                ck = idx - i;
                break;
            }
            if (!i) ck = D[idx - 1] + 1;
        }
        if (ck) {
            D[idx] = ck;
            DP(idx + 1);
            return;
        }
    }
    D[idx] = 1;
    DP(idx + 1);
    return;
}

int main() {
    cin.tie(0)->sync_with_stdio();
    cin >> N >> O;
    D[0] = 1;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N - i; j++) {
            S[j] = O[j + i];
        }
        for (int j = 0; j < i; j++) {
            S[N - i + j] = O[j];
        }
        DP(1);
        int tmp;
        for (int j = 0; j < N; j++) {
            if (D[j + 1] <= D[j]) {
                tmp = D[j];
                if (j == N - 1) {
                    cout << tmp;
                    return 0;
                }
                break;
            }
        }
        for (int j = 0; j < N; j++) {
            cout << S[j];
        }
        cout << '\n';
        for (int j = 0; j < N; j++) {
            cout << D[j];
        }
        cout << '\n';
        cout << tmp << ' ' << D[N - 1] << ' ' << tmp + D[N - 1] << '\n';
        if (tmp + D[N - 1] > ans) ans = tmp + D[N - 1];
    }
    if (ans > N) ans = N;
    cout << ans;
}