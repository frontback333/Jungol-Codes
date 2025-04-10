//D[i][j] = i번째 앱까지 고려했을때 j값을 사용해 만들 수 있는 최대 메모리
//D[i][j] = max(D[i-1][j-k]+A[k],D[i-1][j]
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
struct app{
    int mem,cost;
};
int D[105][10005];
app Data[105];
ll N,M;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin>>N>>M;
    for(ll i=0;i<N;i++)cin>>Data[i].mem;
    for(ll i=0;i<N;i++)cin>>Data[i].cost;
    for(ll i=1;i<=N;i++){
        for(ll j=0;j<10005;j++){
            if(j>=Data[i-1].cost) D[i][j]=max(D[i-1][j-Data[i-1].cost]+Data[i-1].mem,D[i-1][j]);
            else D[i][j]=D[i-1][j];
        }
    }
    /*for(ll i=1;i<=N;i++){
        for(ll j=0;j<15;j++){
            cout<<D[i][j]<<' ';
        }
        cout<<'\n';
    }*/
    for(ll i=0;i<=10005;i++){
        if(D[N][i]>=M){cout<<i;return 0;}
    }
}
