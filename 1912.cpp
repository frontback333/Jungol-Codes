#include<bits/stdc++.h>
using namespace std;
using ll = long long;
ll N,M;
vector<ll>arr[101010];
vector<ll>checkarr(101010,0);

void GoRoom(ll curRoom,ll visitedroom){
    if(curRoom == 0){checkarr[1]=1;cout<<1<<' ';GoRoom(1,0);return;}
    if(visitedroom>=N)return;
    for(ll i : arr[curRoom]){
        if(checkarr[i]==0){
            checkarr[i]=1;
            cout<<i<<' ';
            GoRoom(i,visitedroom+1);
        }
    }
    return;
}

int main(){
    cin.tie(0)->sync_with_stdio();
    ll t1,t2;
    cin>>N>>M;
    while(M--){
        cin>>t1>>t2;
        arr[t1].push_back(t2);
        arr[t2].push_back(t1);
    }
    for(ll i=1;i<=N;i++){
        sort(arr[i].begin(),arr[i].end());
    }
    GoRoom(0,0);
}

