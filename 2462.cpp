#include<bits/stdc++.h>
using namespace std;
using ll = long long;
ll N,cnt=0,temp=0;
vector<ll>smaller[520];
vector<ll>bigger[520];
ll checkarr[520] = {};

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
    ll M,t1,t2;
    cin>>N>>M;
    while(M--){
        cin>>t1>>t2;
        smaller[t2].push_back(t1);
        bigger[t1].push_back(t2);
    }
    for(ll i = 1;i<=N;i++){
        temp = 0;
        for(ll &j:checkarr){
            j=0;
        }
        CheckSmaller(i);
        checkarr[i]=0;
        CheckBigger(i);
        if(temp>=N+1)cnt++;
    }
    cout<<cnt;
}
