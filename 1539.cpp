//D[i] = B 기준 i 번쨰 까지의 최장 부분 증가 수열
//D[i] = i 보다 작은 최댓값k 의 D[k] + 1
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
struct brick{
    int bn,s,h,m;
};
struct dta{
    int h,bc,origin;
};
brick P[105];
dta D[105] = {{0,0,0}},mx;
ll N,tmp=1;
stack<ll> stk;
int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin>>N;
    for(ll i=0;i<N;i++){
        cin>>P[i].s>>P[i].h>>P[i].m;
        P[i].bn = i+1;
    }
    sort(P,P+N,[](brick A,brick B){if(A.s==B.s)return A.m<B.m; return A.s<B.s;});
    for(ll i=0;i<N;i++){
        mx = {0,0,0};
        for(ll j=0;j<i;j++){
            if(P[j].m<P[i].m && mx.h<D[P[j].bn].h){
                mx = D[P[j].bn];
                mx.origin = P[j].bn;
            }
        }
        D[P[i].bn].h = mx.h + P[i].h; D[P[i].bn].bc = mx.bc + 1; D[P[i].bn].origin = mx.origin;
    }
    mx = {0,0,0};
    for(ll i=1;i<=N;i++){
        if(D[i].h>mx.h){mx=D[i];tmp=i;}
    }
    cout<<mx.bc<<'\n';
    while(tmp){
        stk.push(tmp);
        tmp = D[tmp].origin;
    }
    while(!stk.empty()){
        cout<<stk.top()<<'\n';
        stk.pop();
    }
}
