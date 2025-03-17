#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int N, Q, mx = 0;
int scores[500005], zipscore[500005], arr[500005];

void upd(int now, const int& val) {
    do
        arr[now] += val;
    while ((now += now & -now) <= N);
    return;
}

int query(int e) {
    int s = 0;
    while (e > 0) {
        s += arr[e];
        e -= e & -e;
    }
    return s;
}

int main() {
    cin.tie(0)->sync_with_stdio();
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> scores[i];
        zipscore[i] = scores[i];
    }
    sort(zipscore + 1, zipscore + N + 1);
    for (int i = 1; i <= N; i++) {
        int targ = lower_bound(zipscore + 1, zipscore + 1 + N, scores[i]) - zipscore;
        // cout << targ << ' ';
        upd(targ, 1);
        if (mx < targ) mx = targ;
        int br = query(mx) - query(targ) + 1;
        cout << br << '\n';
    }
}