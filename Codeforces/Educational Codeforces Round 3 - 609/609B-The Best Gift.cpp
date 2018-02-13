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
using namespace std;
int ar[N],br[N],cr[N];
int main()
{
    int a,b;
   cin>>a>>b; int x=0;
   f(i,0,a)
   {
       take1(c);
       if(!cr[c]){
          ar[x++]=c;
          cr[c]=1;
       }
        br[c]++;
    }
    ll total=a,ans=0;
    f(i,0,x){
       total-=br[ar[i]];
          ans+=br[ar[i]]*total;
    }
    cout<<ans<<endl;
return 0;
}