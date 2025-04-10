#include<bits/stdc++.h>
using namespace std;
using ll = long long;

ll i,j,k;
ll N,Q,S,E;
ll cnt=0,maxy=0;

struct trunks{
    ll indx,xs,xe,y;
};
vector<trunks>arr(1000006);
vector<ll>paths(1000006,0);

bool compare(const trunks& a,const trunks& b){return a.xs<b.xs;}

void indexing(){
    ll id = 0;
    ll end = arr[0].xe;
    for(j=0;j<N;j++){
        if(arr[j].xs>end){
            id++;
        }
        end = max(arr[j].xe,end);
        paths[arr[j].indx]= id;
    }
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin>>N>>Q;
    for(i=0;i<N;i++){
        cin>>arr[i].xs>>arr[i].xe>>arr[i].y;
        arr[i].indx = i;
        if(arr[i].y>maxy)maxy=arr[i].y;
    }
    sort(arr.begin(),arr.begin()+N,compare);
    indexing();
    while(Q--){
        cin>>S>>E;
        if(paths[S-1]==paths[E-1])cout<<1<<'\n';
        else cout<<0<<'\n';
    }
}
