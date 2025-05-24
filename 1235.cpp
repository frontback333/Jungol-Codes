// D(l,r) = l-r최대 악수
// D(l,r) = max( D(l+1,r-1) + 1 , D(l,k) + D(k,r) )
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int P, ans3;
int arr[1005];
int DP[1005][1005];

int shake(int l, int r) {
    if (l >= r) return DP[l][r] = 0;
    if (DP[l][r] >= 0) return DP[l][r];
    int mx = 0;
    if (arr[l] == arr[r])
        mx = 1 + shake(l + 1, r - 1);
    else
        mx = shake(l + 1, r - 1);
    for (int k = l + 1; k < r; k += 2) {
        mx = max(mx, shake(l, k) + shake(k + 1, r));
    }
    return DP[l][r] = mx;
}

int main() {
    cin.tie(0)->sync_with_stdio();
    cin >> P;
    for (int i = 0; i < P; i++) cin >> arr[i];
    for (int i = 0; i <= 1000; i++) {
        for (int j = 0; j <= 1000; j++) DP[i][j] = -1;
    }
    cout << shake(0, P - 1);
}