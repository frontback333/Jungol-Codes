#include<bits/stdc++.h>
#include<map>
using namespace std;
typedef long long ll;
int main(){
    ios_base::sync_with_stdio(0);
    ll i,j,k;
    ll N,idx;
    cin>>N;
    map<ll,ll>mp;
    for(i=0;i<N;i++){
        cin>>idx;
        mp[idx]++;
    }
    for(auto[key,value] : mp){
        cout<<key<<" : "<<value<<'\n';
    }
}
