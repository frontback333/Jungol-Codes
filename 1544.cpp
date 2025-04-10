#include <bits/stdc++.h>
using namespace std;
using ll = long long;
struct Dta {
    int num, score;
    bool operator<(const Dta& b) const {
        if (score == b.score) return num < b.num;
        return score < b.score;
    }
};
int N;
int arr[55][55];

void georgefloyd() {
    for (int k = 1; k <= N; k++) {
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                if (arr[i][j] > arr[i][k] + arr[k][j]) {
                    arr[i][j] = arr[i][k] + arr[k][j];
                }
            }
        }
    }
}

int main() {
    cin >> N;
    for (int i = 0; i <= N; i++) {
        for (int j = 0; j <= N; j++) {
            if (i != j) arr[i][j] = 2e8;
        }
    }
    while (1) {
        int s, e;
        cin >> s >> e;
        if (s < 0) break;
        arr[s][e] = 1;
        arr[e][s] = 1;
    }
    georgefloyd();
    vector<Dta> scs(N);
    int mx = 0;
    for (int i = 1; i <= N; i++) {
        scs[i - 1].num = i;
        mx = 0;
        for (int j = 1; j <= N; j++) {
            if (arr[i][j] < 2e8 && arr[i][j] > mx) mx = arr[i][j];
        }
        scs[i - 1].score = mx;
    }
    sort(scs.begin(), scs.end());
    int ans = scs[0].score;
    int cnt = 0;
    for (Dta i : scs) {
        if (i.score == ans) cnt++;
    }
    cout << ans << ' ' << cnt << '\n';
    for (Dta i : scs) {
        if (i.score == ans) cout << i.num << ' ';
    }
}