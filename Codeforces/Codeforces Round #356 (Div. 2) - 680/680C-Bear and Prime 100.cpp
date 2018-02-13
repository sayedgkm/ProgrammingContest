// ==========================================================================
//
//                   Bismillahir-Rahmanir-Rahim
//
// ==========================================================================
#include <bits/stdc++.h>
#define        ll                              long long
#define        f(x,y,z)                        for(int x=y;x<z;x++)
#define        pii                             pair<int,int>
#define        pll                             pair<ll,ll>
#define        CLR(a)                          memset(a,0,sizeof(a))
#define        SET(a)                          memset(a,-1,sizeof(a))
#define        N                               1000010
#define        M                               1000000007
#define        pi                              acos(-1.0)
#define        ff                              first
#define        ss                              second
#define        pb                              push_back
#define        inf                             (int)1e9
using namespace std;
int dx[]={0,0,1,-1,-1,-1,1,1};
int dy[]={1,-1,0,0,-1,1,1,-1};
template < class T> inline T biton(T n,T pos){return n |((T)1<<pos);}
template < class T> inline T bitoff(T n,T pos){return n & ~((T)1<<pos);}
template < class T> inline T on(T n,T pos){return (bool)(n & ((T)1<<pos));}
template < class T> inline T gcd(T a, T b){while(b){a%=b;swap(a,b);}return a;}
template <typename T> string NumberToString ( T Number ) { ostringstream ss; ss << Number; return ss.str(); }
inline int nxt(){int aaa;scanf("%d",&aaa);return aaa;}
inline ll lxt(){ll aaa;scanf("%lld",&aaa);return aaa;}
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
int isprime(int n){
  f(i,2,n) if(n%i==0) return false;
  return true;
}
int main(){
     // freopen("out.txt","w",stdout);
     int c=0;
     int ar[]={0,2,3,5,7};
     int x;string s;
     for(int i=1;i<=4;i++){
         cout<<ar[i]<<endl;
            fflush(stdout);
         cin>>s;
         if(s=="yes"){
            c++;
          x=ar[i];
         }
     }
     if(!c){
        puts("prime");
        return 0;
     }
     if(c>=2) puts("composite");
     else {

        for(int i=2;i*x<=100;i++){
        if(isprime(i)){
            cout<<i*x<<endl;
             fflush(stdout);
             cin>>s;
             if(s=="yes"){
                puts("composite");
                return 0;
             }
         }
        }
      puts("prime");
     }

     fflush(stdout);
return 0;
}