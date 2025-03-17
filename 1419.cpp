#include <bits/stdc++.h>
using namespace std;
using ll = long long;
unsigned int num, sum;

int main() {
    cin.tie(0)->sync_with_stdio();
    cin >> num;
    for (int i = 0; i <= 3; i++) {
        sum |= ((num >> i * 8) & 255) << (3 - i) * 8;
    }
    cout << sum;
}
