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
#define        N                     1000010
#define        M                     1000000007
#define        pi                    acos(-1.0)
#define        ff                    first
#define        ss                    second
#define        pb                    push_back
using namespace std;
ll dp[15][15];
int main()
{

    take1(test);
    f(k,1,test+1){
       vector<int> v;
       take2(a,n);
       f(i,0,a){
           take1(x); v.pb(x);}
           f(i,0,a)
                 dp[1][v[i]]=1;
             f(i,2,n+1) f(j,1,10){
                 if(dp[i-1][j]==0) continue;
                   if(j==1)
                      dp[i][j]+=dp[i-1][j]+dp[i-1][j+1]+dp[i-1][j+2];
                    else{
                        f(c,j-2,j+3)
                           dp[i][j]+=dp[i-1][c];
                    }
                }
                ll result=0;
                f(i,1,10)
                  result+=dp[n][i];
                 printf("Case %d: %lld\n",k,result);

          mem(dp,0);
    }
   return 0;
}
