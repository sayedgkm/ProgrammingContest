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
#define        N                               100010
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
inline ll lxt(){ll aaa;scanf("%lld",&aaa);return aaa;}
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
set<ll> h,v;
multiset<ll> mh,mv;
int main(){
     //freopen("out.txt","w",stdout);
    //ios_base::sync_with_stdio(false);
   //cin.tie(0);
   int x,y,n;
   x=nxt(),y=nxt(),n=nxt();
   v.insert(0);
   v.insert(x);
   mv.insert(x);
   h.insert(0);
   h.insert(y);
   mh.insert(y);
   char c[4];
   while(n--){
     scanf("%s",c);
     int x=nxt();
     if(c[0]=='V'){
       auto it = v.lower_bound(x);
       int a,b;
        b=*it;
        it--;
        a=*it;
        v.insert(x);
        it=mv.find(b-a);
        mv.erase(it);
        mv.insert(x-a);
        mv.insert(b-x);
     } else  {
        auto it = h.lower_bound(x);
       int a,b;
        b=*it;
        it--;
        a=*it;
        //cout<<b<<" "<<a<<endl;
        h.insert(x);
        it=mh.find(b-a);
        mh.erase(it);
        mh.insert(x-a);
        mh.insert(b-x);


     }
     cout<<(*--mh.end())*(*--mv.end())<<endl;

   }

return 0;
}