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
int ar[1000],br[1000];
ll pow1(int a,int b)
{
    ll sum=1;
    f(i,0,b)
       sum*=a;

        return sum;


}
int main()
   {
       ll x=0,y=0,a,b,c,d;
         cin>>a>>b;
         f(i,0,a)
          cin>>ar[i];
          int p=0;
          for(int i=a-1;i>=0;i--)
              x+=ar[i]*pow1(b,p++);
      cin>>c>>d;
         f(i,0,c)
          cin>>br[i];
          p=0;
          for(int i=c-1;i>=0;i--){
              y+=br[i]*pow1(d,p++);
              //cout<<y<<endl;
          }
              if(x==y)
                puts("=");
              if(x<y) puts("<");
              if(x>y) puts(">");
}