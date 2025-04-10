#include<bits/stdc++.h>
using namespace std;
using ll = long long;
ll N,M,LX,LY,cnt=0;
ll head,tail;
struct loc{
    ll x,y,pathcnt;
};
loc qa[250005];
ll arr[55][55], checkarr[55][55];
ll XM[4] = {-1,1,0,0}, YM[4] = {0,0,-1,1};

void q_push(ll x,ll y,ll pathcnt){
    if(x>M || y>N || x<1 || y<1 || checkarr[y][x] ||arr[y][x]==0)return;
    //cout<<x<<' '<<y<<' '<<pathcnt<<'\n';
    checkarr[y][x]=1;
    qa[tail++] = {x,y,pathcnt};
    return;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    char tmp;
    cin>>N>>M;
    for(ll i=1;i<=N;i++){
        for(ll j=1;j<=M;j++){
            cin>>tmp;
            if((ll)tmp==87)arr[i][j]=0;
            else arr[i][j]=1;
            //cout<<arr[i][j];
        }
        //cout<<'\n';
    }
    for(ll i=1;i<=N;i++){
        for(ll j=1;j<=M;j++){
            if(arr[i][j]==1 && checkarr[i][j]==0){
                q_push(j,i,0);
                while(head<tail){
                    for(ll k=0;k<4;k++){
                        q_push(qa[head].x + XM[k],qa[head].y + YM[k],qa[head].pathcnt+1);
                    }
                    head++;
                }
                //cout<<i<<' '<<j<<' '<<qa[head].pathcnt<<'\n';
                head--;
                if(cnt<qa[head].pathcnt)cnt=qa[head].pathcnt;
                head++;
                for(ll k=1;k<=N;k++){
                    for(ll p=1;p<=M;p++){
                        checkarr[k][p]=0;
                    }
                }
            }
        }
    }
    rep(1){
        ~~
    }
    cout<<cnt;
}
