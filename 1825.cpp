#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll P, N;
ll gain[25][305], D[25][305], ans[25][305];

void doD(ll row) {
    if (row > N) return;
    for (int i = 1; i <= P; i++) {
        for (int j = 0; j <= i; j++) {
            if (D[row - 1][j] + gain[row][i - j] > D[row][i]) {
                D[row][i] = D[row - 1][j] + gain[row][i - j];
                ans[row][i] = i - j;
            }
        }
    }
    doD(row + 1);
}

int main() {
    cin >> P >> N;
    for (int i = 1; i <= P; i++) {
        int tmp;
        cin >> tmp;
        for (int j = 1; j <= N; j++) {
            cin >> gain[j][tmp];
        }
    }
    vector<int> ct;
    doD(1);
    cout << D[N][P] << '\n';
    for (int i = N; i > 0; i--) {
        ct.push_back(ans[i][P]);
        P -= ans[i][P];
    }
    reverse(ct.begin(), ct.end());
    for (int i : ct) cout << i << ' ';
}