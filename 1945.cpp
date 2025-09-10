#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ln '\n'
ll N;
map<ll, ll> D;

ll doD(ll num) {
    if (D[num]) return D[num];
    if (num >= N) return D[num] = 2;
    for (int i = 2; i < 10; i++) {
        if (doD(num * i) == 2) return D[num] = 1;
    }
    return D[num] = 2;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    while (cin >> N) {
        D.clear();
        if (doD(1) == 1)
            cout << "Baekjoon wins.\n";
        else
            cout << "Donghyuk wins.\n";
    }
}