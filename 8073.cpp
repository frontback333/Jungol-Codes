#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    ll N,temp;
    char a;
    stack<ll>stk;
    cin>>N;
    while(N--){
        cin>>a;
        if(a=='i'){
            cin>>temp;
            stk.push(temp);
        }else if(a=='o'){
            if(stk.size()==0)cout<<"empty"<<'\n';
            else{
                cout<<stk.top()<<'\n';
                stk.pop();
            }
        }else{
            cout<<stk.size()<<'\n';
        }
    }
}

