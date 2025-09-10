#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ln '\n';
struct dta {
    int s, e, c;
    bool operator<(const dta& b) const {
        return c < b.c;
    }
};
int N, ans;
int U[310];
vector<dta> tre;
priority_queue<dta> pq;

int Find(int idx) {
    return U[idx] = idx == U[idx] ? idx : Find(U[idx]);
}

void kruscal() {
    sort(tre.begin(), tre.end());
    for (auto i : tre) {
        int a = Find(i.s);
        int b = Find(i.e);
        if (a == b) continue;
        ans += i.c;
        U[a] = b;
    }
}

int main() {
    cin >> N;
    for (int i = 1; i <= N; i++) {
        int tmp;
        cin >> tmp;
        tre.push_back({i, N + 1, tmp});
    }
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            int tmp;
            cin >> tmp;
            if (!tmp) continue;
            tre.push_back({i, j, tmp});
        }
    }
    for (int i = 1; i <= N + 1; i++) U[i] = i;
    kruscal();
    cout << ans;
}