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
int ar[N];
int br[N];
int main()
{
    int n=nxt();
    f(i,1,n+1) ar[i]=nxt();
    if(n==1){
        cout<<ar[1]<<endl;
        return 0;
    }
    sort(ar+1,ar+n+1);
      int j=1;
      for(int i=1;i<=n;i+=2)
           br[i]=ar[j++];
       for(int i=2;i<=n;i+=2)
               br[i]=ar[j++];
            int check=0;
       for(int i=2;i<n;i++){
          if(i%2){
            if(br[i]>br[i-1]) check=1;

          } else{

             if(br[i]<br[i-1])
                check=1;

          }

       }
    if(n%2)
          if(br[n]>br[n-1]) check=1;
    if(n%2==0)
          if(br[n]<br[n-1]) check=1;
          if(check) puts("Impossible");
          else {

            f(i,1,n+1) cout<<br[i]<<" ";
          }
      return 0;
}