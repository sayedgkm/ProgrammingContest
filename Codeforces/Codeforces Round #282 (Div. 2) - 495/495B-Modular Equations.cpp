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
using namespace std;
ll divisor(ll a,ll b)
{
     int sq=sqrt(a); ll ans=0;
         f(i,1,sq+1){
              if(a%i==0){
                  if(i>b) ans++;
                   if((a/i)>b) ans++;
              }
         }
           if(sq*sq==a&&sq>b) ans--;
           return ans;
}
int main()
   {
     ll a,b;
     cin>>a>>b;
     if(a==b){ puts("infinity");return 0;}
     else if(b>a){ puts("0");return 0;}
     else
        cout<<divisor(a-b,b)<<endl;

}