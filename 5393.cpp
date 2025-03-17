#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
    cin.tie(0)->sync_with_stdio(0);
    ll i,j;
    ll N,cnt=0;
    string ct,st,temp;
    map<string,ll>mp;
    cin>>N;
    for(i=0;i<N;i++){
        cin>>ct>>st;
        temp = ct.substr(0,2);
        if(st+temp == temp+st) continue;
        mp[st+temp]++;
        cnt += mp[temp+st];
    }
    cout<<cnt;
}
