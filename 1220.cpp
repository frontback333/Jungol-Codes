//D[i][j] = [i][j]까지의 최장 공통 부분수열
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
string A, B;
int D[1005][1005];
ll mx=0,c=0,asze,bsze;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin>>A>>B;
    asze = A.size(); bsze = B.size();
    for(ll i=1;i<=bsze;i++){
        for(ll j=1;j<=asze;j++){
            if(A[j-1]==B[i-1])D[i][j]=D[i-1][j-1]+1;
            D[i][j] = max(D[i][j-1],max(D[i-1][j],D[i][j]));
        }
    }
    cout<<D[bsze][asze];
}
