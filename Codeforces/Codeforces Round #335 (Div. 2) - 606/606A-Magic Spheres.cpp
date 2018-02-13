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

int main()
{
  int a[6],b[6];
  f(i,0,3) cin>>a[i];
  f(i,0,3) cin>>b[i];
  ll ans=0;
  f(i,0,3){
       if(b[i]<a[i])
          ans+=(a[i]-b[i])/2;
  }
    f(i,0,3){
       if(b[i]>a[i])
         ans-=(b[i]-a[i]);
    }
    if(ans>=0)
         puts("Yes");
    else
        puts("No");

return 0;
}