#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int N, S;
int D[300005];
map<int, int> mp;
vector<pair<int, int>> arr(1);
int j = 1;
void dp(int idx) {
    if (idx > N) return;

    while ((arr[idx].first - arr[j].first) >= S) j++;
    j--;

    D[idx] = max(D[j] + arr[idx].second, D[idx - 1]);
    dp(idx + 1);
    return;
}

int main() {
    cin.tie(0)->sync_with_stdio();
    cin >> N >> S;
    for (int i = 0; i < N; i++) {
        int h, c;
        cin >> h >> c;
        if (mp[h] < c) mp[h] = c;
    }
    for (pair<int, int> i : mp) {
        arr.push_back({i.first, i.second});
    }
    N = arr.size() - 1;
    dp(1);
    cout << D[N];
}