#include<bits/stdc++.h>
using namespace std;
using ll = long long;
ll w,h,p,q,t,x=1,y=1;
int main(){
    //cin.tie(0)->sync_with_stdio(0);
    cin>>w>>h>>p>>q>>t;
    p+=t;q+=t;
    if(!((p/w)%2))cout<<p%w;
    else cout<<w-(p%w);
    cout<<' ';
    if(!((q/h)%2))cout<<q%h;
    else cout<<h-(q%h);
}
