// ==========================================================================
//
//                   Bismillahir-Rahmanir-Rahim
//
// ==========================================================================
#include <bits/stdc++.h>
#define        ll                              long long
#define        f(x,y,z)                        for(int x=y;x<z;x++)
#define        take1(a);                       scanf("%d",&a);
#define        take2(a,b);                     scanf("%d%d",&a,&b);
#define        take3(a,b,c);                   scanf("%d%d%d",&a,&b,&c);
#define        take4(a,b,c,d);                 scanf("%d%d%d%d",&a,&b,&c,&d);
#define        pii                             pair<int,int>
#define        mem(a,x)                        memset(a,x,sizeof(a))
#define        N                               1000010
#define        M                               1000000007
#define        pi                              acos(-1.0)
#define        ff                              first
#define        ss                              second
#define        pb                              push_back
using namespace std;
vector<int> v;
int dp[N],path[N];
void go(int i){
  if(i>1e6)
    return ;
  v.pb(i);
  go(i*10);
  go(i*10+1);
}
int main()
{
    go(1);
    f(i,0,1e6+3) dp[i]=100000000;
    dp[0]=0;
    int n;
    scanf("%d",&n);
     f(i,0,v.size()){
         if(v[i]>n) continue;
        f(j,v[i],n+1){
          if(dp[j-v[i]]+1<dp[j]){
             dp[j]=dp[j-v[i]]+1;
             path[j]=v[i];
          }

        }

     }
     printf("%d\n",dp[n]);
     int in=n;
     while(n){
        printf("%d ",path[in]);
        n-=path[in];
        in-=path[in];
     }
     puts(" ");
      return 0;
}