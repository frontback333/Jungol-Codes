#include <bits/stdc++.h>
using namespace std;
using ll = long long;
struct newA {
    int ix;
    vector<int> children;
};
int T, N, imp, mtp;
string A, B;
map<char, int> mp;
queue<int> q;
vector<char> ans;
vector<newA> arr(300);

void makeTop() {
    char pre = ' ', nex = ' ';
    for (int i = 0; i < max(A.size(), B.size()); i++) {
        if (i >= A.size() && pre == nex) return;
        if (i >= B.size() && pre == nex) {
            imp = 1;
            return;
        }
        if (A[i] != B[i] && pre == nex) {
            pre = A[i];
            nex = B[i];
        }
        if (i < A.size()) mp[A[i]] = 1;
        if (i < B.size()) mp[B[i]] = 1;
    }
    if (pre == nex) {
        if (A != B) imp = 1;
        return;
    }
    arr[(int)pre].children.push_back((int)nex);
    arr[(int)nex].ix += 1;
    return;
}

void getTop() {
    while (!q.empty()) {
        int idx = q.front();
        if (q.size() > 1) mtp = 1;
        ans.push_back((char)idx);
        for (int i : arr[idx].children) {
            arr[i].ix--;
            if (!arr[i].ix) q.push(i);
        }
        q.pop();
    }
}

int main() {
    // cin.tie(0)->sync_with_stdio();
    cin >> T;
    while (T--) {
        arr.assign(300, {});
        ans.clear();
        mp.clear();
        mtp = 0, imp = 0;
        cin >> N;
        N--;
        cin >> A;
        if (!N) {
            B = A;
            makeTop();
        }
        while (N--) {
            cin >> B;
            makeTop();
            A = B;
        }
        for (int i = 0; i < 300; i++) {
            if (!arr[i].ix && !arr[i].children.empty()) {
                q.push(i);
            }
        }
        getTop();
        int ck = 0;
        for (int i = 0; i < 300; i++)
            if (arr[i].ix) ck = 1;
        if (ck || imp)
            cout << '!' << '\n';
        else if ((mp.size() > 1 && ans.size() < mp.size()) || mtp) {
            cout << '?' << '\n';
        } else {
            for (char i : ans) cout << i;
            if (mp.size() <= 1) {
                for (pair<char, int> i : mp) cout << i.first;
            }
            cout << '\n';
        }
    }
}