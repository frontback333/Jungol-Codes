//Dx[i] =
//D[i] = i 보다 작은 최댓값k 의 D[k] + 1
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
struct paper{
    int x,y;
};
paper D[105];
int P[105] = {1};
ll N,mx;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin>>N;
    for(ll i=0;i<N;i++){
        cin>>D[i].x>>D[i].y;
        if(D[i].x>D[i].y)swap(D[i].x,D[i].y);
    }
    sort(D,D+N,[](paper A, paper B){if(A.x==B.x) return A.y<B.y;else return A.x<B.x;});
    for(ll i = 0;i<N;i++){
        mx=0;
        for(ll j=0;j<i;j++){
            if(D[j].y<=D[i].y && mx < P[j])mx = P[j];
            //else if(D[j].y<=D[i].x && D[j].x<=D[i].y  && mx < P[j]){mx=P[j]+1;}
        }
        P[i]=mx+1;
    }
    mx=0;
    for(ll i=0;i<N;i++){
        if(P[i]>mx)mx=P[i];
    }
    cout<<mx;
}
