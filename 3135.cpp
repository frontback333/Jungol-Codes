#include<bits/stdc++.h>
using namespace std;
using ll = long long;
ll arr[1000005];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    ll N,imos=0,m,s,e;
    cin>>N;
    for(ll i=0;i<N;i++){
        cin>>imos;
        arr[i+1]=arr[i]+imos;
    }
    cin>>m;
    while(m--){
        cin>>s>>e;
        cout<<arr[e]-arr[s-1]<<'\n';
    }
}
