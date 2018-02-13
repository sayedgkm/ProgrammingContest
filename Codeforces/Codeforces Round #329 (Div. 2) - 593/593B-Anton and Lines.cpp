#include <bits/stdc++.h>
#define ll long long
#define f(x,y,z) for(int x=y;x<z;x++)
#define take1(a); scanf("%d",&a);
#define take2(a,b); scanf("%d%d",&a,&b);
#define take3(a,b,c); scanf("%d%d%d",&a,&b,&c);
#define take4(a,b,c,d); scanf("%d%d%d%d",&a,&b,&c,&d);
using namespace std;
struct point{
    ll a,b;

}ar[100000+10];
bool comp(point m,point n) { if (m.a!=n.a)
return m.a<n.a;
else return m.b<n.b;
}

int main()
   {
    int n; ll x,y,p,q;
    take1(n);
    cin>>x>>y;
    f(i,0,n)
           {
               cin>>p>>q;
               ar[i].a=p*x+q;
               ar[i].b=p*y+q;
           }
           //f(i,0,n)
       // cout<<ar[i].a<<" "<<ar[i].b<<endl;
         //cout<<endl;
      sort(ar,ar+n,comp);

      //f(i,0,n)
        // cout<<ar[i].a<<" "<<ar[i].b<<endl;
      f(i,1,n){
          if(ar[i-1].b>ar[i].b){
            puts("YES"); return 0;}

      }
      puts("NO");
      return 0;
   }