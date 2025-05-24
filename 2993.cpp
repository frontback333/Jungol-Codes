// D[i]=i번째 날까지 숙박 가능한 최소 비용
// D[i]=min(D[i-1]+10000,D[i-3]+25000,D[i-5]+37000)
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int N, M;
int arr[105];
int D[105][25];

void resort(int idx, int price, int coupon) {
    if (idx > N + 1) return;
    if (D[idx - 1][coupon] && D[idx - 1][coupon] <= price) return;
    if (arr[idx]) return resort(idx + 1, price, coupon);
    D[idx - 1][coupon] = price;
    // cout << idx << ' ' << D[idx - 1][coupon] << '\n';
    resort(idx + 1, price + 10000, coupon);
    resort(idx + 3, price + 25000, coupon + 1);
    resort(idx + 5, price + 37000, coupon + 2);
    if (coupon >= 3) resort(idx + 1, price, coupon - 3);
    return;
}

int main() {
    cin.tie(0)->sync_with_stdio();
    cin >> N >> M;
    while (M--) {
        int tmp;
        cin >> tmp;
        arr[tmp] = 1;
    }
    resort(1, 0, 0);
    int mn = 2e8;
    for (int i = 0; i < 22; i++)
        if (D[N][i] && D[N][i] < mn) mn = D[N][i];
    if (mn >= (int)2e8) mn = 0;
    cout << mn;
}