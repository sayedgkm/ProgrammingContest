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
#define        N                               10000010
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
bool ok[10000000 + 100];
vector<int> v;
void seive(int n)
{   int sq;
 sq = sqrt(n);
 for(int i=3;i<=sq;i+=2)
  for (int j = i*i; j <= n; j += i * 2)
  ok[j] = 1;
    v.pb(2);
 for (int i = 3; i <= n; i += 2)
 if (!ok[i])
  v.pb(i);
}
ll ans[N]={0};int ar[N];
void go(){
  for(int i=0;i<v.size();i++){
     for(int j=v[i];j<N;j+=v[i])
        if(ar[j]) ans[v[i]]+=ar[j];
   }
  f(i,1,N)
    ans[i]+=ans[i-1];
}
int main(){
    seive(10000010);
    //cout<<v.size()<<endl;
 int n=nxt();
 f(i,0,n) ar[nxt()]++;
   go();
int m=nxt();
     while(m--){
            int a=nxt(),b=nxt();
        printf("%lld\n",ans[min(b,10000000)]-ans[min(a-1,10000000)]);
     }
return 0;
}