#include<bits/stdc++.h>
using namespace std;
using ll = long long;
ll plane[6][6];
ll x[6];
ll y[6];
ll index(ll xs[], ll x) {
    return lower_bound(xs, xs+4, x) - xs;
}
int main(){
    //cin.tie(0)->sync_with_stdio(0);
    ll ax1,ay1,ax2,ay2;
    ll bx1,by1,bx2,by2;
    ll cnt=0,lx=0,ly=0,check=0,lin=0;
    cin>>ax1>>ay1>>ax2>>ay2>>bx1>>by1>>bx2>>by2;
    x[0]=ax1;x[1]=ax2;x[2]=bx1;x[3]=bx2;
    y[0]=ay1;y[1]=ay2;y[2]=by1;y[3]=by2;
    sort(x,x+4);sort(y,y+4);
    for(ll i = index(y,ay1);i<=index(y,ay2);i++){
        for(ll j = index(x,ax1);j<=index(x,ax2);j++){
            plane[i][j]++;
        }
    }
    for(ll i = index(y,by1);i<=index(y,by2);i++){
        for(ll j = index(x,bx1);j<=index(x,bx2);j++){
            plane[i][j]++;
            if(plane[i][j]==2){cnt++;lx=j;ly=i;}
        }
    }
    if(cnt){
        for(ll i=0;i<5;i++)if(plane[ly][i]==2)lin++;
        if(lin>1)check++;
        lin=0;
        for(ll i=0;i<5;i++)if(plane[i][lx]==2)lin++;
        if(lin>1){check++;}
    }
    if(!cnt)cout<<"NULL";
    else if(check==0)cout<<"POINT";
    else if(check==1)cout<<"LINE";
    else cout<<"FACE";
}
