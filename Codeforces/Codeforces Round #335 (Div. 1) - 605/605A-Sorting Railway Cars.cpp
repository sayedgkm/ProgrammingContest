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
int ar[100000+10],br[100000+10];
int main()
{
  take1(n);
  f(i,1,n+1) cin>>ar[i];
     int c=1;
  int counter=1,maxi=1;
   f(i,1,n+1)
      {

        br[ar[i]]=i;
    }
       f(i,1,n)
         {
             if(br[i+1]>br[i])
                  counter++;
             else
                 counter=1;
             maxi=max(counter,maxi);

         }
         cout<<n-maxi<<endl;
return 0;
}