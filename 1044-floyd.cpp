#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int N, M;
int arr[105][105];
int path[105][105];

void FloydWarshell() {
    for (int k = 1; k <= N; k++) {
        for (int a = 1; a <= N; a++) {
            for (int b = 1; b <= N; b++) {
                if (arr[a][b] > arr[a][k] + arr[k][b]) {
                    arr[a][b] = arr[a][k] + arr[k][b];
                    path[a][b] = k;
                }
            }
        }
    }
}

void track(int s, int e) {
    // cout<<s<<' '<<e<<'\n';
    if (s == path[s][e]) {
        cout << s << ' ';
        return;
    }
    track(s, path[s][e]);
    track(path[s][e], e);
    return;
}

int main() {
    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> arr[i][j];
            path[i][j] = i;
        }
    }
    FloydWarshell();
    cout << arr[1][M] << '\n';
    track(1, M);
    cout << M;
}