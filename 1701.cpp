// D(l,r) = l~r사이 최대 길이
// D(l,r) = max( D(l+1,r-1) + 2 , D(l,k) + D(k,r) )
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
string S;
int DP[505][505];

int GML(int l, int r) {
    if (l == r) return DP[l][r] = 0;
    if (DP[l][r] >= 0) return DP[l][r];
    int mx = 0;
    if ((S[l] == 'a' && S[r] == 't') || (S[l] == 'g' && S[r] == 'c')) {
        mx = GML(l + 1, r - 1) + 2;
    }
    for (int k = l; k < r; k++) {
        mx = max(mx, GML(l, k) + GML(k + 1, r));
    }
    return DP[l][r] = mx;
}

int main() {
    cin.tie(0)->sync_with_stdio();
    cin >> S;
    for (int i = 0; i <= 500; i++) {
        for (int j = 0; j <= 500; j++) DP[i][j] = -1;
    }
    cout << GML(0, S.size() - 1);
}