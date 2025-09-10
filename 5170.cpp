#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll N, M, mx;
ll arr[1000005];

ll minPar(ll s, ll e) {
    if (e < s) return e;
    ll m = s + e >> 1;
    ll sum = 0;
    for (int i = 0; i < N; i++) {
        if (arr[i] - m > 0) sum += arr[i] - m;
    }
    if (sum >= M)
        return minPar(m + 1, e);
    else
        return minPar(s, m - 1);
}

int main() {
    cin.tie(0)->sync_with_stdio();
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
        if (arr[i] > mx) mx = arr[i];
    }
    sort(arr, arr + N);
    cout << minPar(0, mx);
}