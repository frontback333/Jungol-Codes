// D[i] = B ���� i ���� ������ ���� �κ� ���� ����
// D[i] = i ���� ���� �ִ�k �� D[k] + 1
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll N, ans, lstidx;
ll mp[10005], switches[10005], D[10005], lst[10005];
vector<ll> ct;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> N;
    for (int i = 1; i <= N; i++) cin >> switches[i];
    for (int i = 1; i <= N; i++) {
        ll a;
        cin >> a;
        mp[a] = i;
        D[i] = 1;
    }
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j < i; j++) {
            if (mp[switches[i]] > mp[switches[j]] && D[i] <= D[j] + 1) {
                lst[i] = j;
                D[i] = D[j] + 1;
            }
        }
    }
    for (int i = 1; i <= N; i++) {
        if (ans < D[i]) {
            ans = D[i];
            lstidx = i;
        }
    }
    cout << ans << '\n';
    while (lstidx) {
        ct.push_back(switches[lstidx]);
        lstidx = lst[lstidx];
    }
    sort(ct.begin(), ct.end());
    for (auto i : ct) cout << i << ' ';
}
