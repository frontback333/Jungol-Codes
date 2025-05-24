#include <bits/stdc++.h>
using namespace std;
using ll = long long;
struct dta {
    int cnt, i, k;
};
int ans = 8;
int arr[6][6];
vector<dta> stk, dt;

void hormove(int co) {
    int tmp = arr[co][4];
    for (int i = 4; i > 1; i--) {
        arr[co][i] = arr[co][i - 1];
    }
    arr[co][1] = tmp;
}

void vermove(int ro) {
    int tmp = arr[4][ro];
    for (int i = 4; i > 1; i--) {
        arr[i][ro] = arr[i - 1][ro];
    }
    arr[1][ro] = tmp;
}

int mnmv() {
    int ck = 0;
    for (int i = 1; i <= 4; i++) {
        for (int j = 1; j <= 4; j++) {
            if (arr[i][j] != (4 * (i - 1)) + j) ck++;
        }
    }
    return (ck + 3) / 4;
}

void dfs(int cnt) {
    int mm = mnmv();
    // cout << cnt << ' ' << mm << '\n';
    if (cnt + mm >= ans) return;
    if (!mm) {
        ans = cnt;
        dt = stk;
        return;
    }
    for (int i = 1; i <= 4; i++) {
        for (int k = 0; k < 3; k++) {
            hormove(i);
            stk.push_back({1, i, k + 1});
            dfs(cnt + 1);
            stk.pop_back();
        }
        hormove(i);
        for (int k = 0; k < 3; k++) {
            vermove(i);
            stk.push_back({2, i, k + 1});
            dfs(cnt + 1);
            stk.pop_back();
        }
        vermove(i);
    }
    return;
}

int main() {
    // cin.tie(0)->sync_with_stdio();
    for (int i = 1; i <= 4; i++) {
        for (int j = 1; j <= 4; j++) {
            cin >> arr[i][j];
        }
    }
    dfs(0);
    cout << ans << '\n';
    for (auto [c, i, k] : dt) {
        cout << c << ' ' << i << ' ' << k << '\n';
    }
}