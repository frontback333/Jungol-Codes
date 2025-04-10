#include<bits/stdc++.h>
using namespace std;
using ll = long long;
ll N,M,head,tail,ans;
struct loc{
    ll x,y,pathcnt;
};
loc qa[1'000'005];
ll arr[1005][1005],DX[4]={-1,1,0,0},DY[4]={0,0,-1,1};

void q_push(ll x,ll y,ll pathcnt){
    if(x<0||y<0||x>=M||y>=N||arr[y][x]==-1)return;
    //cout<<y<<' '<<x<<' '<<pathcnt<<'\n';
    arr[y][x]=-1;
    qa[tail++] = {x,y,pathcnt};
    return;
}

void bfs(){
    ll newx,newy;
    while(head<tail){
        for(ll i=0;i<4;i++){
            newx = qa[head].x + DX[i]; newy = qa[head].y + DY[i];
            if(arr[newy][newx]==1)q_push(newx,newy,0);
            else q_push(newx,newy,qa[head].pathcnt+1);
        }
        head++;
    }
    return;
}

int main(){
    cin.tie(0)->sync_with_stdio();
    cin>>M>>N;
    for(ll i=0;i<N;i++){
        for(ll j=0;j<M;j++){
            cin>>arr[i][j];
        }
    }
    for(ll i=0;i<N;i++){
        for(ll j=0;j<M;j++){
            if(arr[i][j]==1)q_push(j,i,0);
        }
    }
    bfs();
    head--;
    ans = qa[head].pathcnt;
    for(ll i=0;i<N;i++){
        for(ll j=0;j<M;j++){
            if(arr[i][j]==0){ans=-1;break;}
        }
    }
    cout<<ans;
}

