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
int main()
{

    ll x1,y1,x2,y2;
    cin>>x1>>y1>>x2>>y2;
      int n;
      cin>>n;  ll ans=0;
      while(n--){
          ll a,b,c;
          cin>>a>>b>>c;
            ll p=a*x1+b*y1+c;
            ll q=a*x2+y2*b+c;
            if((p<0&&q>0)||(p>0&&q<0))
                 ans++;
      }
      cout<<ans<<endl;
      return 0;
}