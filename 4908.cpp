#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int Q, a;
double b;
string typ;
struct patient {
    string name;
    int age;
    double bleed;
    bool operator<(const patient& _X) const {
        if (bleed == _X.bleed)
            return age < _X.age;
        else
            return bleed < _X.bleed;
    }
};
priority_queue<patient> max_heap;

int main() {
    cin.tie(0)->sync_with_stdio();
    cin >> Q;
    while (Q--) {
        cin >> typ;
        if (typ == "push") {
            cin >> typ >> a >> b;
            max_heap.push({typ, a, b});
        } else {
            if (max_heap.size()) {
                cout << max_heap.top().name << '\n';
                max_heap.pop();
            }
        }
    }
}