#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ln '\n'
int N, ans = 1e8;
int loc[2005][2005], D[2005][2005];
vector<pair<int, int>> ipt;
vector<int> xcomp, ycomp;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> N;
    for (int i = 0; i < N; i++) {
        int x, y;
        cin >> x >> y;
        ipt.push_back({x, y});
        xcomp.push_back(x);
        ycomp.push_back(y);
    }
    xcomp.push_back(2);
    ycomp.push_back(2);
    sort(xcomp.begin(), xcomp.end());
    sort(ycomp.begin(), ycomp.end());
    sort(ipt.begin(), ipt.end());
    xcomp.erase(unique(xcomp.begin(), xcomp.end()), xcomp.end());
    ycomp.erase(unique(ycomp.begin(), ycomp.end()), ycomp.end());
    for (int i = 0; i < N; i++) {
        int x = lower_bound(xcomp.begin(), xcomp.end(), ipt[i].first) - xcomp.begin();
        int y = lower_bound(ycomp.begin(), ycomp.end(), ipt[i].second) - ycomp.begin();
        loc[y][x] = 1;
    }
    for (int i = 1; i < ycomp.size(); i++) {
        int c = 0;
        for (int j = 1; j < xcomp.size(); j++) {
            if (loc[i][j]) c++;
            D[i][j] = D[i - 1][j] + c;
        }
    }
    for (int i = 0; i < xcomp.size(); i++) {
        int l = D[ycomp.size() - 1][i], r = D[ycomp.size() - 1][xcomp.size() - 1] - D[N][i];
        for (int j = 0; j <= N; j++) {
            int lt = D[j][i], rt = D[j][xcomp.size() - 1] - D[j][i];
            // cout << l << ' ' << lt << ' ' << r << ' ' << rt << ln;
            ans = min(ans, max({lt, rt, l - lt, r - rt}));
        }
    }
    cout << ans;
}