#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll n;
struct pb {
    int a, b, c, d;
    pb operator*(const pb _T) {
        return {(a * _T.a + b * _T.c) % 10000, (a * _T.b + b * _T.d) % 10000, (c * _T.a + d * _T.c) % 10000, (c * _T.b + d * _T.d) % 10000};
    }
};

pb pibo(int pn) {
    if (pn == 1)
        return {1, 1, 1, 0};
    pb trg = pibo(pn / 2);
    if (pn & 1)
        return trg * trg * pibo(1);
    else
        return trg * trg;
}

int main() {
    cin.tie(0)->sync_with_stdio();
    while (true) {
        cin >> n;
        if (n < 0)
            break;
        else if (n == 0)
            cout << 0 << '\n';
        else
            cout << pibo(n).b << '\n';
    }
}