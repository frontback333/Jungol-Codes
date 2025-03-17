//D[i] = 무게 i를 만들 수 있는 최대 보석 값어치
//D[i] = D[i-Unit]+1?;
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
ll N,W;
struct gem{
    int weight,value;
};
vector<gem>Gems;
ll D[10005];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin>>N>>W;
    ll temp;
    Gems.resize(N);
    for(auto&[weight,value]:Gems) cin>>weight>>value;
    sort(Gems.begin(),Gems.end(),[](gem a,gem b){return a.weight<b.weight;});
    for(auto k : Gems){
        for(ll i=0;i<=10000;i++){
            temp = i+k.weight;
            if(temp<=10000&&D[i]>=0&&D[temp]<D[i]+k.value)D[temp]=D[i]+k.value;
        }
    }
    for(ll i=W;i>=0;i--)if(D[i]){cout<<D[i];return 0;}
}
