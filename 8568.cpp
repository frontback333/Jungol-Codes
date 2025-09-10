#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll N, p[6], pp, D[2005][2005];
string A, B;

ll doD(ll a, ll b) {
    if (a < 1 && b < 1) return 0;
    if (a < 1) a = 0;
    if (b < 1) b = 0;
    if (D[a][b] >= 0) return D[a][b];
    ll ret = (ll)1e13;
    for (int i = 1; i <= 5; i++) {
        if (a > 0) ret = min(ret, doD(a - i, b) + p[i]);
        if (b > 0) ret = min(ret, doD(a, b - i) + p[i]);
    }
    if (a == b) ret = min(ret, doD(a - 4, b - 4) + pp);
    if (A[a] == '0' && a > 0) ret = min(ret, doD(a - 1, b));
    if (B[b] == '0' && b > 0) ret = min(ret, doD(a, b - 1));
    return D[a][b] = ret;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> N >> A >> B >> p[1] >> p[3] >> p[5] >> pp;
    A = ' ' + A;
    B = ' ' + B;
    for (int i = 0; i <= N; i++) {
        for (int j = 0; j <= N; j++) D[i][j] = -1;
    }
    for (int i = 1; i <= 5; i++) {
        if (i <= 1)
            p[i] = min({p[1], p[3], p[5]});
        else if (i <= 3)
            p[i] = min(p[3], p[5]);
        else
            p[i] = p[5];
    }
    cout << doD(N, N);
}