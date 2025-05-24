#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int N, S;
int arr[50005], prs[50005];
int D[5][50005];

void DF() {
    for (int i = 1; i < 4; i++) {
        for (int j = 1 + (S * (i - 1)); j <= N; j++) {
            D[i][j] = max(D[i - 1][j], D[i][j - 1]);
            if (i > 1) D[i][j] = max(D[i][j], D[i - 1][j - S] + D[0][j]);
        }
    }
}

int main() {
    // cin.tie(0)->sync_with_stdio();
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
        prs[i] = arr[i] + prs[i - 1];
    }
    cin >> S;
    for (int i = 1; i <= N - S + 1; i++) {
        D[0][i] = prs[i + S - 1] - prs[i - 1];
    }
    DF();
    cout << D[3][N];
}