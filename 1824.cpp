#include<bits/stdc++.h>
using namespace std;
using ll = long long;
ll M,N;
ll arr[105][105],checkarr[105][105],lastcheese[60];
ll X_M[4] = {-1,1,0,0},Y_M[4] = {0,0,-1,1};

void check(ll y,ll x,const ll& cnt){
    if(y<=0||x<=0||y>M||x>N||checkarr[y][x]==1)return;
    if(arr[y][x]==1){
            //cout<<y<<' '<<x<<'\n';
            lastcheese[cnt]++;
            arr[y][x]=0; checkarr[y][x]=1;
            return;
    }
    checkarr[y][x]=1;
    for(ll i=0;i<4;i++){
        check(y+Y_M[i],x+X_M[i],cnt);
    }
    return;
}

int main(){
    cin.tie(0)->sync_with_stdio();
    cin>>M>>N;
    for(ll i=1;i<=M;i++){
        for(ll j=1;j<=N;j++){
            cin>>arr[i][j];
        }
    }
    ll cnt = 1;
    while(1){
        for(ll i=1;i<=M;i++){
            for(ll j=1;j<=N;j++){
                checkarr[i][j]=0;
            }
        }
        check(1,1,cnt);
        if(!lastcheese[cnt])break;
        cnt++;
    }
    if(cnt)cnt--;
    cout<<cnt<<'\n'<<lastcheese[cnt];
}

