#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ln '\n'
int N, K, s, ans;
int arr[800005];
multiset<int> st;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> N >> K;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
        st.insert(arr[i]);
        // cout << s << ' ' << i << ' ' << *st.rbegin() << ' ' << *st.begin() << ln;
        while (!st.empty() && (*st.rbegin() - *st.begin()) > K) {
            st.erase(st.find(arr[s]));
            s++;
            // cout << s << ' ' << i << ' ' << (*st.rbegin() - *st.begin()) << ln;
        }
        ans = max(ans, i - s + 1);
    }
    cout << ans;
}