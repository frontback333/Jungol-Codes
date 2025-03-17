#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll N, sz;
int tre[500005] = {(1 << 31) - 1};

void push(int idx, int val) {
    if (tre[idx / 2] < val) {
        tre[idx] = tre[idx / 2];
        return push(idx / 2, val);
    }
    tre[idx] = val;
}

void pop() {
    swap(tre[sz], tre[1]);
    int i = 1;
    while (i * 2 < sz) {
        int c = i * 2;
        if (c + 1 < sz && tre[c] < tre[c + 1]) c++;
        if (tre[i] >= tre[c]) break;
        swap(tre[i], tre[c]);
        i = c;
    }
    sz--;
    return;
}

int main() {
    cin.tie(0)->sync_with_stdio();
    cin >> N;
    for (int i = 0, x; i < N; i++) {
        cin >> x;
        push(++sz, x);
    }
    for (int i = 1; i <= N; i++) {
        cout << tre[i] << ' ';
    }
    cout << "\n";
    while (sz > 0) {
        pop();
    }
    for (int i = 1; i <= N; i++) {
        cout << tre[i] << ' ';
    }
}
