#include<bits/stdc++.h>
using namespace std;
using ll = long long;
ll N,cnt=0,temp=0;
vector<ll>smaller[100010];
vector<ll>bigger[100010];
ll checkarr[100010] = {};

void CheckSmaller(ll self){
    if(checkarr[self])return;
    checkarr[self] = 1;
    temp++;
    for(ll i : smaller[self]){
        CheckSmaller(i);
    }
    return;
}

void CheckBigger(ll self){
    if(checkarr[self]==1)return;
    checkarr[self] = 1;
    temp++;
    for(ll i : bigger[self]){
        CheckBigger(i);
    }
    return;
}

int main(){
    //cin.tie(0)->sync_with_stdio(0);
    ll M,X,t1,t2;
    cin>>N>>M>>X;
    while(M--){
        cin>>t1>>t2;
        smaller[t1].push_back(t2);
        bigger[t2].push_back(t1);
    }
    CheckBigger(X);
    cout<<temp<<' ';
    checkarr[X]=0;
    temp=0;
    CheckSmaller(X);
    cout<<N-temp+1;
}
