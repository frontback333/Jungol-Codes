#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ln '\n';
int N, ml, mx, stt;
int A[500005], D[500005], lst[500005], ans[500005];
vector<int> track, xt;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> N;
    for (int i = 0; i < N; i++) {
        int a, b;
        cin >> a >> b;
        A[a] = b;
        ml = max({ml, a, b});
    }
    for (int i = 1; i <= ml; i++) {
        if (!A[i]) {
            lst[i] = i;
            continue;
        }
        if (track.empty() && A[i]) {
            track.push_back(A[i]);
            xt.push_back(i);
        }
        auto idx = lower_bound(track.begin(), track.end(), A[i]) - track.begin();
        if (idx >= track.size()) {
            track.push_back(A[i]);
            xt.push_back(i);
        } else {
            track[idx] = A[i];
            xt[idx] = i;
        }
        if (idx) lst[i] = xt[idx - 1];
        D[i] = track.size();
        if (D[i] > mx) {
            mx = D[i];
            stt = i;
        }
    }
    for (int i = 1; i <= ml; i++)
        if (!A[i]) ans[i] = 1;
    cout << N - D[ml] << ln;
    while (stt) {
        ans[stt] = 1;
        stt = xt[stt];
    }
    for (int i = 1; i <= ml; i++)
        if (!ans[i]) cout << i << ln;
}