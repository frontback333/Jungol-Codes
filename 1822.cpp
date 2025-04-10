//D[i]=i번째 날에 생성된 세포 수
//D[i] = sigma k=i-b+1 -> i-a D[k]
//S[i]=누적합D[i]
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int a,b,d,N;
int D[1000055]={1},S[1000055]={1};

void PushD(const ll& day){
    ll stt = day-b; ll ed = day-a;
    if(stt<0)D[day]=S[ed-1]+D[ed];
    else{
        if(S[ed]-S[stt]<0)D[day]=S[ed]+1000 - S[stt];
        else D[day]=S[ed]-S[stt];
    }
    D[day]%=1000;
    S[day]=S[day-1]+D[day]; S[day]%=1000;
    //if(!S[day-1])S[day]=1;
    cout<<D[day]<<' ';
    return;
}

int main(){
    cin>>a>>b>>d>>N;
    D[a]=1; S[a]=2;
    for(ll i=a+1;i<=N;i++){
        PushD(i);
    }
    if(S[N]-S[N-d]<0)cout<<S[N]+1000 - S[N-d];
    else cout<<S[N]-S[N-d];
}
