//D[i][j]=i번째 동전까지 사용했을때 j값을 만들 수 있는 가짓수
//D[i] = D[i-1][j]+D[i-1][j-price]+1
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
ll T,K;
struct Coin{
    ll price,num;
};
vector<Coin>Coins;
ll D[105][10005]={1};

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin>>T>>K;
    Coins.resize(K);
    for(Coin& i : Coins)cin>>i.price>>i.num;
    for(ll i=0;i<K;i++){
        ll temp = Coins[i].price;
        for(ll j=0;j<=10000;j++){
            for(int k=0;k<=Coins[i].num&&k*temp<=j;k++){
                D[i+1][j] += D[i][j-temp*k];
            }
        }
    }
    for(ll i=0;i<K;i++){
        for(ll j=0;j<=T;j++)cout<<D[i][j];
        cout<<'\n';
    }
    cout<<D[K][T];
}
