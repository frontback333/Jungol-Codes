#include<bits/stdc++.h>
using namespace std;
using ll = long long;

ll drawersize,finalcnt = 1e9,usecnt;
vector<ll>Drawers(25,1);
ll UseArr[25];

ll MoveDrawers(ll cnt,ll usestep,ll blank1,ll blank2){
    if(usestep>=usecnt) return cnt;
    return min(MoveDrawers(cnt+abs(blank1 - UseArr[usestep]),usestep+1,UseArr[usestep],blank2), MoveDrawers(cnt+abs(blank2 - UseArr[usestep]),usestep+1,blank1,UseArr[usestep]));
}

int main(){
    /*cin.tie(0)->sync_with_stdio();*/
    ll openo,opent;
    cin>>drawersize>>openo>>opent>>usecnt;
    Drawers[openo-1]=0; Drawers[opent-1]=0;
    for(ll i=0;i<usecnt;i++){
        cin>>UseArr[i];
        UseArr[i]-=1;
    }
    cout<< MoveDrawers(0,0,openo-1,opent-1);
}

