//D[i][j]=i번째 추까지 사용하였을때 j의 무게 측정 ㄱㄴ?
//if(D[i][j]==1)D[i+1][j+weight]=1,D[i+1][weight-j]=1
#include<bits/stdc++.h>
using namespace std;
using ll = int;
ll N,CN;

multiset<int> Weights;
ll D[35][40005]={1};
int main(){
    cin.tie(0)->sync_with_stdio(0);
    ll TCheck,temp;
    cin>>N;
    for(ll i=0;i<N;i++){
        cin>>temp;
        Weights.insert(temp);
    }
    ll i=0;
    for(auto mass : Weights){
        for(ll k=0;k<=15000;k++) D[i+1][k]=D[i][abs(k-mass)]|D[i][k]|D[i][k+mass];
        i++;
    }
    /*for(ll i=0;i<N+1;i++){
        for(ll j=0;j<=10;j++)cout<<D[i][j];
        cout<<'\n';
    }*/
    cin>>CN;
    while(CN--){
        cin>>TCheck;
        if(D[N][TCheck])cout<<"Y ";
        else cout<<"N ";
    }
}
