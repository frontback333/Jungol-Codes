//D[i] = i번째 자리까지 가능한 경우의 수
//D[i] = D[i-1]+(i-1과 자신<35이면 D[i-2], 아니면 0)
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
ll D[45]={1,1};
string S;

int main(){
    cin.tie()->sync_with_stdio();
    cin>>S;
    ll temp1,temp2;
    S = (string)" " + S;
    for(ll i=2;i<S.size();i++){
        temp1 = (ll)S[i-1] - 48; temp2 = (ll)S[i] - 48;
        if(!temp2 && temp1*10 + temp2 > 35)break;
        else if(!temp2)D[i]=D[i-2];
        else if(temp1 && temp1*10 + temp2 < 35)D[i]= D[i-1]+D[i-2];
        else D[i]=D[i-1];
        //cout<<i<<" : "<<D[i]<<'\n';
    }
    cout<<D[S.size()-1];
}

