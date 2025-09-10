#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll N, ans;
ll A[2005], B[2005], D[2005][2005];

ll doD(ll L, ll R) {
    if (D[L][R] >= 0) return D[L][R];
    if (L > N + 1 || R > N + 1) return 0;
    ll mx = max(doD(L + 1, R), doD(L + 1, R + 1));
    if (A[L] > B[R]) mx = max(mx, doD(L, R + 1) + B[R]);
    D[L][R] = mx;
    return D[L][R];
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> N;
    for (int i = 1; i <= N; i++) cin >> A[i];
    for (int i = 1; i <= N; i++) cin >> B[i];
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++) D[i][j] = -1;
    cout << doD(1, 1);
}