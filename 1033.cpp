#include <bits/stdc++.h>
using namespace std;
using ll = long long;
struct loc {
    int x, y, price, lastidx;
};
int n, k, sy, sx, ey, ex, head, tail, ans = 1e9, ansidx, cnt;
int arr[55][55], checkarr[55][55];
int X[6] = {-1, 1, 0, 0}, Y[6] = {0, 0, -1, 1};
loc que[2505];

void q_push(int y, int x, int price, int lastidx) {
    if (y > n || x > n || x < 1 || y < 1 || checkarr[y][x] <= price) return;
    checkarr[y][x] = price;
    int addp = arr[y][x] ? k : 1;
    que[tail] = {x, y, price + addp, lastidx};
    if (y == ey && x == ex) {
        cout << y << ' ' << x << ' ' << price + addp << '\n';
        ans = price + addp;
        ansidx = tail;
        return;
    }
    tail++;
    return;
}

void bfs() {
    q_push(sy, sx, 0, 0);
    while (head < tail) {
        auto [x, y, price, idx] = que[head++];
        for (int i = 0; i < 4; i++) {
            q_push(y + Y[i], x + X[i], price, head);
        }
    }
    cout << ans << '\n';
    return;
}

int main() {
    cin.tie(0)->sync_with_stdio();
    int tmp;
    cin >> n >> sy >> sx >> ey >> ex >> k >> tmp;
    for (int i = 0; i < 52; i++) {
        for (int j = 0; j < 52; j++) {
            checkarr[i][j] = 1e9;
        }
    }
    while (tmp--) {
        int turns, x, y, lastx = 0, lasty = 0;
        cin >> turns;
        while (turns--) {
            cin >> y >> x;
            arr[y][x] = 1;
            if (lastx && lasty) {
                if (lastx == x) {
                    for (int i = min(lasty, y); i < max(lasty, y); i++) {
                        arr[i][x] = 1;
                    }
                } else {
                    for (int i = min(lastx, x); i < max(lastx, x); i++) {
                        arr[y][i] = 1;
                    }
                }
            }
            lastx = x;
            lasty = y;
        }
    }
    bfs();

    int chck = ansidx;
    vector<pair<int, int>> points;
    while (chck > 0) {
        points.push_back({que[chck].y, que[chck].x});
        cout << que[chck].y << ' ' << que[chck].x << '\n';
        chck = que[chck].lastidx;
    }
    for (int i = 1; i < points.size() - 1; i++) {
        if (points[i].first == points[i + 1].first && points[i].second == points[i - 1].second)
            cnt++;
        else if (points[i - 1].first == points[i].first && points[i].second == points[i + 1].second)
            cnt++;
    }
    cout << cnt << ' ';
    for (int i = 1; i < points.size() - 1; i++) {
        if (points[i].first == points[i + 1].first && points[i].second == points[i - 1].second)
            cout << points[i].first << ' ' << points[i].second << ' ';
        else if (points[i - 1].first == points[i].first && points[i].second == points[i + 1].second)
            cout << points[i].first << ' ' << points[i].second << ' ';
    }
}