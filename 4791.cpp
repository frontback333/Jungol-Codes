#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int N, M, mn = 0;
ll arr[305], prefix[305];

int minParS(int s, int e) {
    if (e < s) return s;
    int m = s + e >> 1;
    int lst = 0, cnt = 1;
    for (int i = 1; i <= N; i++) {
        if (prefix[i] - prefix[lst] > m) {
            cnt++;
            lst = i - 1;
        }
    }
    if (cnt <= M)
        return minParS(s, m - 1);
    else
        return minParS(m + 1, e);
}

int main() {
    cin.tie(0)->sync_with_stdio();
    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
        prefix[i] = prefix[i - 1] + arr[i];
        if (mn < arr[i]) mn = arr[i];
    }
    int ans = minParS(mn, prefix[N]);
    cout << ans << '\n';
    int lst = 0, cnt = 0;
    for (int i = 1; i <= N; i++) {
        if (prefix[i] - prefix[lst] > ans || M > N - i + 1) {
            lst = i - 1;
            cout << cnt << ' ';
            M--;
            cnt = 0;
        }
        cnt++;
    }
    cout << cnt;
}