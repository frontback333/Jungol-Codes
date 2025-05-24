#include <bits/stdc++.h>
using namespace std;
using ll = long long;
struct dta {
    int w, s, l;
    bool operator!=(const dta& b) const {
        return (w != b.w) || (s != b.s) || (l != b.l);
    }
};
int ans = 0, cnt;
dta arr[10], dfar[10];

void dfs(int a, int b) {
    if (ans) return;
    if (b > 5) {
        if (b < a || a > 5) return;
        return dfs(a + 1, a + 1);
    }
    if (a == b && a == 5) {
        int ck = 0;
        for (int i = 0; i < 6; i++) {
            // cout << (arr[i] != dfar[i]) << '\n';
            if (ck) break;
            if (arr[i] != dfar[i]) ck = 1;
        }
        if (!ck) ans = 1;
        return;
    }
    if (a == b) return dfs(a, b + 1);
    dfar[a].w += 1;
    dfar[b].l += 1;
    dfs(a, b + 1);
    dfar[a].w -= 1;
    dfar[a].l += 1;
    dfar[b].w += 1;
    dfar[b].l -= 1;
    dfs(a, b + 1);
    dfar[a].l -= 1;
    dfar[b].w -= 1;
    dfar[a].s += 1;
    dfar[b].s += 1;
    dfs(a, b + 1);
    dfar[a].s -= 1;
    dfar[b].s -= 1;
    return;
}

int main() {
    // cin.tie(0)->sync_with_stdio();
    int n = 4;
    while (n--) {
        ans = 0;
        for (int i = 0; i < 6; i++) {
            cin >> arr[i].w >> arr[i].s >> arr[i].l;
        }
        dfs(0, 1);
        cout << ans << ' ';
    }
}