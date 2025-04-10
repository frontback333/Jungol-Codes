#include<bits/stdc++.h>
using namespace std;
using ll = long long;
ll N,M,R,C,S,K,cnt=0;
ll head,tail;
struct loc{
    ll x,y,pathcnt;
};
ll checkarr[1005][1005];
loc qa[1000005];
ll XM[8] = {1,2,2,1,-1,-2,-2,-1}, YM[8] = {2,1,-1,-2,2,1,-1,-2};

void q_push(ll x,ll y,ll pathcnt){
    if(x>N || y>M || x<1 || y<1 || checkarr[x][y] ||cnt)return;
    //cout<<x<<' '<<y<<' '<<pathcnt<<'\n';
    if(x==S && y==K){cnt = pathcnt; return;}
    checkarr[x][y]=1;
    qa[tail++] = {x,y,pathcnt};
    return;
}

int main(){
    cin>>N>>M>>R>>C>>S>>K;
    q_push(R,C,0);
    while(!cnt&&head!=tail){
        for(ll i=0;i<8;i++){
            if(qa[head].x == S && qa[head].y == K){cnt = qa[head].pathcnt; break;}
            q_push(qa[head].x + XM[i],qa[head].y + YM[i],qa[head].pathcnt+1);
        }
        head++;
    }
    cout<<cnt;
    return 0;
}
