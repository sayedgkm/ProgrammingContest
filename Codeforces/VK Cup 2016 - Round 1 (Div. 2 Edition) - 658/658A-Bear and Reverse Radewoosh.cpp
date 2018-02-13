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
int dx[]={0,0,1,-1,-1,-1,1,1};
int dy[]={1,-1,0,0,-1,1,1,-1};
template < class T> inline T gcd(T a, T b){while(b){a%=b;swap(a,b);}return a;}
template <class T> inline T bigmod(T p,T e,T m){
    ll ret = 1;
    for(; e > 0; e >>= 1){
        if(e & 1) ret = (ret * p) % m;
        p = (p * p) % m;
    } return (T)ret;
}
inline int nxt(){
  int aaa;
  scanf("%d",&aaa);
  return aaa;
}
ll ar[N],br[N];
int main()
{
   ll n,c;  ll a=0,b=0;
   cin>>n>>c;
   f(i,0,n){
     scanf("%I64d",&ar[i]);
   }
   f(i,0,n){
     scanf("%I64d",&br[i]);
   }
   ll p=0;
   f(i,0,n){
       p+=br[i];
     a+=max(ar[i]-c*p,0LL);
   }
   p=0;
   for(int i=n-1;i>=0;i--){
        p+=br[i];
     b+=max(ar[i]-c*p,0LL);
   }
   //cout<<a<<" "<<b<<endl;
   if(a>b)
       puts("Limak");
   else if(b>a) puts("Radewoosh");
   else puts("Tie");
      return 0;
}