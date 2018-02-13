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
using namespace std;
int dx[]={0,0,1,-1,-1,-1,1,1};
int dy[]={1,-1,0,0,-1,1,1,-1};
template < class T> inline T biton(T n,T pos){return n |((T)1<<pos);}
template < class T> inline T bitoff(T n,T pos){return n & ~((T)1<<pos);}
template < class T> inline T on(T n,T pos){return (bool)(n & ((T)1<<pos));}
template < class T> inline T gcd(T a, T b){while(b){a%=b;swap(a,b);}return a;}
template <typename T> string NumberToString ( T Number ) { ostringstream ss; ss << Number; return ss.str(); }
inline int nxt(){int aaa;scanf("%d",&aaa);return aaa;}
inline ll lxt(){ll aaa;scanf("%I64d",&aaa);return aaa;}
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
vector<int> go(int n ){
    vector<int>v;
  int sq=sqrt(n);
  for(int i=1;i<=sq;i++){
    if(n%i==0){
        v.pb(i);
        v.pb(n/i);
    }
  } if(sq*sq==n) v.pop_back();
   sort(v.begin(),v.end());
   return v;
}

int main(){
     //freopen("out.txt","w",stdout);
    //ios_base::sync_with_stdio(false);
   //cin.tie(0);
   int n=nxt(),m=nxt();
   vector<int>v1,v2,v;
   v1=go(n);
   v2=go(m);
   for(int i=0;i<v1.size();i++){
       int p=v1[i];
       int in=lower_bound(v2.begin(),v2.end(),p)-v2.begin();
       if(v2[in]==p) v.pb(p);
   }
   n=nxt();
   while(n--){
    int a=nxt();
    int b=nxt();
    if(b<a) swap(a,b);
    int low=upper_bound(v.begin(),v.end(),a)-v.begin();
    int hi=upper_bound(v.begin(),v.end(),b)-v.begin();
    low--;
    hi--;
    if(v[hi]>b||v[hi]<a) puts("-1");
    else printf("%d\n",v[hi]);


   }
return 0;
}