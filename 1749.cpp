#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int k1, k2, B[5];
int D[555][555];

ll doD(int i, int j) {
    if (D[i][j] >= 0) {
        return D[i][j];
    }
    int ans = 0;
    for (int k = 0; k < 3; k++) {
        if (i - B[k] >= 0) ans |= !doD(i - B[k], j);
        if (j - B[k] >= 0) ans |= !doD(i, j - B[k]);
    }
    return D[i][j] = ans;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    for (int i = 0; i <= 550; i++)
        for (int j = 0; j <= 550; j++) D[i][j] = -1;
    cin >> B[0] >> B[1] >> B[2];
    D[0][0] = 0;
    for (int T = 0; T < 5; T++) {
        cin >> k1 >> k2;
        doD(k1, k2) ? cout << "A\n" : cout << "B\n";
    }
}