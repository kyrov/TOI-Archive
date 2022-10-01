/*
author : the follower of the omnissiah
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    long long u,v,w;
    bool operator < (const A&o) const{
        return w < o.w;
    }
};
priority_queue<A> hp;
long long p[200100];
long long find(long long i){
    if(p[i]==i) return i;
    return p[i]=find(p[i]);
}
int main(){
    long long n,m,i,j,u,v,w,ans=0;
    scanf("%lld %lld",&n,&m);
    for(i=1;i<=n;i++){
        p[i] = i;
    }
    while(m--){
        scanf("%lld %lld %lld",&u,&v,&w);
        hp.push({u,v,w});
    }
    while(!hp.empty()){
        u = hp.top().u;
        v = hp.top().v;
        w = hp.top().w;
        hp.pop();
        if(find(u)!=find(v)){
            ans += w-1;
            p[find(u)] = find(v);
        }
    }
    printf("%lld",ans);
    return 0;
}