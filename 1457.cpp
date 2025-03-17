#include<bits/stdc++.h>
using namespace std;
using ll = long long;
ll M,N,K,curArea=0;
ll arr[105][105],checkarr[105][105],AreaCnt[2505];
ll X_M[4] = {-1,1,0,0},Y_M[4] = {0,0,-1,1};

void AreaCheck(ll y, ll x, const ll& AreaNum){
    if(y<0||x<0||y>=M||x>=N||arr[y][x]||checkarr[y][x])return;
    checkarr[y][x]=1; AreaCnt[AreaNum]++;
    for(ll i=0;i<4;i++){
        AreaCheck(y+Y_M[i],x+X_M[i],AreaNum);
    }
}

int main(){
    /*cin.tie(0)->sync_with_stdio();*/
    ll xl,yl,xr,yr;
    cin>>M>>N>>K;
    for(ll i=0;i<K;i++){
        cin>>xl>>yl>>xr>>yr;
        for(ll j=yl;j<yr;j++){
            for(ll k=xl;k<xr;k++){
                arr[j][k]=1;
            }
        }
    }
    for(ll i=0;i<M;i++){
        for(ll j=0;j<N;j++){
            if(arr[i][j]==0&&checkarr[i][j]==0){
                curArea++;
                AreaCheck(i,j,curArea);
            }
        }
    }
    sort(AreaCnt+1,AreaCnt+curArea+1);
    cout<<curArea<<'\n';
    for(ll i=1;i<=curArea;i++){
        cout<<AreaCnt[i]<<' ';
    }
}

