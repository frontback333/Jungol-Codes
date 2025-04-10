#include<bits/stdc++.h>
using namespace std;
using ll = long long;
ll NX,NY,finalcnt = 1e8;
ll arr[105][105];
vector<vector<ll>>Checkarr(105,vector<ll>(105,100));
struct Pos{
    ll x,y;
};
Pos horse,pawn;
Pos Ways[8] = {{1,2},{1,-2},{2,1},{2,-1},{-1,2},{-1,-2},{-2,1},{-2,-1}};

void MoveHorse(ll X, ll Y, ll cnt){
    if(Checkarr[Y][X]<=cnt)return;
    else Checkarr[Y][X]=cnt;
    if(cnt>=finalcnt) return;
    if(arr[Y][X]==2){
        if(cnt<finalcnt)finalcnt = cnt;
        return;
    }
    for(ll i=0;i<8;i++){
        if(X+Ways[i].x<0 || X+Ways[i].x>=NX || Y+Ways[i].y<0 || Y+Ways[i].y>=NY) continue;
        MoveHorse(X+Ways[i].x,Y+Ways[i].y,cnt+1);
    }
    return;
}

int main(){
    /*cin.tie(0)->sync_with_stdio();*/
    cin>>NX>>NY;
    cin>>horse.x>>horse.y>>pawn.x>>pawn.y;
    horse.x-=1; horse.y-=1; pawn.x-=1; pawn.y-=1;
    Checkarr[horse.y][horse.x]=1;
    arr[pawn.y][pawn.x]=2;
    MoveHorse(horse.x,horse.y,0);
    cout<<finalcnt;
}

