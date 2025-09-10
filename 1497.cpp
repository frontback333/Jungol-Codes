#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ln '\n'
struct dta {
    ll s, e;
    bool operator<(const dta& b) const {
        return e < b.e;
    }
};
ll N, D[100005];
dta ipt[100005];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> N;
    for (int i = 1; i <= N; i++) cin >> ipt[i].s >> ipt[i].e;
    sort(ipt + 1, ipt + N + 1);
    D[0] = 1;
    for (int i = 1; i <= N; i++) {
        D[i] += D[i - 1];
        int idx = lower_bound(ipt + 1, ipt + N + 1, (dta){0, ipt[i].s}) - (ipt + 1);
        if (idx <= N) D[i] += D[idx];
        D[i] %= 20070713;
    }
    cout << D[N];
}