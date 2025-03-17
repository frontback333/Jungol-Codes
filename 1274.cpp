#include <bits/stdc++.h>
using namespace std;
using ll = long long;
string N;
int num;

int main() {
    cin.tie(0)->sync_with_stdio();
    cin >> N;
    if (N[0] == '1') {
        cout << '-';
        for (int i = 1; i < 8; i++) {
            if (N[i] == '1')
                N[i] = '0';
            else
                N[i] = '1';
        }
    }
    for (int i = 1; i < 8; i++) {
        N[i] == '1' ? num += (1 << 7 - i) : num;
        // cout << num << '\n';
    }
    N[0] == '1' ? cout << num + 1 : cout << num;
}
