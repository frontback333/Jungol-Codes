#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

struct meeting{
    ll index;
    ll meetstart;
    ll meetend;
};

bool startop(const meeting& i, const meeting& j){return(i.meetstart>j.meetstart);}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll i,j;
    ll N;
    cin>>N;
    vector<meeting>arr(N);
    vector<meeting>res(1);
    for(i=0;i<N;i++){
        cin>>arr[i].index>>arr[i].meetstart>>arr[i].meetend;
    }
    sort(arr.begin(),arr.end(),startop);
    res[0]=arr[0];
    for(i=1;i<N;i++){
        if(arr[i].meetend<=res.back().meetstart) res.push_back(arr[i]);
    }
    cout<<res.size()<<'\n';
    for(i=res.size()-1;i>=0;i--){
        cout<<res[i].index<<' ';
    }
}
