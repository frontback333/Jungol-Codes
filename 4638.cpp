#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll Q, it;
set<ll> s;

int main() {
    cin.tie(0)->sync_with_stdio();
    cin >> Q;
    while (Q--) {
        char a;
        int x;
        cin >> a >> x;
        if (a == 'i')
            s.insert(x);
        else
            s.erase(x);
    }
    cin >> it;
    int c = 0;
    for (auto i : s) {
        c++;
        if (c == it) cout << i << ' ';
    }
    if (c < it) cout << "OVER";
}