//D[i] = B 기준 i 번쨰 까지의 최장 부분 증가 수열
//D[i] = i 보다 작은 최댓값k 의 D[k] + 1
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
struct light{
    int snum,lnum;
};
struct Dt{
    int val,origin;
};
light P[10005] = {{0,0}};
map<ll,ll>inptos;
vector<int> cvec;
Dt D[10005] = {1};
ll N,tmp,mx = 0;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin>>N;
    for(ll i=1;i<=N;i++){
        cin>>P[i].snum;
        inptos[P[i].snum]=i;
    }
    for(ll i=1;i<=N;i++){
        cin>>tmp;
        P[i].lnum = inptos[tmp];
    }
    for(ll i=1;i<=N;i++){
        mx=0; tmp=0;
        for(ll j=1;j<i;j++){
            if(P[j].lnum<P[i].lnum && mx<D[j].val){
                mx=D[j].val; tmp = j;
            }
        }
        D[i].val = mx + 1; D[i].origin = tmp;
    }
    mx = 0; tmp = 0;
    for(ll i=1;i<=N;i++)if(D[i].val > mx){mx=D[i].val; tmp=i;}
    while(tmp){
        //cout<<P[tmp].snum<<' ';
        cvec.push_back(P[P[tmp].snum].snum);
        tmp = D[tmp].origin;
    }
    cout<<mx<<'\n';
    sort(cvec.begin(), cvec.begin() + mx);
    for(ll i : cvec){
        cout<<i<<' ';
    }
}
