#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    cin.tie(0)->sync_with_stdio();
    char arr[26];
    for (ll i = 0; i < 26; i++) {
        arr[i] = i + 65;
    }
    for (char e : arr) {
        cout << e << ' ';
    }
}
