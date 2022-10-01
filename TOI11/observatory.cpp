/*
    author : kyrov
*/
#include<bits/stdc++.h>
using namespace std;
int dp[2010][2010][4],a[2010][2010];
int main(){
    int n,m,k,i,j,ans=-1e9;
    scanf("%d %d %d",&n,&m,&k);
    for(i=1;i<=n;i++){
        for(j=1;j<=m;j++){
            scanf("%d",&a[i][j]);
            dp[i][j][0] = a[i][j] + dp[i-1][j][0] + dp[i][j-1][0] - dp[i-1][j-1][0];
        }
    }
    for(i=1;i<=n;i++){
        for(j=1;j<=m;j++){
            dp[i][j][1] = a[i][j] + dp[i][j-1][1] + dp[i-1][j-1][1] - dp[i-1][max(j-2,0)][1];
        }
    }
    for(i=k;i<=n;i++){
        for(j=k;j<=m;j++){
            ans = max(ans,dp[i][j][1] - dp[i-k][j-k][1] - dp[i][j-k][0] + dp[i-k][j-k][0]);
        }
    }
    for(i=1;i<=n;i++){
        for(j=m;j>=1;j--){
            dp[i][j][2] = a[i][j] + dp[i][j+1][2] + dp[i-1][j][2] - dp[i-1][j+1][2];
        }
    }
    for(i=1;i<=n;i++){
        for(j=m;j>=1;j--){
            dp[i][j][3] = a[i][j] + dp[i][j+1][3] + dp[i-1][j+1][3] - dp[i-1][j+2][3];
        }
    }
    for(i=k;i<=n;i++){
        for(j=m-k+1;j>=1;j--){
            ans = max(ans,dp[i][j][3] - dp[i-k][j+k][3] - dp[i][j+k][2] + dp[i-k][j+k][2]);
        }
    }
    printf("%d\n",ans);
    return 0;
}