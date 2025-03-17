#include<bits/stdc++.h>
using namespace std;
using ll = long long;
ll N;
ll F_DP[100005];

ll Fibo(ll n){
    if(F_DP[n])return F_DP[n];
    if(n==1 || n== 2)return 1;
    F_DP[n] = (Fibo(n-2) + Fibo(n-1)) % (ll)(1e9 + 7);;
    //cout<<n<<" = "<<F_DP[n]<<'\n';
    return F_DP[n];
}

int main(){
    cin>>N;
    cout<<Fibo(N);
}
