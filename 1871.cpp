//D[i] = i번 값이 가장 뒤에 있는 최장 부분 증가 수열
//D[i] = i 보다 작은 최댓값k 의 D[k] + 1
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
ll D[205]={1},C[205];
ll N,mx;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin>>N;
    for(ll i=0;i<N;i++)cin>>C[i];
    for(ll i=0;i<N;i++){
        mx=0;
        for(ll j=0;j<i;j++){
            if(C[j]<C[i]&&D[j]>mx)mx=D[j];
        }
        D[i] = mx+1;
    }
    mx=0;
    for(ll i=0;i<N;i++)if(D[i]>mx)mx=D[i];
    cout<<N-mx;
}
