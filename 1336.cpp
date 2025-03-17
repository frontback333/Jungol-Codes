#include<bits/stdc++.h>
using namespace std;
using ll = long long;
ll A,B,head,tail,ans=0;
struct bstop{
    ll b,pathcnt;
};
ll checkarr[10005];
bstop qa[100005];

bool checkprime(ll a){
    for(ll i=2;i<=sqrt(a);i++){
        if(a%i==0)return false;
    }
    return true;
}

void q_push(ll a,ll b,ll pathcnt){
    if(b<1000||checkprime(b)==false||checkarr[b])return;
    //cout<<a<<' '<<b<<' '<<pathcnt<<'\n';
    if(b==B){ans=pathcnt;return;}
    checkarr[b]=1;
    qa[tail++]={b,pathcnt};
    return;
}

void bfs(){
    for(ll i=0;i<10;i++){
        q_push(A,(A/1000)%10 * 1000 + (A/100)%10 *100 + (A/10)%10 *10 + i,1);
        q_push(A,(A/1000)%10 * 1000 + (A/100)%10 *100  + i*10 + A%10,1);
        q_push(A,(A/1000)%10 * 1000 + i*100 + (A/10)%10 *10  + A%10,1);
        q_push(A,i*1000 + (A/100)%10 *100  + (A/10)%10 *10  + A%10,1);
    }
    while(head<tail){
        for(ll i=0;i<10;i++){
            q_push(qa[head].b,(qa[head].b/1000)%10 * 1000 + (qa[head].b/100)%10 *100  + (qa[head].b/10)%10 *10  + i,qa[head].pathcnt+1);
            q_push(qa[head].b,(qa[head].b/1000)%10 * 1000 + (qa[head].b/100)%10 *100  + i*10 + qa[head].b%10,qa[head].pathcnt+1);
            q_push(qa[head].b,(qa[head].b/1000)%10 * 1000 + i*100 + (qa[head].b/10)%10 *10  + qa[head].b%10,qa[head].pathcnt+1);
            q_push(qa[head].b,i*1000 + (qa[head].b/100)%10 *100  + (qa[head].b/10)%10 *10  + qa[head].b%10,qa[head].pathcnt+1);
            if(ans)break;
        }
        head++;
    }
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin>>A>>B;
    //cout<<checkprime(1030)<<'\n';
    checkarr[A]=1;
    bfs();
    cout<<ans;
}
