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
struct p{

ll a,b,dif;


}ar[500000+10];
bool comp(p x,p y){
        return x.b<y.b;


}
int main()
   {
     take1(n);ll m,o;
     f(i,0,n){
          cin>>m>>o;
          ar[i].a=m;
          ar[i].b=o;
          ar[i].dif=abs(m-o);


     }
     sort(ar,ar+n,comp);
     ll x=ar[0].a;ll y=ar[0].b;ll counter=1;
     f(i,1,n){
         if(ar[i].a<x&&ar[i].b<x) {counter++;
         x=ar[i].a;y=ar[i].b;
         }
         if(ar[i].a>y&&ar[i].b>y) {counter++;
         x=ar[i].a;y=ar[i].b;
         }
     }
  cout<<counter<<endl;
}