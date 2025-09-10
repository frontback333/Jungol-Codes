#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int orsz, sz, ans;
string ord, A[2];
int D[25][105][5];  // D[i][j][k], i = A혹은B , j = 인덱스, k = 몇번째 ord

int doD(int i, int j, int k) {
    if (!i) return 1;
    if (!j) return 0;
    if (D[i][j][k] >= 0) return D[i][j][k];
    if (ord[i] != A[k][j]) return D[i][j][k] = doD(i, j - 1, k);
    return D[i][j][k] = doD(i, j - 1, k) + doD(i - 1, j - 1, k ^ 1);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> ord >> A[0] >> A[1];
    orsz = ord.size();
    sz = A[0].size();
    ord = " " + ord;
    A[0] = " " + A[0];
    A[1] = " " + A[1];
    for (int i = 0; i <= orsz; i++) {
        for (int j = 0; j <= sz; j++) {
            for (int k = 0; k < 2; k++) D[i][j][k] = -1;
        }
    }
    cout << doD(orsz, sz, 0) + doD(orsz, sz, 1);
}