#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll N, Q, v, cnt;
ll arr[500005], sus[500005];

ll binsearch(int s, int e) {
    if (e <= s && arr[s] != v) return 0;
    int m = s + e >> 1;
    if (arr[m] == v) return 1;
    if (arr[m] > v)
        return binsearch(s, m - 1);
    else
        return binsearch(m + 1, e);
}

int main() {
    cin.tie(0)->sync_with_stdio();
    cin >> N >> Q;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    sort(arr, arr + N);
    for (int i = 0; i < Q; i++) {
        cin >> v;
        if (!binsearch(0, N - 1)) {
            cnt++;
            cout << v << ' ';
        }
    }
    if (!cnt) cout << -1;
}