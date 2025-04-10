//D[i] = i번째 자리까지 얻을 수 있는 최대의 점수
//D[i] = max(D(i-2) + SS[i], D(i-3) + SS[i-1] + SS[i])
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
ll N;
ll SS[305];
ll D[305] = {0};

ll MaxScore(ll n){
    if(D[n])return D[n];
    D[n] = max(MaxScore(n-2), MaxScore(n-3) + SS[n-1]) + SS[n];
    return D[n];
}

int main(){
    cin.tie()->sync_with_stdio();
    cin>>N;
    for(ll i=1;i<=N;i++){
        cin>>SS[i];
    }
    D[1]=SS[1];
    D[2]=SS[1]+SS[2];
    D[3]=max(SS[1],SS[2]) + SS[3];
    cout<<MaxScore(N);
}

