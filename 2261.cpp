#include<bits/stdc++.h>
using namespace std;
using ll = long long;
ll N,K,head,tail,A,B,ans=0;
struct path{
    ll a,b,pathcnt;
};
vector<ll>heming[1005];
stack<ll>fin;
ll checkarr[1005];
path qa[1'000'005];
char arr[1005][35];

ll H(ll a,ll b){
    ll cnt =0;
    for(ll i=0;i<K;i++){
        if(arr[a][i]!=arr[b][i])cnt++;
    }
    return cnt;
}

void q_push(ll a,ll b,ll pathcnt){
    if(checkarr[b]) return;
    checkarr[b]=a;
    //cout<<b<<' '<<pathcnt<<'\n';
    if(b==B){ans=pathcnt;return;}
    qa[tail++]={a,b,pathcnt};
    return;
}

void bfs(){
    checkarr[A]=-1;
    for(ll i : heming[A]){
        q_push(A,i,1);
    }
    while(head<tail){
        for(ll i : heming[qa[head].b]){
            //cout<<qa[head].pathcnt<<' ';
            q_push(qa[head].b, i, qa[head].pathcnt+1);
            if(ans)break;
        }
        head++;
    }
    return;
}

int main(){
    //cin.tie(0)->sync_with_stdio();
    cin>>N>>K;
    for(ll i=1;i<=N;i++){
        for(ll j=0;j<K;j++){
            cin>>arr[i][j];
        }
    }
    for(ll i=1;i<=N;i++){
        for(ll j=1;j<=N;j++) if(i!=j) if(H(i,j)==1)heming[i].push_back(j);
    }
    cin>>A>>B;
    bfs();
    if(!ans)cout<<-1;
    else{
        ll k=B;
        while(k!=-1){
            fin.push(k);
            k = checkarr[k];
        }
        while(fin.size()>0){
            cout<<fin.top()<<' ';
            fin.pop();
        }
    }
}

