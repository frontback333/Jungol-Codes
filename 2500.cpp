#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ln '\n';
int N, K;
int arr[205], D[205][205][2];

int binS(int s, int e) {
    if (s == e) {
        D[s][e][0] = 0;
        D[s][e][1] = 1 << arr[s];
        return D[s][e][1];
    }
    if (D[s][e][1]) return D[s][e][1];
    D[s][e][0] = 1e8;
    for (int m = s; m < e; m++) {
        int color = D[s][m][1] & D[m + 1][e][1];
        int count = D[s][m][0] + D[m + 1][e][0] + !color;
        if (!color) color = D[s][m][1] | D[m + 1][e][1];
        if (count < D[s][e][0]) {
            D[s][e][0] = count;
            D[s][e][1] = color;
        } else if (count == D[s][e][0]) {
            D[s][e][1] |= color;
        }
    }
    return D[s][e][1];
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> N >> K;
    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
    }
    binS(1, N);
    cout << D[1][N][0];
}