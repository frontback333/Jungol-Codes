#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void mul(string N,string M){
    int res[10005]={0};
    ll addval=0,c=0,m=0;
    for(ll i=0;i<M.size();i++){
        if((M[i]-48)<0){M[i]=48;m++;}
        for(ll j=0;j<N.size();j++){
            if((N[j]-48)<0){N[j]=48;m++;}
            addval = (N[j]-48)*(M[i]-48);
            res[i+j]+=addval;
        }
    }
    for(ll i=0;i<10004;i++){
        if(res[i]>=10)addval=res[i]/10;
        else addval = 0;
        res[i+1]+=addval;
        res[i]%=10;
    }
    if(m%2)cout<<'-';
    for(ll i=10004;i>=0;i--){
        if(res[i]>0)c=1;
        if(c)cout<<res[i];
    }
}

int main(){
    /*cin.tie(0)->sync_with_stdio();*/
    while(1){
        string N,M;
        cin>>N;
        if(!(N[0]-48))return 0;
        cin>>M;
        if(!(M[0]-48))cout<<0;
        else{
            if(M.size()>N.size()||(M.size()==N.size()&&M>N))swap(M,N);
            reverse(N.begin(),N.end()); reverse(M.begin(),M.end());
            mul(N,M);
        }
        cout<<'\n';
    }
}

