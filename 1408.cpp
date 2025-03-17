//D[i] = B 기준 i 번쨰 까지의 최장 부분 증가 수열
//D[i] = i 보다 작은 최댓값k 의 D[k] + 1
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
struct eline{
    int A,B;
};
eline P[105];
int D[105] = {1};
ll N,mx;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin>>N;
    for(ll i=0;i<N;i++){
        cin>>P[i].A>>P[i].B;
    }
    sort(P,P+N,[](eline a, eline b){return a.A<b.A;});
    for(ll i=0;i<N;i++){
        mx=0;
        for(ll j=0;j<i;j++){
            if(P[j].B<P[i].B&&mx<D[j])mx=D[j];
        }
        D[i]=mx+1;
    }
    mx=0;
    for(ll i : D)if(i>mx)mx=i;
    cout<<N-mx;
}
