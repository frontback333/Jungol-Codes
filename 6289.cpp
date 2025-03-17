#include <bits/stdc++.h>
using namespace std;
using ll = long long;
struct box {
    ll weight, targ;
};
ll N, M, tmp;
ll seg[1500005];
box stuff[150005];

void upd(int now, int s, int e, int idx, int val) {
    if (s == e) {
        seg[now] += val;
        return;
    }
    int lseg = now * 2, mid = (s + e) / 2;
    if (idx <= mid)
        upd(lseg, s, mid, idx, val);
    else
        upd(lseg + 1, mid + 1, e, idx, val);
    seg[now] = max(seg[lseg], seg[lseg + 1]);
    return;
}

void boxadd(int now, int s, int e, box& b) {
    if (s == e) {
        b.targ = s;
        upd(1, 1, N, s, -b.weight);
        return;
    }
    int lseg = now * 2, mid = (s + e) / 2;
    if (seg[lseg] >= b.weight)
        boxadd(lseg, s, mid, b);
    else
        boxadd(lseg + 1, mid + 1, e, b);
    return;
}

int main() {
    cin.tie(0)->sync_with_stdio();
    cin >> N >> M;
    for (ll i = 1; i <= N; i++) {
        cin >> tmp;
        upd(1, 1, N, i, tmp);
    }
    for (ll i = 1; i <= M; i++) {
        cin >> stuff[i].weight;
    }
    for (ll i = 1; i <= M; i++) {
        if (seg[1] < stuff[i].weight)
            stuff[i].targ = 0;
        else
            boxadd(1, 1, N, stuff[i]);
    }
    for (ll i = 1; i <= M; i++) {
        cout << stuff[i].targ << ' ';
    }
}