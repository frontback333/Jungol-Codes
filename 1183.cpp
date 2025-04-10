#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const ll Coins[6] = {500,100,50,10,5,1};

int main(){
    cin.tie(0)->sync_with_stdio(0);
    ll i,j;
    ll W,temp,gotmoney=0,coincnt = 0;
    vector<ll>cnts(6);
    vector<ll>ans(6);
    cin>>W;
    for(i=0;i<6;i++){
        cin>>cnts[i];
        gotmoney += Coins[i]*cnts[i];
    }
    gotmoney -= W;
    for(i=0;i<6;i++){
        temp = gotmoney - gotmoney%Coins[i];
        while(temp/Coins[i]>cnts[i]){
            temp-=Coins[i];
        }
        ans[i]=temp/Coins[i];
        gotmoney -= temp;
    }
    for(i=0;i<6;i++){
        ans[i] = cnts[i]-ans[i];
        coincnt += ans[i];
    }
    cout<<coincnt<<'\n';
    for(i=0;i<6;i++){
        cout<<ans[i]<<' ';
    }
}
