// ==========================================================================
//
//                   Bismillahir-Rahmanir-Rahim
//
// ==========================================================================

#include <bits/stdc++.h>
#define ll long long
#define f(x,y,z) for(int x=y;x<z;x++)
#define take1(a); scanf("%d",&a);
#define take2(a,b); scanf("%d%d",&a,&b);
#define take3(a,b,c); scanf("%d%d%d",&a,&b,&c);
#define take4(a,b,c,d); scanf("%d%d%d%d",&a,&b,&c,&d);
using namespace std;
int main()
   {
      int a,b,c,d,counter=0;
      take2(a,b);
      while(a--)
      {
           f(i,0,b)
           {
               take2(c,d);
               if(c==1||d==1) counter++;

            }



      }
  cout<<counter<<endl;

 }