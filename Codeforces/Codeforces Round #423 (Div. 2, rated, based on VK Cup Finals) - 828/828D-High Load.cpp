//==========================================================================
//
//                   Bismillahir-Rahmanir-Rahim
//
// ==========================================================================
#include <bits/stdc++.h>
#define        ll                              long long int
#define        FOR(x,y,z)                      for(int x=y;x<z;x++)
#define        pii                             pair<int,int>
#define        pll                             pair<ll,ll>
#define        CLR(a)                          memset(a,0,sizeof(a))
#define        SET(a)                          memset(a,-1,sizeof(a))
#define        N                               200010
#define        M                               1000000007
#define        pi                              acos(-1.0)
#define        ff                              first
#define        ss                              second
#define        pb                              push_back
#define        inf                             9e9+100
#define        eps                             1e-9
#define        debug(x)                        cerr << #x << " is " << x << endl;
#define        ALL(x)                          x.begin(),x.end()
using namespace std;
int dx[]={0,0,1,-1,-1,-1,1,1};
int dy[]={1,-1,0,0,-1,1,1,-1};
template < class T> inline T biton(T n,T pos){return n |((T)1<<pos);}
template < class T> inline T bitoff(T n,T pos){return n & ~((T)1<<pos);}
template < class T> inline T ison(T n,T pos){return (bool)(n & ((T)1<<pos));}
template < class T> inline T gcd(T a, T b){while(b){a%=b;swap(a,b);}return a;}
template <typename T> string NumberToString ( T Number ) { ostringstream ss; ss << Number; return ss.str(); }
inline int nxt(){int aaa;scanf("%d",&aaa);return aaa;}
inline ll lxt(){ll aaa;scanf("%lld",&aaa);return aaa;}
inline double dxt(){double aaa;scanf("%lf",&aaa);return aaa;}
template <class T> inline T bigmod(T p,T e,T m){T ret = 1;
for(; e > 0; e >>= 1){
    if(e & 1) ret = (ret * p) % m;p = (p * p) % m;
} return (T)ret;}
///******************************************START******************************************
int ar[N];
int n;
int calc(int x,int k) {
    int mx=(x-1);
     k-=2;
     if(!k) return n-1;
     int baki = n-x;
     int rem= baki % k;
      baki=baki/k;
      if(rem) {
         baki++;
      }
      mx=max((x/2)+baki,mx);
      if(k>1){
      baki*=2;
      if(rem==1) baki--;
      }
      return max(mx,baki);
}
int main(){
     //freopen("out.txt","w",stdout);
     //freopen("in.txt","r",stdin);
    //ios_base::sync_with_stdio(false);
   //cin.tie(0);
     n=nxt();
     int edge=n-1;
    int k=nxt();
    int mn=inf;
    int ans;

    FOR(i,3,n+1) {
        int x= calc(i,k);
        if(x<=mn) {
            mn=x;
            ans=i;
        }
    }
    printf("%d\n",mn);
   // debug(ans);
     n--;
     int x=2;
     int cnt=0;
    FOR(i,0,ans-1) {
       n--;
       edge--;
      printf("%d %d\n",x-1,x);
      x++;
    }
    ans=(ans+1)/2;
    k-=2;
    if(!k) return 0;
   int rem=n%k;
//   debug(rem);
//   debug(n/k);
//   debug(edge);
    while(edge) {

          int temp=n/k;
          bool f=0;
          if(rem) temp++,rem--;
          while(temp&&edge) {
             temp--;
             edge--;
             if(!f)
              printf("%d %d\n",ans,x);
              else printf("%d %d\n",x-1,x);
              x++;
              f=1;
          }


    }


return 0;
}