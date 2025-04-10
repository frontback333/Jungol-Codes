#include<bits/stdc++.h>
using namespace std;
using ll = long long;
ll emptycnt=0;
vector<vector<ll>>arr(11,vector<ll>(11,0));
vector<vector<ll>>XCheck(11,vector<ll>(11,0)); /*몇번째 X줄에서 있는 숫자와 없는 숫자 나타냄*/
vector<vector<ll>>YCheck(11,vector<ll>(11,0)); /*몇번째 Y줄에서 있는 숫자와 없는 숫자 나타냄*/
vector<vector<ll>>BCheck(11,vector<ll>(11,0)); /*몇번째 박스에서 있는 숫자와 없는 숫자 나타냄*/


struct location{
    ll x,y;
};
vector<location>emptybox(85,{0,0});

bool Sudoku(ll x, ll y,ll emptystep){
    if(emptystep>=emptycnt)return true;
    for(ll i=1;i<=9;i++){
        if(XCheck[y][i]==0&&YCheck[x][i]==0&&BCheck[3*(y/3)+(x/3)][i]==0){
            XCheck[y][i]=1; YCheck[x][i]=1; BCheck[3*(y/3)+(x/3)][i]=1;
            arr[y][x]=i;
            if(Sudoku(emptybox[emptystep+1].x,emptybox[emptystep+1].y,emptystep+1)==false){
                XCheck[y][i]=0; YCheck[x][i]=0; BCheck[3*(y/3)+(x/3)][i]=0;
                arr[y][x]=0;
            }else return true;
        }
    }
    return false;
}

int main(){
    cin.tie(0)->sync_with_stdio();
    for(ll i=0;i<9;i++){
        for(ll j=0;j<9;j++){
            cin>>arr[i][j];
            if(arr[i][j]==0){emptybox[emptycnt].x = j; emptybox[emptycnt].y = i; emptycnt++;}
            XCheck[i][arr[i][j]]+=1;
            YCheck[j][arr[i][j]]+=1;
        }
    }
    for(ll i=0;i<9;i++){
        for(ll j=0;j<9;j++){
            BCheck[3*(i/3)+(j/3)][arr[i][j]]+=1;
        }
    }
    Sudoku(emptybox[0].x,emptybox[0].y,0);
    for(ll i=0;i<9;i++){
        for(ll j=0;j<9;j++){
            cout<<arr[i][j]<<' ';
        }
        cout<<'\n';
    }
}

