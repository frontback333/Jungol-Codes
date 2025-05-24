#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int N, M;
int students[50005];
map<int, int> mp;

void resetgroup() {
    for (int i = 1; i <= N; i++) students[i] = i;
}

int findP(int t) {
    if (students[t] != t) students[t] = findP(students[t]);
    return students[t];
}

void UnionS(int x, int y) {
    int xp = findP(x), yp = findP(y);
    if (xp == yp)
        return;
    students[yp] = xp;
}

int main() {
    cin.tie(0)->sync_with_stdio();
    cin >> N >> M;
    resetgroup();
    while (M--) {
        int s, e;
        cin >> s >> e;
        UnionS(s, e);
    }
    for (int i = 1; i <= N; i++) {
        findP(i);
        mp[students[i]] = 1;
    }
    cout << mp.size();
}