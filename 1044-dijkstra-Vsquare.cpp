#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int N, M;
int arr[105][105];
int path[105], vis[105], dist[105];

void dijkstra(int source) {
    for (int i = 1; i <= N; i++) dist[i] = 2e9;
    dist[source] = 0;
    for (int i = 1; i <= N; i++) {
        int minNode, minVal = 2e9;
        for (int j = 1; j <= N; j++) {
            if (!vis[j] && minVal > dist[j]) {
                minNode = j;
                minVal = dist[j];
            }
        }
        vis[minNode] = 1;
        for (int j = 1; j <= N; j++) {
            if (dist[j] > minVal + arr[minNode][j]) {
                dist[j] = minVal + arr[minNode][j];
                path[j] = minNode;
            }
        }
    }
    return;
}

int main() {
    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> arr[i][j];
            // path[i][j] = i;
        }
    }
    dijkstra(1);
    cout << dist[M] << '\n';
    vector<int> trc;
    while (M > 0) {
        trc.push_back(M);
        M = path[M];
    }
    reverse(trc.begin(), trc.end());
    for (int i : trc) {
        cout << i << ' ';
    }
}