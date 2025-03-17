#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    ll i,j;
    ll N,sum=0;
    cin>>N;
    vector<ll>arr(N,0);
    for(i=0;i<N;i++){
        cin>>arr[i];
    }
    sort(arr.begin(),arr.end());
    for(i=0;i<N;i++){
        if(sum+1<arr[i]){cout<<sum+1; return 0; }
        sum+=arr[i];
    }
    cout<<sum+1;
}
