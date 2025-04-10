#include<bits/stdc++.h>
using namespace std;
using ll = long long;
ll N,curid,curlcm=1;
ll mix[20005],check[20005];
vector<ll>v;
ll gcd(ll a, ll b){return b?gcd(b,a%b):a+b;}

ll iscycle(ll idx, ll cnt){
    check[idx]=1;
    if(idx==curid)return cnt;
    else return iscycle(mix[idx],cnt+1);
}

int main(){
    cin.tie(0)->sync_with_stdio();
    cin>>N;
    for(ll i=0;i<N;i++){
        cin>>mix[i];
        mix[i]--;
    }
    for(curid=0;curid<N;curid++){
        if(!check[curid])v.push_back(iscycle(mix[curid],1));
    }
    for(ll i : v)curlcm = curlcm * i / gcd(curlcm,i);
    cout<<curlcm;
    return 0;
}


