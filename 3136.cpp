#include<bits/stdc++.h>
using namespace std;
using ll = long long;
ll arr[1005][1005];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    ll N,imosx=0,imosy=0,m,sr,sc,er,ec;
    cin>>N;
    for(ll i=1;i<=N;i++){
        for(ll j=1;j<=N;j++){
            cin>>arr[i][j];
        }
    }
    for(ll i=1;i<=N;i++){
        for(ll j=1;j<=N;j++){
            if(!i)arr[i][j]+=arr[i][j-1];
            else if(!j)arr[i][j]+=arr[i-1][j];
            else arr[i][j]+=arr[i-1][j]+arr[i][j-1]-arr[i-1][j-1];
        }
    }
    cin>>m;
    while(m--){
        cin>>sr>>sc>>er>>ec;
        cout<<arr[er][ec]-arr[sr-1][ec]-arr[er][sc-1]+arr[sr-1][sc-1]<<'\n';
    }
}


