#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int r, v, cnt, minh, wrc;
int arr[1000005];

bool pos(int sz) {
    int i = 1;
    int used = 0;
    while (i <= v) {
        if (arr[i]) {
            used++;
            i += sz;
        } else
            i++;
    }
    return used <= cnt;
}

int minpar(int s, int e) {
    if (e < s) return s;
    int m = s + e >> 1;
    if (pos(m))
        return minpar(s, m - 1);
    else
        return minpar(m + 1, e);
}

int main() {
    cin.tie(0)->sync_with_stdio();
    cin >> r >> v >> cnt >> wrc;
    for (int i = 0; i < wrc; i++) {
        int a, b;
        cin >> a >> b;
        arr[b] = 1;
        if (a > minh) minh = a;
    }
    cout << minpar(minh, min(r, v));
}