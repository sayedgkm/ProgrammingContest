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
using namespace std;
ll ar[N];
vector<ll>p;
int main()
{
  take1(n);
  f(i,0,n) cin>>ar[i];
  ll mini=1e15,m=1e5;int index,in;
  f(i,0,n){
      mini=min(ar[i],mini);
  }
   f(i,0,n){

     if(ar[i]==mini) p.push_back(i);
   }
   ll diff=0;
   f(i,1,p.size()){
        diff=max(p[i]-1-p[i-1],diff);

   }
  // f(i,0,p.size())
     //cout<<p[i]<<endl;
   ll diff1=(n-1)-p[p.size()-1]+p[0];

   diff=max(diff1,diff);
   ll ans=n*mini+diff;
   cout<<ans<<endl;
return 0;
}