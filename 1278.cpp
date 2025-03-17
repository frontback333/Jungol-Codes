//D[i] = 무게 i를 만들 수 있는 최대 보석 값어치
//D[i] = D[i-Unit]+1?;
#include<bits/stdc++.h>
using namespace std;
using ll = int;
ll N,W;
struct gem{
    int weight,value;
};
vector<gem>Gems;
ll D[1005][10005];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin>>N>>W;
    ll temp;
    Gems.resize(N);
    for(auto&[weight,value]:Gems) cin>>weight>>value;
    sort(Gems.begin(),Gems.end(),[](gem a,gem b){return a.weight<b.weight;});
    for(ll i=0;i<N;i++){
        for(ll j=0;j<=W;j++){
            temp = Gems[i].weight;
            if(j-temp<0)D[i+1][j]=D[i][j];
            else D[i+1][j] = max(D[i][j-temp]+Gems[i].value,D[i][j]);
        }
    }
    /*for(ll i=0;i<N+1;i++){
        for(ll j=0;j<=W;j++)cout<<D[i][j]<<' ';
        cout<<'\n';
    }*/
    cout<<D[N][W];
    return 0;
}
