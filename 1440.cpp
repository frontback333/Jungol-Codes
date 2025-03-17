#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int N, A, B;
int tre[10005];
int chck[10005];

int main() {
    cin.tie(0)->sync_with_stdio();
    cin >> N;
    for (int i = 0; i < N - 1; i++) {
        cin >> A >> B;
        tre[B] = A;
    }
    cin >> A >> B;
    while (A) {
        chck[A]++;
        A = tre[A];
    }
    while (!chck[B]) {
        chck[B]++;
        B = tre[B];
    }
    cout << B;
}