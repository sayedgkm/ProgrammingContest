//==========================================================================
//
//                   Bismillahir-Rahmanir-Rahim
//
// ==========================================================================
#include <bits/stdc++.h>
#define        ll                              long long int
#define        f(x,y,z)                        for(int x=y;x<z;x++)
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
#define        inf                             (int)1e9
#define        eps                              1e-9
using namespace std;
int dx[]={0,0,1,-1,-1,-1,1,1};
int dy[]={1,-1,0,0,-1,1,1,-1};
template < class T> inline T biton(T n,T pos){return n |((T)1<<pos);}
template < class T> inline T bitoff(T n,T pos){return n & ~((T)1<<pos);}
template < class T> inline T ison(T n,T pos){return (bool)(n & ((T)1<<pos));}
template < class T> inline T gcd(T a, T b){while(b){a%=b;swap(a,b);}return a;}
template <typename T> string NumberToString ( T Number ) { ostringstream ss; ss << Number; return ss.str(); }
inline int nxt(){int aaa;scanf("%d",&aaa);return aaa;}
inline ll lxt(){ll aaa;scanf("%I64d",&aaa);return aaa;}
inline double dxt(){double aaa;scanf("%lf",&aaa);return aaa;}
template <class T> inline T bigmod(T p,T e,T m){T ret = 1;
for(; e > 0; e >>= 1){
    if(e & 1) ret = (ret * p) % m;p = (p * p) % m;
} return (T)ret;}
#define sayed
#ifdef sayed
     #define debug(args...) {cerr<<"Debug: "; dbg,args; cerr<<endl;}
#else
    #define debug(args...)  // Just strip off all debug tokens
#endif
struct debugger{
    template<typename T> debugger& operator , (const T& v){
        cerr<<v<<" ";
        return *this;
    }
}dbg;
///******************************************START******************************************
vector<int> v;
int main(){
     //freopen("out.txt","w",stdout);
     int n=nxt(),k=nxt(),a=nxt(),b=nxt();
     int mx=max(a,b);
     int mn=min(a,b);
     if((ll)mx>(ll)(mn+1)*k){
        puts("NO");
        return 0;
     }
      while(1){

         for(int i=0;i<k;i++){
              v.pb(1); mx--;
              if(mx<=mn) break;
          }
         if(mx<=mn) break;
         v.pb(0);
         mn--;
      }
      while(1){


          if(mn){
            v.pb(0);
            mn--;
          }
           if(mx) {
            v.pb(1);
            mx--;

          }
        if(!mn&&!mx) break;
      }
      if(a>b){
        for(int i=0;i<v.size();i++) if(v[i]==1) putchar('G');
                                    else putchar('B');
        } else  {
           for(int i=0;i<v.size();i++) if(v[i]==0) putchar('G');
                                    else putchar('B');
        }

return 0;
}