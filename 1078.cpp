#include<bits/stdc++.h>
using namespace std;
using ll = long long;
ll N,M,LX,LY,cnt=0;
ll head,tail;
struct loc{
    ll x,y,pathcnt;
};
loc qa[10005];
ll arr[105][105], checkarr[105][105];
ll XM[4] = {-1,1,0,0}, YM[4] = {0,0,-1,1};

void q_push(ll x,ll y,ll pathcnt){
    if(x>N || y>M || x<1 || y<1 || arr[y][x]==0)return;
    //cout<<x<<' '<<y<<' '<<pathcnt<<'\n';
    arr[y][x]=0;
    qa[tail++] = {x,y,pathcnt};
    return;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    char tmp;
    cin>>N>>M;
    for(ll i=1;i<=M;i++){
        for(ll j=1;j<=N;j++){
            cin>>tmp;
            if((ll)tmp==48)arr[i][j]=0;
            else arr[i][j]=1;
        }
    }
    cin>>LX>>LY;
    q_push(LX,LY,0);
    while(head<tail){
        for(ll i=0;i<4;i++){
            q_push(qa[head].x + XM[i],qa[head].y + YM[i],qa[head].pathcnt+1);
        }
        head++;
    }
    cout<<qa[head-1].pathcnt + 3<<'\n';
    for(ll i=1;i<=M;i++){
        for(ll j=1;j<=N;j++){
            if(arr[i][j]==1)cnt++;
        }
    }
    cout<<cnt;
}
