// D[i][j] = [i][j]������ ���� ���� �κм���
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
struct Data {
    ll value;
    ll i, j, n, m;
    bool operator<(const Data& other) const {
        return value < other.value;
    }
    void add(int val) { value += val; }
};
string A, B, ansA, ansB;
Data D[1005][1005];
ll N, M;
Data maxsim() {
    for (ll i = 1; i <= N; i++) {
        for (ll j = 1; j <= M; j++) {
            if (A[i - 1] == B[j - 1]) {
                D[i][j] = max({0, i, j}, D[i - 1][j - 1]);
                D[i][j].add(3);
            } else {
                D[i][j] = max({{0, i, j}, D[i - 1][j - 1], D[i - 1][j], D[i][j - 1]});
                D[i][j].add(-2);
            }
            D[i][j].n = i;
            D[i][j].m = j;
        }
    }
    return *max_element(D[0], D[N + 1]);
}
int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> N >> A >> M >> B;
    for (ll i = 0; i <= max(N, M); i++) {
        D[i][0] = {-2 * i, i, 0};
        D[0][i] = {-2 * i, 0, i};
    }
    Data mx = maxsim();
    cout << mx.value << '\n';
    A = A.substr(mx.i - 1, mx.n - (mx.i - 1));
    B = B.substr(mx.j - 1, mx.m - (mx.j - 1));
    cout << A << '\n'
         << B;
}
