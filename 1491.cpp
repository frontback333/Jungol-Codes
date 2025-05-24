#include <bits/stdc++.h>
using namespace std;
using ll = long long;
struct dta {
    ll tim, lst;
    bool operator<(const dta& b) const {
        return tim < b.tim;
    }
};
ll N, MD;
ll dist[120], fixt[120];
dta D[120];
vector<ll> arr;

void mt() {
    for (int idx = 1; idx <= N + 1; ++idx) {
        int cnt = 0, j = idx;
        D[idx].tim = 1LL << 32;
        while (j >= 0 && dist[idx] - dist[j] <= MD) {
            D[idx] = min(D[idx], dta{D[j].tim + fixt[j], j});
            j--;
        }
    }
    return;
}

int main() {
    // cin.tie(0)->sync_with_stdio();
    cin >> MD >> N;
    for (int i = 1; i <= N + 1; i++) {
        cin >> dist[i];
        dist[i] += dist[i - 1];
    }
    for (int i = 1; i <= N; i++) {
        cin >> fixt[i];
    }
    mt();
    cout << D[N + 1].tim << '\n';
    ll k = N + 1;
    while (D[k].lst) {
        arr.push_back(D[k].lst);
        k = D[k].lst;
    }
    if (!arr.empty()) {
        reverse(arr.begin(), arr.end());
        cout << arr.size() << '\n';
        for (int i : arr) cout << i << ' ';
    }
}