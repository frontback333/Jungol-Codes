#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int E, N, sum, cnt;
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
    cin >> E;
    while (E--) {
        int a, b;
        cin >> a >> b;
        arr[a][b] = 1;
        if (a > N) N = a;
        if (b > N) N = b;
    }
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (i != j && !arr[i][j]) arr[i][j] = 2e8;
        }
    }
    georgefloyd();
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (arr[i][j]) {
                sum += arr[i][j];
                cnt++;
            }
        }
    }
    cout << fixed << setprecision(3) << (double)sum / cnt;
}