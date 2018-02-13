// ==========================================================================
//
//                   Bismillahir-Rahmanir-Rahim
//
// ==========================================================================
#include <bits/stdc++.h>
#define        ll                              long long
#define        f(x,y,z)                        for(int x=y;x<z;x++)
#define        take1(a);                       scanf("%d",&a);
#define        take2(a,b);                     scanf("%d%d",&a,&b);
#define        take3(a,b,c);                   scanf("%d%d%d",&a,&b,&c);
#define        take4(a,b,c,d);                 scanf("%d%d%d%d",&a,&b,&c,&d);
#define        pii                             pair<int,int>
#define        mem(a,x)                        memset(a,x,sizeof(a))
#define        N                               1000010
#define        M                               1000000007
#define        pi                              acos(-1.0)
#define        ff                              first
#define        ss                              second
#define        pb                              push_back
using namespace std;
pii ar[N];
double go(double x1,double y1,double x2,double y2){

    return ((x1-x2)/(y1-y2));

}
int main()
{
    int n,x,y;
    cin>>n>>x>>y;
    f(i,0,n){
    cin>>ar[i].ff>>ar[i].ss;
    }
    int ans=0;int check=0;
    f(i,0,n){
      if(ar[i].ff==x){
          ar[i].ff=1e5;
          check=1;
      }
    }
    if(check) ans++;
    check=0;
    f(i,0,n){
      if(ar[i].ss==y){
          ar[i].ff=1e5;
          check=1;

      }
    }
    if(check) ans++;
    double ra;
    f(i,0,n){
        if(ar[i].ff==1e5) continue; check=0;
        ra=go(x,y,ar[i].ff,ar[i].ss);
        f(j,0,n){
          if(ar[j].ff==1e5) continue;
          if(go(x,y,ar[j].ff,ar[j].ss)==ra){
            check=1;
            ar[j].ff=1e5;
          }


       }
    if(check) ans++;
    }
    cout<<ans<<endl;
      return 0;
}