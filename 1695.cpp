#include<bits/stdc++.h>
using namespace std;
using ll = long long;
ll N,curBlocks=0;
ll arr[30][30],checkarr[30][30],BlockCnt[150];
ll X_M[4] = {-1,1,0,0},Y_M[4] = {0,0,-1,1};

void BlockCheck(ll y, ll x, const ll& curBlocks){
    if(x<0 || y<0 || !arr[y][x] || checkarr[y][x])return;
    checkarr[y][x]=1; BlockCnt[curBlocks]++;
    for(ll i=0;i<4;i++){
        BlockCheck(y + Y_M[i],x + X_M[i],curBlocks);
    }
    return;
}

int main(){
    /*cin.tie(0)->sync_with_stdio();*/
    char temp;
    cin>>N;
    for(ll i=0;i<N;i++){
        for(ll j=0; j<N; j++){
            cin>>temp;
            arr[i][j]=temp-48;
        }
    }
    for(ll i=0;i<N;i++){
        for(ll j=0; j<N; j++){
            if(arr[i][j] && !checkarr[i][j]){
                curBlocks++;
                BlockCheck(i,j,curBlocks);
            }
        }
    }
    cout<<curBlocks<<'\n';
    sort(BlockCnt+1,BlockCnt+curBlocks+1);
    for(ll i=1;i<=curBlocks;i++)cout<<BlockCnt[i]<<'\n';
}

