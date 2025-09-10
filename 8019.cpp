#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ln '\n'
struct loc {
    int u, v;
    bool operator<(const loc& b) const {
        return v > b.v;
    }
};
struct dta {
    int v;
    vector<ll> children;
};
ll N, root = 1;
dta tre[300005];
priority_queue<loc> pq;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> N;
    vector<int> ipt;
    for (int i = 2; i <= N; i++) {
        int p;
        cin >> p;
        ipt.push_back(p);
    }
    for (int i = 1; i <= N; i++) {
        int x;
        cin >> x;
        tre[i].v = x;
    }
    int nd = 2;
    for (int i : ipt) {
        pq.push({
            nd,
        });
    }
}