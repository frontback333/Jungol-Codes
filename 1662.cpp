#include<bits/stdc++.h>
using namespace std;
using ll = long long;
ll BoardSze = 0,cnt=0,finalcnt=0;
ll Board[15][15];
vector<ll>Lcheck(25,0);

void BishopPlace(ll Y){
    if(Y>=BoardSze*2-1){
        if(cnt>finalcnt)finalcnt=cnt;
        return;
    }
    ll startx,starty;
    if(Y<BoardSze){startx = 0; starty = Y;}
    else{startx=Y-BoardSze+1;starty=BoardSze-1;}
    for(ll i=startx;i<=starty;i++){
        if(Board[Y-i][i]==1&&Lcheck[Y-2*i+BoardSze-1]==0){
            Lcheck[Y-2*i+BoardSze-1]=1;
            cnt++;
            BishopPlace(Y+2);
            Lcheck[Y-2*i+BoardSze-1]=0;
            cnt--;
        }
    }
    BishopPlace(Y+2);
}

int main(){
    /*cin.tie(0)->sync_with_stdio();*/
    cin>>BoardSze;
    ll temp =0;
    for(ll i=0;i<BoardSze;i++){
        for(ll j=0;j<BoardSze;j++){
            cin>>Board[i][j];
        }
    }
    BishopPlace(0); temp = finalcnt;
    finalcnt = 0;
    BishopPlace(1);
    cout<<temp + finalcnt;
}

