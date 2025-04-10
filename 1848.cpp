//D[i] = i번째 자리까지 고려한 가짓수
//D[i] = D[i-1]+D[i-2]

#include<bits/stdc++.h>
using namespace std;
using ll = long long;
ll N,M;
ll seat[45];
ll S_D[45]={1,1,2};

int main(){
    ll temp;
    cin>>N>>M;
    while(M--){
        cin>>temp;
        seat[temp]=1;
    }
    for(ll i = 1;i<=N;i++){
        if(seat[i-1]||seat[i])S_D[i]=S_D[i-1];
        else S_D[i] = S_D[i-1]+S_D[i-2];
    }
    cout<<S_D[N];
}
