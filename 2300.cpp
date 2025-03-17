#include<bits/stdc++.h>
using namespace std;
using ll = long long;
ll N;
map<ll,ll>fluid;

int main(){
    //cin.tie(0)->sync_with_stdio(0);
    ll tmp,mn=0,ms,ml,s,l;
    cin>>N;
    for(ll i=0;i<N;i++){
        cin>>tmp;
        fluid[i]=tmp;
    }
    mn = abs(fluid[0]+fluid[N-1]);s=0;l=N-1;
    for(ll i=0;i<N;i++){
        if(s==l)break;
        tmp=fluid[s]+fluid[l];
        if(abs(tmp)<=mn){mn=abs(tmp);ms=fluid[s];ml=fluid[l];}
        if(tmp<0)s++;
        else l--;
    }
    cout<<min(ms,ml)<<' '<<max(ms,ml);
}
