#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll N, d = 0, cnt;
ll Cds[505], Tds[505];
vector<ll> cnts;

int main() {
    ios_base::sync_with_stdio(0);
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> Cds[i];
    }
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            cnt = 0;
            d = (Cds[j] - Cds[i]) / (j - i);
            Tds[i] = Cds[i];
            Tds[j] = Cds[j];
            for (int k = i + 1; k < N; k++) {
                Tds[k] = Tds[k - 1] + d;
                if (Tds[k] != Cds[k]) cnt++;
            }
            for (int k = i - 1; k >= 0; k--) {
                Tds[k] = Tds[k + 1] - d;
                if (Tds[k] != Cds[k]) cnt++;
            }
            cnts.push_back(cnt);
        }
    }
    sort(cnts.begin(), cnts.end());
    cout << cnts[0];
}
