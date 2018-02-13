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
ll bigmod(ll b,ll p){
   if(p==0) return 1;
   if(p%2==0){
    ll ret=bigmod(b,p/2);
     return (ret%M*ret%M)%M;
   }
   else
     return (b%M*bigmod(b,p-1)%M)%M;
}
int main()
{
   take1(n);
   cout<<((bigmod(3,3*n)-bigmod(7,n))+M)%M<<endl;

}