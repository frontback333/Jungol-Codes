#include<bits/stdc++.h>
using namespace std;
using ll = long long;
string A,B;
ll Asze, Bsze;

void sum(const string& big,const string& small,const ll& bigs,const ll& smalls){
    ll addval = 0,c=0;
    int result[210]={0};
    for(ll i=0;i<210;i++){
        if(i<smalls)addval+=small[i]-48;
        if(i<bigs)addval+=big[i]-48;
        result[i]=addval%10;
        addval/=10;
    }
    for(ll i=209;i>=0;i--){
        if(result[i]>0)c=1;
        if(c)cout<<result[i];
    }
    cout<<'\n';
    return;
}

void sub(const string& big,const string& small,const ll& bigs,const ll& smalls){
    ll subval = 0,c=0;
    int result[210]={0};
    for(ll i=0;i<bigs;i++){
        if(i<smalls)subval += ((int)big[i]-48)-((int)small[i]-48);
        else subval += (int)big[i]-48;

        if(subval>=0){result[i]=subval; subval=0;}
        else{result[i]=10+subval; subval=-1;}
    }
    for(ll i=bigs-1;i>=0;i--){
        if(result[i]>0||!i)c=1;
        if(c)cout<<result[i];
    }
    cout<<'\n';
    return;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    while(1){
        cin>>A>>B;
        if(!((int)A[0]-48) && !((int)B[0]-48))break;
        Asze = A.size(); Bsze = B.size();
        if(Asze>Bsze||(Asze==Bsze&&A>B)){swap(A,B);swap(Asze,Bsze);}
        reverse(A.begin(),A.end()); reverse(B.begin(),B.end());
        sum(B,A,Bsze,Asze); sub(B,A,Bsze,Asze);
    }
    return 0;
}
