#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll i,j;
    ll M,S,C;
    ll cnt=0;
    cin>>M>>S>>C;
    if(M>C){cout<<C;return 0;}
    vector<ll>arr(C,0);
    vector<ll>dist(C-1,0);
    for(i=0;i<C;i++){
        cin>>arr[i];
    }
    sort(arr.begin(),arr.end());
    cnt=arr[C-1]-arr[0]+1;
    for(i=1;i<C;i++){
        dist[i-1]= arr[i] - arr[i-1]-1;
    }
    sort(dist.begin(),dist.end(),greater<>());
    for(i = 0;i<M-1;i++){
        cnt -= dist[i];
    }
    cout<<cnt;
}
