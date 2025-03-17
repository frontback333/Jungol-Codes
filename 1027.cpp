#include<bits/stdc++.h>
using namespace std;
using ll = long long;
ll N,finalcnt=1e9;
vector<ll>arr(85,0);

bool checkGoodArr(ll idx){
    if(idx==0)return true;
    if(idx==1){
        if(arr[1]!=arr[0])return true;
        return false;
    }
    for(ll i=idx/2;i<idx;i++){
        if(arr[i]==arr[idx]){
            ll check=0;
            for(ll j=0;j<idx-i;j++){
                if(arr[i-j]!=arr[idx-j])check++;
            }
            if(check==0)return false;
        }
    }
    return true;
}

bool GoodArray(ll idx){
    if(idx>=N){
        return true;
    }
    for(ll p=1;p<=3;p++){
        arr[idx]=p;
        if(checkGoodArr(idx) && GoodArray(idx+1)) return true;
    }
    return false;
}

int main(){
    cin.tie(0)->sync_with_stdio();
    cin>>N;
    GoodArray(0);
    for(ll i=0;i<N;i++){
        cout<<arr[i];
    }
}

