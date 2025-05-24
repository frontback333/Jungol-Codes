#include <bits/stdc++.h>
using namespace std;
using ll = long long;
struct piece {
    int cnt;
    vector<pair<int, int>> children;
};
int N, M;
int basic[105];
queue<int> q;
piece arr[105];

void Topology() {
    while (!q.empty()) {
        int cn = q.front();
        for (pair<int, int> i : arr[cn].children) {
            arr[i.first].cnt += arr[cn].cnt * i.second;
            q.push(i.first);
        }
        q.pop();
    }
}

int main() {
    // cin.tie(0)->sync_with_stdio();
    cin >> N >> M;
    while (M--) {
        int X, Y, K;
        cin >> X >> Y >> K;
        arr[X].children.push_back({Y, K});
        basic[X] = 1;
    }
    q.push(N);
    arr[N].cnt = 1;
    Topology();
    for (int i = 1; i <= N; i++) {
        if (!basic[i]) {
            cout << i << ' ' << arr[i].cnt << '\n';
        }
    }
}