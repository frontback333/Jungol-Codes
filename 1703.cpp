// D(l,r) = l-r최대 악수
// D(l,r) = max( D(l+1,r-1) + 1 , D(l,k) + D(k,r) )
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
struct Dta {
    int len, height;
    bool operator<(const Dta& b) const {
        return len + 2 * height < b.len + 2 * b.height;
    }
    Dta operator+(const Dta& b) const {
        return {len + b.len, max(height, b.height)};
    }
};
int N;
string S;
Dta D[105][105];
int tck[105][105];
vector<pair<int, int>> arr;

Dta getlen(int s, int e) {
    if (s >= e) return D[s][e] = {0, 0};
    if (D[s][e].len >= 0) return D[s][e];
    Dta mn = {(int)2e8, (int)2e8};
    if (S[s] != S[e]) {
        mn = getlen(s + 1, e - 1);
        mn.height += 1;
        mn.len += e - s + (mn.height * 2);
        tck[s][e] = -1;
    }
    for (int k = s + 1; k < e - 1; k += 2) {
        Dta tmp = getlen(s, k) + getlen(k + 1, e);
        if (tmp < mn) {
            mn = tmp;
            tck[s][e] = k;
        }
    }
    return D[s][e] = mn;
}

void btck(int s, int e) {
    if (s >= e) return;
    if (tck[s][e] < 0) {
        cout << s + 1 << ' ' << e + 1 << '\n';
        btck(s + 1, e - 1);
        return;
    }
    btck(s, tck[s][e]);
    btck(tck[s][e] + 1, e);
    return;
}

int main() {
    cin.tie(0)->sync_with_stdio();
    cin >> N >> S;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) D[i][j].len = -1;
    }
    getlen(0, N - 1);
    cout << D[0][N - 1].len << '\n';
    btck(0, N - 1);
}