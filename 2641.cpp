#include<bits/stdc++.h>
using namespace std;
using ll = long long;

struct boxin{
    ll startcart,endcart,boxes;
};

bool boxpar(const boxin& a,const boxin& b){return a.endcart<b.endcart;}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    ll i,j;
    ll N,C,M;
    ll minbox=100005,cnt=0,temp;
    cin>>N>>C>>M;
    vector<ll>arr(N,C);
    vector<boxin>boxdata(M);
    for(i=0;i<M;i++){
        cin>>boxdata[i].startcart>>boxdata[i].endcart>>boxdata[i].boxes;
    }
    sort(boxdata.begin(),boxdata.end(),boxpar);
    for(i=0;i<M;i++){
        minbox = 100005;
        for(j=boxdata[i].startcart-1;j<boxdata[i].endcart-1;j++){
            if(arr[j]<minbox)minbox=arr[j];
        }
        if(minbox>boxdata[i].boxes)temp=boxdata[i].boxes;
        else temp = minbox;
        cnt+=temp;
        for(j=boxdata[i].startcart-1;j<boxdata[i].endcart-1;j++){
            arr[j]-=temp;
        }
    }
    cout<<cnt;
}
