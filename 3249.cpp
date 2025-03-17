#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll N, step;
char arr[1200][1200];
string Dta;

void recover(int x, int y, int sze) {
    if (step >= Dta.size()) return;
    if (Dta[step] == 'X') {
        step++;
        recover(x, y, sze / 2);
        recover(x, y + (sze / 2), sze / 2);
        recover(x + (sze / 2), y, sze / 2);
        recover(x + (sze / 2), y + (sze / 2), sze / 2);
    } else {
        for (int i = x; i < x + sze; i++) {
            for (int j = y; j < y + sze; j++) {
                arr[i][j] = Dta[step];
            }
        }
        step++;
    }
    return;
}

int main() {
    cin.tie(0)->sync_with_stdio();
    cin >> N >> Dta;
    recover(0, 0, N);
    cout << N << '\n';
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << arr[i][j] << ' ';
        }
        cout << '\n';
    }
}