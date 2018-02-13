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
template < class T> inline T gcd(T a, T b){return a%b ? gcd(b,a%b) : b;}
using namespace std;
int ar[N],br[N];vector<pii> v;int cr[N];
bool comp(int a,int b){
  return a>b;
}
int main()
{
    int n,q;
    take2(n,q);
    f(i,0,n){ scanf("%d",ar+i);
      br[i]=ar[i];
    }
    f(i,0,q){
      int a,b
      take2(a,b);
      while(!v.empty()&&b>=v.back().ss)
           v.pop_back();
        v.pb(pii(a,b));
    }
    v.pb(pii(0,0));
    int check;
     sort(ar,ar+v[0].ss);
     deque<int> dq;
     int in=v[0].ss-1;
     for(int i=0;i<v[0].ss;i++)
           dq.pb(ar[i]);
   for(int i=0;i<v.size()-1;i++) {
      if(v[i].ff==1){
         for(int j=v[i].ss;j>v[i+1].ss;j--){
            br[in--]=dq.back(); dq.pop_back();
         }
      }else {
          for(int j=v[i].ss;j>v[i+1].ss;j--){
            br[in--]=dq.front();dq.pop_front();
         }
      }
    }
    f(i,0,n) printf("%d ",br[i]);
      return 0;
}