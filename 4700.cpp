#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(0)->sync_with_stdio();
    ll n,x,temp;
    char cmd;
    cin>>n>>x;
    vector<ll>arr(n,x);
    while(1){
        cin>>cmd;
        if(cmd == 'i'){
            cin>>temp;
            arr.push_back(temp);
        }
        else if(cmd == 'r'){
            if(!arr.empty())arr.pop_back();
        }
        else if(cmd == 's'){
            if(!arr.empty()){
            sort(arr.begin(),arr.end());
            }
        }
        else if(cmd=='t'){
            if(!arr.empty()){
            temp = arr.back();
            arr.back() = arr.front(); arr.front() = temp;
            }
        }
        else{
            for(ll i:arr)cout<<i<<' ';
            break;
        }
    }
}

