#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(0)->sync_with_stdio();
    ll N,k,temp;
    vector<int>arr[1050];
    cin>>N;
    for(ll i = 0;i<N;i++){
        cin>>k;
        while(k--){
            cin>>temp;
            arr[i].push_back(temp);
        }
    }
    while(N--){
        cin>>k;
        for(ll i : arr[k]){
            cout<<i<<' ';
        }
        cout<<'\n';
    }
}

