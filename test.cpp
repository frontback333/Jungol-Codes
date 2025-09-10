#include <bits/stdc++.h>
using namespace std;
using ll = long long;
struct dta {
    int s, e, d;
    bool operator<(const dta& b) const {
        return d > b.d;
    }
};
int N, ans;
int U[105];
priority_queue<dta> E;

int getP(int idx) {
    if (idx != U[idx]) U[idx] = getP(U[idx]);
    return U[idx];
}

void kruskual() {
    while (!E.empty()) {
        auto t = E.top();
        E.pop();
        int a = getP(t.s), b = getP(t.e);
        if (a == b) continue;
        U[a] = b;
        ans += t.d;
    }
}

int main() {
    // cin.tie(0)->sync_with_stdio(0);
    cin >> N;
    for (int i = 0; i <= N; i++) U[i] = i;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            int tmp;
            cin >> tmp;
            if (tmp) E.push({i, j, tmp});
        }
    }
    kruskual();
    cout << ans;
}
