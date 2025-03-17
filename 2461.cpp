#include<bits/stdc++.h>
using namespace std;
using ll = long long;

ll monthes[] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
ll cnt = 0;
ll N,i,j;

struct flower{
    ll bloomstart,bloomend;
};
vector<flower>arr(100006);

bool fpar(const flower& a,const flower& b){return a.bloomend>b.bloomend;}

void cntflower(ll S){
    if(S >1130)return;
    for(i=0;i<N;i++){
        if(arr[i].bloomstart<=S && arr[i].bloomend>S){cnt++; cntflower(arr[i].bloomend); return;}
    }
    cnt = 0;
    return;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    ll SM,SD,EM,ED;
    cin>>N;
    for(i=0;i<N;i++){
        cin>>SM>>SD>>EM>>ED;
        arr[i].bloomstart = SM*100 + SD;
        arr[i].bloomend = EM*100 + ED;
    }
    sort(arr.begin(),arr.end(),fpar);
    cntflower(301);
    cout<<cnt;
}
