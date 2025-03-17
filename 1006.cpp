#include<bits/stdc++.h>
using namespace std;
using ll = long long;
ll N,M,head,tail,ans;
ll ay,ax,adir,by,bx,bdir;
ll arr[105][105],checkarr[105][105][4],DX[4]={1,-1,0,0},DY[4]={0,0,1,-1};
struct loc{
    ll x,y,dir,pathcnt;
};
loc qa[1000'005];

bool q_push(ll x, ll y, ll dir, ll pathcnt){
    //cout<<x<<' '<<y<<' '<<dir<<' '<<pathcnt<<'\n';
    if(x<1||y<1||x>M||y>N||arr[y][x])return false;
    if(checkarr[y][x][dir])return true;
    checkarr[y][x][dir]=1;
    if(y==by && x==bx && dir == bdir){
        ans = pathcnt;
        return false;
    }
    qa[tail++]={x,y,dir,pathcnt};
    return true;
}

void bfs(){
    ll inc,dx=0,dy=0,curdir;
    while(head<tail){
        for(ll i=0;i<3;i++){
            dx+=DX[qa[head].dir]; dy += DY[qa[head].dir];
            //cout<<dx<<' '<<dy<<'\n';
            if(!q_push(qa[head].x + dx, qa[head].y + dy, qa[head].dir, qa[head].pathcnt+1))break;
        }
        dx=0;dy=0;
        if(ans)break;
        else if(qa[head].dir==0||qa[head].dir==1){
            q_push(qa[head].x,qa[head].y,3,qa[head].pathcnt+1);
            q_push(qa[head].x,qa[head].y,2,qa[head].pathcnt+1);
        }else{
            q_push(qa[head].x,qa[head].y,0,qa[head].pathcnt+1);
            q_push(qa[head].x,qa[head].y,1,qa[head].pathcnt+1);
        }
        head++;
    }
}

int main(){
    //cin.tie(0)->sync_with_stdio(0);
    cin>>N>>M;
    for(ll i = 1;i<=N;i++){
        for(ll j=1;j<=M;j++){
            cin>>arr[i][j];
        }
    }
    cin>>ay>>ax>>adir>>by>>bx>>bdir;
    adir--;bdir--;
    q_push(ax,ay,adir,0);
    bfs();
    cout<<ans;
}
