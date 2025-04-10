    #include<bits/stdc++.h>
    using namespace std;
    using ll = long long;
    ll N,M,head=0,tail=0;
    vector<ll>que(1000005);

    void q_Push(ll value){
        que[tail] = value;
        tail++;
    }
    void q_Pop(){head++;}

    int main(){
        //cin.tie(0)->sync_with_stdio(0);
        ll temp;
        cin>>N>>M;
        vector<ll>arr(N,0);
        for(ll i = 0;i<M;i++){
            cin>>temp;
            q_Push(temp-1);
            arr[temp-1]=1;
        }
        while(head<tail){
            if(que[head]-1>=0 && arr[que[head]-1]==0){arr[que[head]-1]=arr[que[head]]+1; q_Push(que[head]-1);}
            if(que[head]+1<N && arr[que[head]+1]==0){arr[que[head]+1]=arr[que[head]]+1; q_Push(que[head]+1);}
            q_Pop();
        }
        for(ll i : arr){
            cout<<i-1<<' ';
        }
    }
