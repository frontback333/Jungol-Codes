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
        ll N,cnt=0;
        chem curmax;
        cin>>N;
        vector<chem>arr(N);
        for(i=0;i<N;i++){
            cin>>arr[i].mintemp>>arr[i].maxtemp;
        }
        sort(arr.begin(),arr.end(),maxtop);
        cnt++;
        curmax = arr[0];
        for(i=1;i<N;i++){
            if(curmax.maxtemp<arr[i].mintemp){cnt++; curmax=arr[i];}
        }
        cout<<cnt;
    }
