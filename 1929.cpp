#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll N, tmp, sum;
priority_queue<ll, vector<ll>, greater<ll>> planks;

int main() {
    cin.tie(0)->sync_with_stdio();
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> tmp;
        planks.push(tmp);
    }
    while (planks.size() > 1) {
        tmp = planks.top();
        planks.pop();
        tmp += planks.top();
        planks.pop();
        sum += tmp;
        planks.push(tmp);
    }
    cout << sum;
}