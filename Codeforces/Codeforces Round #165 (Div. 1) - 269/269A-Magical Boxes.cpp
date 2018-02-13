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
#define        N                               100010
#define        M                               1000000007
#define        pi                              acos(-1.0)
#define        ff                              first
#define        ss                              second
#define        pb                              push_back
using namespace std;
pii ar[N];ll dp[N];
ll go(ll b){
       if(b==1) return 1;
      ll x=1;ll ans=0;
     while(x<b){
         x*=4;
         ans++;
      }
   return ans;
}
int main()
{
    int n;take1(n);
    f(i,0,n) cin>>ar[i].ff>>ar[i].ss;
      sort(ar,ar+n);
      f(i,0,n){
         // cout<<go(1)<<endl;
          dp[i+1]=max(dp[i],dp[i+1]+go(ar[i].ss)+ar[i].ff);
      }
      cout<<dp[n]<<endl;
      return 0;
}