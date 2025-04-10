#include<bits/stdc++.h>
using namespace std;
using ll = long long;

struct Data{
    ll x,y,z;
};

int main(){
    cin.tie(0)->sync_with_stdio(0);
    ll N,x,y,z;
    char a;
    queue<Data>qa;
    cin>>N;
    while(N--){
        cin>>a;
        if(a=='i'){
            cin>>x>>y>>z;
            qa.push({x,y,z});
        }
        else if(a=='o'){
            if(qa.size()==0)cout<<"empty\n";
            else{
                cout<<qa.front().x<<' '<<qa.front().y<<' '<<qa.front().z<<'\n';
                qa.pop();
            }
        }
        else if(a=='c'){
            cout<<qa.size()<<'\n';
        }
        else{
            cin>>x;
            if(qa.size()==0)cout<<"no\n";
            else{
               if(x==qa.front().z)cout<<"yes\n";
                else cout<<"no\n";
            }
        }
    }
}

