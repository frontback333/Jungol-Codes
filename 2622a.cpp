#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ln '\n'
string A, B;
ll ck, ans, D[2][200005];
map<ll, ll> AD, BD;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> A >> B;
    A = ' ' + A;
    B = ' ' + B;
    for (ll i = 1; i < A.size(); i++) {
        if (A[i] == '(')
            D[0][i] = D[0][i - 1] + 1;
        else
            D[0][i] = D[0][i - 1] - 1;
        if (D[0][i] < 0) ck = 1;
        if (ck)
            D[0][i] = -1;
        else
            AD[D[0][i]]++;
    }
    ck = 0;
    for (ll i = 1; i < B.size(); i++) {
        if (B[i] == '(') {
            D[1][i] = D[1][i - 1] + 1;
            ck++;
        } else {
            D[1][i] = D[1][i - 1] - 1;
            if (ck > 0) ck--;
        }
        if (!ck)
            BD[D[1][i]]++;
    }
    for (ll i = 1; i < A.size(); i++)
        if (D[0][i] >= 0) ans += BD[-D[0][i]];
    cout << ans;
}