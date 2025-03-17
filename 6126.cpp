#include<bits/stdc++.h>
using namespace std;
using ll = long long;
ll Teams[1000005];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    ll N,S,E,C,Q,T,imos=0;
    cin>>N;
    for(ll i=0;i<N;i++){
        cin>>S>>E>>C;
        Teams[S]+=C; Teams[E+1]-=C;
    }
    for(ll &i : Teams){
        imos += i;
        i = imos;
    }
    cin>>Q;
    while(Q--){
        cin>>T;
        cout<<Teams[T]<<'\n';
    }
}
