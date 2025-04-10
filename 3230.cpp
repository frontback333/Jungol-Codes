#include<bits/stdc++.h>
using namespace std;
using ll = long long;
ll N,L1,L2,cmin=0;

struct Path{
    ll target,len;
};
vector<Path>arr[100010];
ll checkarr[100010];

void FindPath(ll R1,ll StartF,ll MaxLength,ll Pathcnt){
    if(R1==L2){cmin = Pathcnt - MaxLength; return;}
    for(Path i : arr[R1]){
        if(i.target == StartF)continue;
        FindPath(i.target,R1,MaxLength>i.len ? MaxLength : i.len,Pathcnt+i.len);
    }
    return;
}

int main(){
    //cin.tie(0)->sync_with_stdio(0);
    ll start,target,len;
    cin>>N>>L1>>L2;
    for(ll i=0;i<N-1;i++){
        cin>>start>>target>>len;
        arr[start].push_back({target,len});
        arr[target].push_back({start,len});
    }
    FindPath(L1,0,0,0);
    cout<<cmin;
}
