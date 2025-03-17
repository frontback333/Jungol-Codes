#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int N, Ai, Aj;
int mount[105][105], arr[105][105];
int X[6] = {-1, 1, 0, 0}, Y[6] = {0, 0, -1, 1};

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

void getgraph(int a, int b) {
    if (a == 1 || b == 1 || a == N || b == N) {
        arr[a][b] = mount[a][b] * mount[a][b];
        return;
    }
    for (int i = 0; i < 4; i++) {
        if (mount[a][b] < mount[a + X[i]][b + Y[i]]) {
        }
    }
}

int main() {
    cin >> N >> Ai >> Aj;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> mount[i][j];
        }
    }
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            getgraph(i, j);
        }
    }
}