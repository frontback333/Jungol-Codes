#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int N, K, r, a, b, c, tmp;
struct dta {
    int parent, edge;  // 위쪽엣지
};
dta tre[1000005];
int check[1000005];

int getRoot(int p, int q) {
    int chc = 0;
    while (p && chc < 1005) {
        check[p] = K + 1;
        chc++;
        p = tre[p].parent;
    }
    while (check[q] != K + 1) {
        check[q] = K + 1;
        q = tre[q].parent;
    }
    return q;
}

int main() {
    cin.tie(0)->sync_with_stdio();
    cin >> N >> K;
    for (int i = 0; i < N; i++) {
        tre[i + 1].parent = 0;
    }
    while (K--) {
        cin >> r;
        if (r == 1) {
            cin >> a >> b >> c;
            tmp = getRoot(a, b);
            while (a != tmp) {
                tre[a].edge = c;
                a = tre[a].parent;
            }
            while (b != tmp) {
                tre[b].edge = c;
                b = tre[b].parent;
            }
        } else if (r == 2) {
            cin >> a >> b;
            tre[a].parent = b;
        } else {
            cin >> a >> b;
            tmp = getRoot(a, b);
            map<int, int> cnt;
            while (a != tmp) {
                cnt[tre[a].edge]++;
                a = tre[a].parent;
            }
            while (b != tmp) {
                cnt[tre[b].edge]++;
                b = tre[b].parent;
            }
            cout << cnt.size() << '\n';
        }
    }
}