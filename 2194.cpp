    #include<bits/stdc++.h>
    using namespace std;
    typedef long long ll;

    struct chem{
        ll mintemp,maxtemp;
    };

    bool maxtop(const chem& i,const chem& j){return(i.maxtemp<j.maxtemp);}

    int main(){
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        ll i,j;
        ll N,S,cnt=0,lastcost;
        cin>>N>>S;
        vector<ll>C(N);
        vector<ll>Y(N);
        for(i=0;i<N;i++){
            cin>>C[i]>>Y[i];
        }
        cnt+=C[0]*Y[0];
        lastcost = C[0];
        for(i=1;i<N;i++){
            lastcost +=S;
            if(lastcost>C[i])lastcost = C[i];
            cnt += lastcost*Y[i];
        }
        cout<<cnt;
    }
