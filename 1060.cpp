#include <bits/stdc++.h>
using namespace std;
using ll = long long;
struct Dta {
    int s, e, d;
    bool operator<(const Dta& b) const {
        return d < b.d;
    }
} edj[10005];
int N, M, ans;
int group[105];

int _Find(int t) { return group[t] == t ? t : group[t] = _Find(group[t]); }

void _Union(const Dta& x) {
    int xp = _Find(x.s), yp = _Find(x.e);
    if (xp == yp) return;
    ans += x.d;
    group[yp] = xp;
}

void kruscal() {
    for (int i = 1; i <= N; i++) group[i] = i;
    sort(edj, edj + M);
    for (Dta i : edj) _Union(i);
}
int main() {
    cin.tie(0)->sync_with_stdio();
    cin >> N;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            int x;
            cin >> x;
            if (!x) continue;
            edj[M++] = {i, j, x};
        }
    }
    kruscal();
    cout << ans;
}