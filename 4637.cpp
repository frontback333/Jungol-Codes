#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll Q, tmp;
char typ;
set<ll> st;

int main() {
    cin.tie(0)->sync_with_stdio();
    cin >> Q;
    while (Q--) {
        cin >> typ >> tmp;
        if (typ == 'i')
            st.insert(tmp);
        else
            st.erase(tmp);
    }
    for (ll e : st) {
        cout << e << ' ';
    }
}