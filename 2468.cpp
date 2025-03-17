#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll bi, sm, num, tsq, cnt;

int main() {
    // cin.tie(0)->sync_with_stdio();
    cin >> num;
    sm = num;
    while (((sm & 3) != 2) && sm > 0) {
        if (sm & 1) cnt++;
        tsq++;
        sm = sm >> 1;
    }
    sm ? sm = sm ^ 3 : sm;
    while (sm && tsq > 0) {
        sm = sm << 1;
        tsq--;
        if (cnt) {
            sm += 1;
            cnt--;
        }
    }
    sm ? sm : sm = 0;
    bi = num;
    cnt = 0;
    tsq = 0;
    while (((bi & 3) != 1) && bi > 0) {
        if (bi & 1) cnt++;
        tsq++;
        bi = bi >> 1;
    }
    bi = bi ^ 3;
    while (tsq > 0) {
        bi = bi << 1;
        if (tsq == cnt) {
            bi += 1;
            cnt--;
        }
        tsq--;
    }
    cout << sm << ' ' << bi;
}
