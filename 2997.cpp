#include <bits/stdc++.h>
using namespace std;
using ll = long long;
struct qipt {
    ll x, c, d;
};
ll N, Q, cnt;
ll curu[200005];
ll dpar[200005];
stack<qipt> stk;
vector<string> ans;

int Find(int idx) {
    if (curu[idx] != idx) curu[idx] = Find(curu[idx]);
    return curu[idx];
}

int main() {
    // cin.tie(0)->sync_with_stdio();
    cin >> N >> Q;
    for (int i = 1; i <= N - 1; i++) {
        cin >> dpar[i + 1];
    }
    for (int i = 0; i < N + Q - 1; i++) {
        ll x, c, d = 0;
        cin >> x;
        if (x)
            cin >> c >> d;
        else
            cin >> c;
        stk.push({x, c, d});
    }
    for (int i = 1; i <= N; i++) curu[i] = i;
    while (!stk.empty()) {
        qipt c = stk.top();
        cnt++;
        if (!c.x) {
            curu[c.c] = Find(dpar[c.c]);
        } else {
            if (Find(c.c) == Find(c.d))
                ans.push_back("YES");
            else
                ans.push_back("NO");
        }
        stk.pop();
    }
    reverse(ans.begin(), ans.end());
    for (string S : ans) cout << S << '\n';
}