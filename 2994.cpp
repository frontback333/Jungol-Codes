#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ln '\n';
struct dta {
    int x, yl, yh;
    bool operator<(const dta& b) const {
        if (x == b.x) return yl < b.yl;
        return x < b.x;
    }
};
struct stt {
    int y, dist;
    bool operator<(const stt& b) const {
        return y < b.y;
    }
};
int ex, sy, N, ans, mn = 1e8, cnt;
dta obs[100005];
set<stt> st;
void upd(int y, int dist) {
    auto tg = st.find({y});
    if (tg != st.end() && (*tg).dist > dist) st.erase(tg);
    st.insert({y, dist});
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> N >> sy >> ex;
    ans = ex;
    for (int i = 0; i < N; i++) cin >> obs[i].x >> obs[i].yl >> obs[i].yh;
    sort(obs, obs + N);
    st.insert({sy, 0});
    for (int i = 0; i < N; i++) {
        auto l = st.upper_bound({obs[i].yl});
        auto h = st.upper_bound({obs[i].yh});
        if (h == l) continue;
        int hmin = (int)1e8, lmin = (int)1e8;
        for (auto it = l; it != h; ++it) {
            lmin = min(lmin, (*it).dist + ((*it).y - obs[i].yl));
            hmin = min(hmin, (*it).dist + (obs[i].yh - (*it).y));
        }
        st.erase(l, h);
        upd(obs[i].yh, hmin);
        upd(obs[i].yl, lmin);
    }
    for (auto i : st) mn = min(mn, i.dist);
    ans += mn;
    vector<int> cot;
    for (auto i : st) {
        if (i.dist == mn) {
            cnt++;
            cot.push_back(i.y);
        }
    }
    cout << ans << ln;
    cout << cnt << ' ';
    for (auto i : cot) cout << i << ' ';
}