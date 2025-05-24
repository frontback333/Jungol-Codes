#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int N, M;
int horprefix[7][15], verprefix[7][15];
char arr[7][15];

void dfs(int ck, int ro, int cnt) {
}

int main() {
    // cin.tie(0)->sync_with_stdio();
    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            cin >> arr[i][j];
            if (arr[i][j] == '*') {
                verprefix[i][j] = verprefix[i - 1][j] + 1;
                horprefix[i][j] = horprefix[i][j - 1] + 1;
            }
        }
    }
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            cout << verprefix[i][j];
        }
        cout << '\n';
    }
    cout << '\n';
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            cout << horprefix[i][j];
        }
        cout << '\n';
    }
}