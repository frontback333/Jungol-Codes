//D[i] = i원을 만들 수 있는 최소 동전 수
//D[i] = D[i-Unit]+1?;
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
ll N,W;
vector<ll>Unit(15);
ll D[64505] = {0};

int main(){
    cin.tie(0)->sync_with_stdio();
    ll temp;
    cin>>N;
    for(ll i=1;i<=64000;i++){
        D[i]=-1;
    }
    for(ll i=0;i<N;i++){
        cin>>Unit[i];
    }
    sort(Unit.begin(),Unit.end());
    for(ll temp:Unit){
        for(ll i=0;i<=64000;i++){
            if(i+temp<=64000&&D[i]>=0&&(D[i+temp]<0||D[i+temp]>D[i]+1))D[i+temp]=D[i]+1;
        }
    }
    cin>>W;
    if(D[W]<0)cout<<"impossible";
    else cout<<D[W];
}

