#include<bits/stdc++.h>
using namespace std;
using ll = long long;
ll N,finlen=1e9;
vector<string>DNAS(10);
map<ll,ll>InStr;

ll checkstr(const string& mainstr, const string& addingstr){
    ll mainsze = mainstr.size();
    ll checksze = min(mainsze,(ll)addingstr.size());
    ll Dupsze = 0;
    for(ll i = checksze-1;i>=0;i--){
        for(ll j=i;j>=0;j--){
            //cout<<i<<' '<<mainstr[mainsze-1-j]<<' '<<addingstr[i-j]<<'\n';
            if(mainstr[mainsze-1-j]==addingstr[i-j])Dupsze++;
            else{Dupsze=-1;break;}
        }
        if(Dupsze!=-1)break;
        Dupsze = 0;
    }
    return Dupsze;
}

void DNASum(ll step,ll curidx,ll curlen){
    if(curlen>=finlen)return;
    if(step>=N){
        if(finlen>curlen)finlen = curlen;
        return;
    }
    for(ll i=0;i<N;i++){
        if(InStr[i]!=0)continue;
        InStr[i]=1;
        DNASum(step+1,i,curlen-checkstr(DNAS[curidx],DNAS[i])+DNAS[i].size());
        InStr[i]=0;
    }
    return;
}

int main(){
    /*cin.tie(0)->sync_with_stdio();*/
    cin>>N;
    for(ll i=0;i<N;i++){
        cin>>DNAS[i];
    }
    DNASum(0,9,0);
    cout<<finlen;
}

