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
        else {
            if (s.find(x) != s.end()) {
                if (s.size() == 1)
                    cout << "UNIQUE\n";
                else {
                    int a = s.find(x) == s.begin() ? 1e8 : *prev(s.find(x));
                    int b = s.find(x) == prev(s.end()) ? 1e8 : *next(s.find(x));
                    if (abs(x - a) > abs(x - b))
                        cout << b << '\n';
                    else
                        cout << a << '\n';
                }
            } else {
                cout << "NOPE\n";
            }
        }
    }
}