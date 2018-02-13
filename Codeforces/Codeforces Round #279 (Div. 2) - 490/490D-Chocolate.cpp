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
int main()
   {
       ll a,b,c,d,v1,v2,ans=0;
       cin>>a>>b>>c>>d;
       v1=a*b;
       v2=c*d;
       while(v1%3==0&&v2%3==0)
              v1/=3,v1*=2,v2/=3,v2*=2;

              while(v1%3==0){
                v1/=3;v1*=2;
                if(a%3==0) a/=3,a*=2;
                else
                    b/=3,b*=2;
                ans++;
              }

     while(v2%3==0){
                v2/=3;v2*=2;
                if(c%3==0) c/=3,c*=2;
                else
                    d/=3,d*=2;
                ans++;
              }

              while(v1%2==0&&v2%2==0)
              v1/=2,v2/=2;

              while(v1%2==0){
                    v1/=2;
                if(a%2==0) a/=2;
                else
                    b/=2;
                    ans++;
              }
              //cout<<"b"<<endl;
              while(v2%2==0){
                  v2/=2;
                if(c%2==0) c/=2;
                else
                    d/=2;
                    ans++;
              }
    if(v1!=v2) puts("-1");
    else{
        printf("%lld\n%lld %lld\n%lld %lld\n",ans,a,b,c,d);

    }
}