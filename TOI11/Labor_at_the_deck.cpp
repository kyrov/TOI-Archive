/*
    author : kyrov
*/
#include<bits/stdc++.h>
using namespace std;
long long a[1000100];
int main(){
    long long n,m,i,j,l,r,mid,sum;
    scanf("%lld %lld",&n,&m);
    for(i=1;i<=n;i++){
        scanf("%lld",&a[i]);
    }
    l=1,r=1e18;
    while(l<r){
        mid = (l+r)/2;
        for(i=1,sum=0;i<=n;i++){
            sum += mid/a[i];
        }
        if(sum >= m) r = mid;
        else l = mid + 1;
    }
    printf("%lld",l);
    return 0;
}