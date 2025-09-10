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
        else if (a == 'r')
            s.erase(x);
        else if (a == 's') {
            if (s.upper_bound(x) != s.begin())
                cout << *prev(s.upper_bound(x)) << '\n';
        } else {
            if (s.lower_bound(x) != s.end()) cout << *s.lower_bound(x) << '\n';
        }
    }
}