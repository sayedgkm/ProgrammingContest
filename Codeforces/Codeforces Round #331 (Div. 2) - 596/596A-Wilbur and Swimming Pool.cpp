// ==========================================================================
//
//                   Bismillahir-Rahmanir-Rahim
//
// ==========================================================================

#include <bits/stdc++.h>
#define ll long long
#define f(x,y,z) for(int x=y;x<z;x++)
#define take1(a); int a;scanf("%d",&a);
#define take2(a,b); int a;int b;scanf("%d%d",&a,&b);
#define take3(a,b,c); int a;int b;int c;scanf("%d%d%d",&a,&b,&c);
#define take4(a,b,c,d); int a;int b;int c;int d;scanf("%d%d%d%d",&a,&b,&c,&d);
#define pii pair<int,int>
using namespace std;
int main()
   {
   pii ar[5];
   take1(n);
   f(i,0,n)
     cin>>ar[i].first>>ar[i].second;
   if(n==1)
   {
       puts("-1"); return 0;
   }
   f(i,0,n) f(j,0,n)
       if(ar[i].first!=ar[j].first&&ar[i].second!=ar[j].second&&i!=j)
      {
          cout<<abs(ar[i].first-ar[j].first)*abs(ar[i].second-ar[j].second);return 0;
      }
       puts("-1");
}