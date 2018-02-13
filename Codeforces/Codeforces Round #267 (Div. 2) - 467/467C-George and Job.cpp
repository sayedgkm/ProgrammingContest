// ==========================================================================
//
//                   Bismillahir-Rahmanir-Rahim
//
// ==========================================================================
#include <bits/stdc++.h>
#define        ll                    long long
#define        f(x,y,z)              for(int x=y;x<z;x++)
#define        take1(a);             int a;scanf("%d",&a);
#define        take2(a,b);           int a;int b;scanf("%d%d",&a,&b);
#define        take3(a,b,c);         int a;int b;int c;scanf("%d%d%d",&a,&b,&c);
#define        take4(a,b,c,d);       int a;int b;int c;int d;scanf("%d%d%d%d",&a,&b,&c,&d);
#define        pii                   pair<int,int>
#define        mem(a,x)              memset(a,x,sizeof(a))
#define        N                     100010
#define        M                     1000000007
#define        pi                    acos(-1.0)
using namespace std;
ll dp[5005][5005];ll sum[N];
int main()
{
    take3(n,m,k);
    f(i,1,n+1){
       take1(a);
       sum[i]=sum[i-1]+a;
    }
   for(int i=m;i<=n;i++){
      for(int j=1;j<=k;j++){
          dp[i][j]=max(dp[i-1][j],dp[i-m][j-1]+sum[i]-sum[i-m]);
        }

}
  cout<<dp[n][k]<<endl;
return 0;
}