#include<bits/stdc++.h>
using namespace std;
using ll = int;
ll M,N,K,sx,sy,dx,dy,head,tail,ans=0;
ll checkarr[5005];
struct buspth{
    ll bn,x1,y1,x2,y2;
};
struct loc{
    ll bn,pathcnt;
};
vector<buspth>buspath;
vector<ll>meetingbus[5005];
vector<ll>startingbus;
loc qa[5005];

bool iscross(buspth A, buspth B){
    if(A.x2<B.x1 || A.x1>B.x2 || A.y2<B.y1 || A.y1>B.y2)return false;
    return true;
}

void q_push(ll B_bn, ll pathcnt){
    if(B_bn<0){ans=pathcnt-1;return;}
    if(checkarr[B_bn])return;
    checkarr[B_bn]++;
    qa[tail++]={B_bn,pathcnt};
}

void bfs(){
    for(ll i : startingbus){
        q_push(i,1);
    }
    while(head<tail){
        for(ll i:meetingbus[qa[head].bn]){
            q_push(i,qa[head].pathcnt+1);
            if(ans)break;
        }
        head++;
    }
}

int main(){
    //cin.tie(0)->sync_with_stdio(0);
    ll bn,x1,y1,x2,y2,minx,miny,maxx,maxy;
    cin>>M>>N>>K;
    for(ll i=0;i<K;i++){
        cin>>bn>>x1>>y1>>x2>>y2;
        if(x1 > x2) swap(x1,x2);
        if(y1 > y2) swap(y1,y2);
        for(buspth i : buspath){
            if(iscross({bn,x1,y1,x2,y2},i)){
                meetingbus[bn].push_back(i.bn);
                meetingbus[i.bn].push_back(bn);
            }
        }
        buspath.push_back({bn,min(x1,x2),min(y1,y2),max(x1,x2),max(y1,y2)});
    }
    cin>>sx>>sy>>dx>>dy;
    for(buspth i : buspath){
        if(iscross({0,sx,sy,sx,sy},i)) startingbus.push_back(i.bn);
        if(iscross({0,dx,dy,dx,dy},i)) meetingbus[i.bn].push_back(-1);
    }
    bfs();
    cout<<ans;
}
