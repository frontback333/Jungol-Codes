#include<bits/stdc++.h>
using namespace std;
using ll = long long;
ll N;
ll tile_DP[100005]={1,1,3};

ll tiles(ll n){
    if(tile_DP[n])return tile_DP[n];
    tile_DP[n]=tiles(n-2)*2 + tiles(n-1);
    tile_DP[n] %= 20100529;
    //cout<<n<<" : "<<tile_DP[n]<<'\n';
    return tile_DP[n];
}

int main(){
    cin>>N;
    cout<<tiles(N);
}

