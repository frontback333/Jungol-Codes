//D[i][j] = i번째 앱까지 고려했을때 j값을 사용해 만들 수 있는 최대 메모리
//D[i][j] = max(D[i-1][j-k]+A[k],D[i-1][j]
#include<bits/stdc++.h>
using namespace std;
using ll = int;
ll N;
struct Vote{
    ll sum,Num;
    ll Scores[4]={};
};
Vote Students[4];
bool HARAM(const Vote& A, const Vote& B){
    if(A.sum!=B.sum) return A.sum < B.sum;
    if(A.Scores[0]!=B.Scores[0])return A.Scores[0]<B.Scores[0];
    return A.Scores[1]<B.Scores[1];
}
int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin>>N;
    ll Fst,Sec,Thd;
    Students[1].Num=1; Students[2].Num=2; Students[3].Num=3;
    while(N--){
        cin>>Fst>>Sec>>Thd;
        Students[1].sum+=Fst; Students[1].Scores[Fst]++;
        Students[2].sum+=Sec; Students[2].Scores[Sec]++;
        Students[3].sum+=Thd; Students[3].Scores[Thd]++;
    }
    sort(Students + 1,Students + 4,HARAM);
    if(Students[3].sum == Students[2].sum && Students[3].Scores[1] == Students[2].Scores[1] && Students[3].Scores[3] == Students[2].Scores[3]){
        cout<<0<<' '<<Students[3].sum;
    }else cout<<Students[3].Num<<' '<<Students[3].sum;
    return 0;
}
