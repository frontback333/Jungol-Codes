#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll cnt;
set<ll> ugly;
vector<ll> uglyarr;

int main() {
    cin.tie(0)->sync_with_stdio();
    ugly.insert(1);
    while (cnt < 1500) {
        ll x = *ugly.begin();
        ugly.insert(x * 2);
        ugly.insert(x * 3);
        ugly.insert(x * 5);
        uglyarr.push_back(*ugly.begin());
        ugly.erase(ugly.begin());
        cnt++;
    }

    ll n = 1;
    while (n) {
        cin >> n;
        if (!n) break;
        cout << uglyarr[n - 1] << '\n';
    }
}