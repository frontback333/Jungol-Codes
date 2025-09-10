#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll Z, N, M, ans[1000005], city[1000005];
pair<ll, ll> P[1000005];
set<ll> s;

int main() {
    cin.tie(0)->sync_with_stdio();
    cin >> Z;
    while (Z--) {
        cin >> N >> M;
        s.clear();
        int imp = 0;
        for (int i = 1; i <= N; i++) city[i] = 0;
        for (int i = 1; i <= M; i++) {
            cin >> P[i].first;
            ans[i] = 0;
            P[i].second = city[P[i].first];
            city[P[i].first] = i;
            if (!P[i].first)
                s.insert(i);
            else {
                int lst = P[i].second;
                auto ub = s.upper_bound(lst);
                // cout << i << ' ' << lst << ' ' << ub << '\n';
                if (imp || ub == s.end()) {
                    imp = 1;
                } else {
                    ans[*ub] = P[i].first;
                    s.erase(ub);
                }
            }
        }
        if (!imp) {
            cout << "YES\n";
            for (int i = 1; i <= M; i++)
                if (!P[i].first) cout << ans[i] << ' ';
        } else
            cout << "NO";

        cout << '\n';
    }
}