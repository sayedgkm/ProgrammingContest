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
       ll a,b,c,sum[10];
       cin>>a>>b>>c;
       sum[0]=a+a+b+b;
       sum[1]=a+c+b;
       sum[2]=a+c+c+a;
       sum[3]=b+c+c+b;
       sort(sum,sum+4);
       cout<<sum[0]<<endl;


}