#include<bits/stdc++.h>
using namespace std;
using ll = long long;
ll N,M,ans,head,tail;
struct loc{
    ll x,y,pathcnt;
    char typ;
};
loc qa[5005];
ll DX[4] = {-1,1,0,0}, DY[4] = {0,0,-1,1},checkarr[55][55];
char arr[55][55];

void q_push(ll x,ll y,ll pathcnt,ll typ){
    if(x<0||y<0||x>=M||y>=N||checkarr[y][x]||arr[y][x]=='X')return;
    //cout<<x<<' '<<y<<' '<<pathcnt<<' '<<(char)typ<<'\n';
    if(typ=='*' && arr[y][x]=='D') return;
    checkarr[y][x]=1;
    if(typ=='S'){
        if(arr[y][x]=='D'){ans = pathcnt;}
        else qa[tail++] = {x,y,pathcnt,typ};
    }else{
         qa[tail++] = {x,y,pathcnt,typ};
    }
    return;
}

void bfs(){
    while(head<tail){
        for(ll i=0;i<4;i++){
            q_push(qa[head].x+DX[i],qa[head].y+DY[i],qa[head].pathcnt+1,qa[head].typ);
            if(ans)break;
        }
        head++;
    }
}

int main(){
    cin.tie(0)->sync_with_stdio();
    cin>>N>>M;
    for(ll i=0;i<N;i++){
        for(ll j=0;j<M;j++){
            cin>>arr[i][j];
        }
    }
    for(ll i=0;i<N;i++){
        for(ll j=0;j<M;j++){
            if(arr[i][j]=='*')q_push(j,i,0,'*');
        }
    }
    for(ll i=0;i<N;i++){
        for(ll j=0;j<M;j++){
            if(arr[i][j]=='S')q_push(j,i,0,'S');
        }
    }
    bfs();
    if(!ans)cout<<"impossible";
    else cout<<ans;
}

