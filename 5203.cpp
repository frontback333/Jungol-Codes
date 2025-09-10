#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ln '\n'
struct dta {
    ll v, p;
    bool operator<(const dta& b) const {
        return p < b.p;
    }
};
ll N;
queue<ll> q[300005];
set<pair<ll, ll>> id, sz;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> N;
    map<ll, ll> mp;
    for (int i = 1; i <= N; i++) {
        ll a;
        cin >> a;
        q[a].push(i);
        mp[a]++;
    }
    for (auto i : mp)
        if (i.first) sz.insert({i.second, i.first});
    for (int i = 1; i <= N; i++) {
        if (q[i].)
    }
}