/*
    author : Kyrov
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int i,j;
};
queue<A> q;
char a[2100][2100];
int di[8]={1,-1,0,0,1,1,-1,-1},dj[8]={0,0,1,-1,1,-1,1,-1};
int main(){
    int n,m,i,j,ans=0,ii,jj;
    scanf("%d %d",&n,&m);
    for(i=0;i<n;i++){
        scanf("%s",a[i]);
    }
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            if(a[i][j]=='1'){
                ans += 1;
                a[i][j]='0';
                q.push({i,j});
                while(!q.empty()){
                    A t=q.front();
                    q.pop();
                    for(int k=0;k<8;k++){
                        ii=t.i+di[k];
                        jj=t.j+dj[k];
                        if(ii>=0&&ii<n&&jj>=0&&jj<m&&a[ii][jj]=='1'){
                            a[ii][jj]='0';
                            q.push({ii,jj});
                        }
                    }
                }
            }
        }
    }
    printf("%d\n",ans);
    return 0;
}