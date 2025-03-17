#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll N, a, b, mid;
priority_queue<int> sballs;
priority_queue<int, vector<int>, greater<int>> bballs;

int main() {
    cin.tie(0)->sync_with_stdio();
    cin >> N >> a;
    mid = a;
    cout << mid << '\n';
    for (ll i = 0; i < (N - 1) / 2; i++) {
        cin >> a >> b;
        if (a > b) swap(a, b);
        if (b < mid) {
            bballs.push(mid);
            sballs.push(a);
            sballs.push(b);
            mid = sballs.top();
            sballs.pop();
        } else if (a > mid) {
            sballs.push(mid);
            bballs.push(b);
            bballs.push(a);
            mid = bballs.top();
            bballs.pop();
        } else {
            sballs.push(a);
            bballs.push(b);
        }
        cout << mid << '\n';
    }
}