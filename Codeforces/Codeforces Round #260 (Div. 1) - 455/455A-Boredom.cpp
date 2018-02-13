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
ll dp[N];int ar[N],c[N];
int main()
{
    int n;int m=0;
    cin>>n;
    f(i,0,n){ cin>>ar[i];m=max(m,ar[i]);
      c[ar[i]]++;
    }
    int p=100005;
    dp[1]=(ll)c[1]*1LL; //cout<<dp[1]<<" ";
   f(i,2,m+1){
      dp[i]=max(dp[i-2]+(ll)c[i]*(ll)i,dp[i-1]); //cout<<dp[i]<<" ";
   }
      cout<<dp[m]<<endl;
return 0;
}