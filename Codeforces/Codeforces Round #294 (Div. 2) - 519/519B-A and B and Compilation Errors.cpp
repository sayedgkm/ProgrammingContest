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
using namespace std;
map<int,int>a,b,c;int ar[100000+10],br[100000+10],cr[100000+10];
int main()
{
   take1(n);
   f(i,0,n)
   {
       cin>>ar[i];

   }
   f(i,0,n-1) {cin>>br[i];
   }
   f(i,0,n-2)
      {
cin>>cr[i];
      }
     sort(ar,ar+n);
     sort(br,br+n-1);
     sort(cr,cr+n-2);
      f(i,0,n)
      {
         if(ar[i]!=br[i])
         {
             cout<<ar[i]<<endl;break;
         }
     }
f(i,0,n-1)
      {
         if(br[i]!=cr[i])
         {
             cout<<br[i]<<endl;break;
         }
     }




}